
// #include "gf.h" // For generic functions
#include "julia.h"
#include "julia_internal.h"
#include "lookup_generic.h"

#define N_CALL_CACHE 4096
_Atomic(jl_typemap_entry_t*) call_cache[N_CALL_CACHE];
static _Atomic(uint8_t) pick_which[N_CALL_CACHE];

static inline int sig_match_leaf(jl_value_t *arg1, jl_value_t **args, jl_value_t **sig, size_t n)
{
    // NOTE: This function is a huge performance hot spot!!
    size_t i;
    if (jl_typeof(arg1) != sig[0])
        return 0;
    for (i = 1; i < n; i++) {
        jl_value_t *decl = sig[i];
        jl_value_t *a = args[i - 1];
        if (jl_typeof(a) != decl) {
            /*
              we are only matching concrete types here, and those types are
              hash-consed, so pointer comparison should work.
            */
            return 0;
        }
    }
    return 1;
}

static inline int sig_match_simple(jl_value_t *arg1, jl_value_t **args, size_t n, jl_value_t **sig,
                                   int va, size_t lensig)
{
    // NOTE: This function is a performance hot spot!!
    size_t i;
    if (va)
        lensig -= 1;
    for (i = 0; i < lensig; i++) {
        jl_value_t *decl = sig[i];
        jl_value_t *a = (i == 0 ? arg1 : args[i - 1]);
        if (jl_typeof(a) == decl || decl == (jl_value_t*)jl_any_type) {
            /*
              we are only matching concrete types here, and those types are
              hash-consed, so pointer comparison should work.
            */
            continue;
        }
        jl_value_t *unw = jl_is_unionall(decl) ? ((jl_unionall_t*)decl)->body : decl;
        if (jl_is_type_type(unw) && jl_is_type(a)) {
            jl_value_t *tp0 = jl_tparam0(unw);
            if (jl_is_typevar(tp0)) {
                // in the case of Type{_}, the types don't have to match exactly.
                // this is cached as `Type{T} where T`.
                if (((jl_tvar_t*)tp0)->ub != (jl_value_t*)jl_any_type &&
                    !jl_subtype(a, ((jl_tvar_t*)tp0)->ub))
                    return 0;
            }
            else {
                if (a != tp0) {
                    jl_datatype_t *da = (jl_datatype_t*)a;
                    jl_datatype_t *dt = (jl_datatype_t*)tp0;
                    while (jl_is_unionall(da))
                        da = (jl_datatype_t*)((jl_unionall_t*)da)->body;
                    while (jl_is_unionall(dt))
                        dt = (jl_datatype_t*)((jl_unionall_t*)dt)->body;
                    if (jl_is_datatype(da) && jl_is_datatype(dt) && da->name != dt->name)
                        return 0;
                    if (!jl_types_equal(a, tp0))
                        return 0;
                }
            }
        }
        else {
            return 0;
        }
    }
    if (va) {
        jl_value_t *decl = sig[i];
        if (jl_vararg_kind(decl) == JL_VARARG_INT) {
            if (n - i != jl_unbox_long(jl_tparam1(decl)))
                return 0;
        }
        jl_value_t *t = jl_unwrap_vararg(decl);
        for (; i < n; i++) {
            jl_value_t *a = (i == 0 ? arg1 : args[i - 1]);
            if (!jl_isa(a, t))
                return 0;
        }
        return 1;
    }
    return 1;
}

int jl_tuple1_isa(jl_value_t *child1, jl_value_t **child, size_t cl, jl_datatype_t *pdt)
{
    // TODO: Implement it?
    return 0;
    // if (jl_is_tuple_type(pdt) && !jl_is_va_tuple(pdt)) {
    //     if (cl != jl_nparams(pdt))
    //         return 0;
    //     size_t i;
    //     if (!jl_isa(child1, jl_tparam(pdt, 0)))
    //         return 0;
    //     for (i = 1; i < cl; i++) {
    //         if (!jl_isa(child[i - 1], jl_tparam(pdt, i)))
    //             return 0;
    //     }
    //     return 1;
    // }
    // jl_value_t *tu = (jl_value_t*)arg_type_tuple(child1, child, cl);
    // int ans;
    // JL_GC_PUSH1(&tu);
    // ans = jl_subtype(tu, (jl_value_t*)pdt);
    // JL_GC_POP();
    // return ans;
}

jl_typemap_entry_t *jl_typemap_entry_assoc_exact(jl_typemap_entry_t *ml, jl_value_t *arg1, jl_value_t **args, size_t n, size_t world)
{
    // some manually-unrolled common special cases
    while (ml->simplesig == (void*)jl_nothing && ml->guardsigs == jl_emptysvec && ml->isleafsig) {
        // use a tight loop for as long as possible
        if (world >= ml->min_world && world <= ml->max_world) {
            if (n == jl_nparams(ml->sig) && jl_typeof(arg1) == jl_tparam(ml->sig, 0)) {
                if (n == 1)
                    return ml;
                if (n == 2) {
                    if (jl_typeof(args[0]) == jl_tparam(ml->sig, 1))
                        return ml;
                }
                else if (n == 3) {
                    if (jl_typeof(args[0]) == jl_tparam(ml->sig, 1) &&
                        jl_typeof(args[1]) == jl_tparam(ml->sig, 2))
                        return ml;
                }
                else {
                    if (sig_match_leaf(arg1, args, jl_svec_data(ml->sig->parameters), n))
                        return ml;
                }
            }
        }
        ml = jl_atomic_load_relaxed(&ml->next);
        if (ml == (void*)jl_nothing)
            return NULL;
    }

    for (; ml != (void*)jl_nothing; ml = jl_atomic_load_relaxed(&ml->next)) {
        if (world < ml->min_world || world > ml->max_world)
            continue; // ignore replaced methods
        size_t lensig = jl_nparams(ml->sig);
        if (lensig == n || (ml->va && lensig <= n+1)) {
            if (ml->simplesig != (void*)jl_nothing) {
                size_t lensimplesig = jl_nparams(ml->simplesig);
                int isva = lensimplesig > 0 && jl_is_vararg(jl_tparam(ml->simplesig, lensimplesig - 1));
                if (lensig == n || (isva && lensimplesig <= n + 1)) {
                    if (!sig_match_simple(arg1, args, n, jl_svec_data(ml->simplesig->parameters), isva, lensimplesig))
                        continue;
                }
                else {
                    continue;
                }
            }

            if (ml->isleafsig) {
                if (!sig_match_leaf(arg1, args, jl_svec_data(ml->sig->parameters), n))
                    continue;
            }
            else if (ml->issimplesig) {
                if (!sig_match_simple(arg1, args, n, jl_svec_data(ml->sig->parameters), ml->va, lensig))
                    continue;
            }
            else {
                if (!jl_tuple1_isa(arg1, args, n, ml->sig))
                    continue;
            }

            size_t i, l;
            if (ml->guardsigs != jl_emptysvec) {
                for (i = 0, l = jl_svec_len(ml->guardsigs); i < l; i++) {
                    // checking guard entries require a more
                    // expensive subtype check, since guard entries added for @nospecialize might be
                    // abstract. this fixed issue #12967.
                    if (jl_tuple1_isa(arg1, args, n, (jl_tupletype_t*)jl_svecref(ml->guardsigs, i))) {
                        goto nomatch;
                    }
                }
            }
            return ml;
nomatch:
            continue;
        }
    }
    return NULL;
}

jl_typemap_entry_t *jl_typemap_level_assoc_exact(jl_typemap_level_t *cache, jl_value_t *arg1, jl_value_t **args, size_t n, int8_t offs, size_t world)
{
    return NULL;
}

jl_tupletype_t *arg_type_tuple(jl_value_t *arg1, jl_value_t **args, size_t nargs)
{
    return jl_inst_arg_tuple_type(arg1, args, nargs, 1);
}

static int8_t jl_cachearg_offset(jl_methtable_t *mt)
{
    return mt->offs;
}

jl_tupletype_t *jl_inst_arg_tuple_type(jl_value_t *arg1, jl_value_t **args, size_t nargs, int leaf)
{
    return NULL;
}

static inline jl_typemap_entry_t *lookup_leafcache(jl_array_t *leafcache JL_PROPAGATES_ROOT, jl_value_t *tt, size_t world) JL_NOTSAFEPOINT
{
    // TODO: Implement it?
    // jl_typemap_entry_t *entry = (jl_typemap_entry_t*)jl_eqtable_get(leafcache, (jl_value_t*)tt, NULL);
    // if (entry) {
    //     do {
    //         if (entry->min_world <= world && world <= entry->max_world) {
    //             if (entry->simplesig == (void*)jl_nothing || concretesig_equal(tt, (jl_value_t*)entry->simplesig))
    //                 return entry;
    //         }
    //         entry = jl_atomic_load_relaxed(&entry->next);
    //     } while ((jl_value_t*)entry != jl_nothing);
    // }
    return NULL;
}


static jl_tupletype_t *lookup_arg_type_tuple(jl_value_t *arg1 JL_PROPAGATES_ROOT, jl_value_t **args, size_t nargs)
{
    return NULL;// jl_lookup_arg_tuple_type(arg1, args, nargs, 1);
}


int sig_match_fast(jl_value_t *arg1t, jl_value_t **args, jl_value_t **sig, size_t n)
{
    // NOTE: This function is a huge performance hot spot!!
    if (arg1t != sig[0])
        return 0;
    size_t i;
    for (i = 1; i < n; i++) {
        jl_value_t *decl = sig[i];
        jl_value_t *a = args[i - 1];
        if (jl_typeof(a) != decl) {
            /*
              we are only matching concrete types here, and those types are
              hash-consed, so pointer comparison should work.
            */
            return 0;
        }
    }
    return 1;
}


jl_methtable_t* mt_mock_data;
jl_array_t* jl_an_empty_vec_any_mock_data;
jl_datatype_t* jl_typemap_level_type_mock_data;

struct _jl_value_t {};

// Main function for search generic method
JL_DLLEXPORT jl_method_t *jl_lookup_generic_(jl_value_t *F, jl_value_t **args, uint32_t nargs,
                                                uint32_t callsite, size_t world) {
    jl_method_t *m = NULL;

    jl_value_t *FT = jl_to_typeof(((((jl_taggedvalue_t*)((char*)(F) - sizeof(jl_taggedvalue_t)))->header) & ~(uintptr_t)15));

    uint32_t cache_idx[4] = {
        (callsite) & (N_CALL_CACHE - 1),
        (callsite >> 8) & (N_CALL_CACHE - 1),
        (callsite >> 16) & (N_CALL_CACHE - 1),
        (callsite >> 24 | callsite << 8) & (N_CALL_CACHE - 1)};

    // Search in Last Caller cache
    jl_typemap_entry_t *entry = NULL;

    int i;

    #define LOOP_BODY(_i) do { \
        i = _i; \
        entry = jl_atomic_load_relaxed(&call_cache[cache_idx[i]]); \
        if (entry && nargs == jl_svec_len(entry->sig->parameters) && \
            sig_match_fast(FT, args, jl_svec_data(entry->sig->parameters), nargs) && \
            world >= entry->min_world && world <= entry->max_world) { \
            goto have_entry; \
        } \
    } while (0);
    LOOP_BODY(0);
    LOOP_BODY(1);
    LOOP_BODY(2);
    LOOP_BODY(3);
    #undef LOOP_BODY

    // Search in main cache
    i = 4;
    jl_tupletype_t *tt = NULL;
    int64_t last_alloc = 0;
    jl_methtable_t *mt = NULL;
    if (i == 4) {
        // if no method was found in the associative cache, check the full cache
        // mt = jl_gf_mtable(F); <- This is mocked with mt_mock_data

        mt = mt_mock_data;
        jl_an_empty_vec_any = (jl_value_t *)jl_an_empty_vec_any_mock_data;
        jl_typemap_level_type = jl_typemap_level_type_mock_data;

        jl_array_t *leafcache = jl_atomic_load_relaxed(&mt->leafcache);
        entry = NULL;
        if (leafcache != (jl_array_t*)jl_an_empty_vec_any &&
                jl_typetagis(jl_atomic_load_relaxed(&mt->cache), jl_typemap_level_type)) {
            // hashing args is expensive, but looking at mt->cache is probably even more expensive
            tt = lookup_arg_type_tuple(F, args, nargs);
            if (tt != NULL)
                entry = lookup_leafcache(leafcache, (jl_value_t*)tt, world);
        }
        if (entry == NULL) {
            jl_typemap_t *cache = jl_atomic_load_relaxed(&mt->cache); // XXX: gc root required?
            entry = jl_typemap_assoc_exact(cache, F, args, nargs, jl_cachearg_offset(mt), world);
            if (entry == NULL) {
                last_alloc = jl_options.malloc_log ? jl_gc_diff_total_bytes() : 0;
                if (tt == NULL) {
                    tt = arg_type_tuple(F, args, nargs); // TODO: Add bodies to these two funcs
                    entry = lookup_leafcache(leafcache, (jl_value_t*)tt, world);
                }
            }
        }
        if (entry != NULL && entry->isleafsig && entry->simplesig == (void*)jl_nothing && entry->guardsigs == jl_emptysvec) {
            // put the entry into the cache if it's valid for a leafsig lookup,
            // using pick_which to slightly randomize where it ends up
            // (intentionally not atomically synchronized, since we're just using it for randomness)
            // TODO: use the thread's `cong` instead as a source of randomness
            int which = jl_atomic_load_relaxed(&pick_which[cache_idx[0]]) + 1;
            jl_atomic_store_relaxed(&pick_which[cache_idx[0]], which);
            jl_atomic_store_release(&call_cache[cache_idx[which & 3]], entry);
        }
    }

have_entry:

    // Doing full search
    return m;
}