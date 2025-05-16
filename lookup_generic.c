
// #include "gf.h" // For generic functions
#include "julia.h"
#include "julia_internal.h"
#include "lookup_generic.h"

jl_methtable_t* mt_mock_data;
jl_array_t* jl_an_empty_vec_any_mock_data;
jl_datatype_t* jl_typemap_level_type_mock_data;

struct _jl_value_t {};

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
    // return 0;
    if (
        0
        // jl_is_tuple_type(pdt) && !jl_is_va_tuple(pdt)
        ) {
        if (cl != jl_nparams(pdt))
            return 0;
        size_t i;
        if (!jl_isa(child1, jl_tparam(pdt, 0)))
            return 0;
        for (i = 1; i < cl; i++) {
            if (!jl_isa(child[i - 1], jl_tparam(pdt, i)))
                return 0;
        }
        return 1;
    }
    jl_value_t *tu = (jl_value_t*)arg_type_tuple(child1, child, cl);
    int ans;
    // JL_GC_PUSH1(&tu);
    ans = 0;// jl_subtype(tu, (jl_value_t*)pdt);
    // JL_GC_POP();
    return ans;
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
                    exit(EXIT_FAILURE);
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


static unsigned type_hash(jl_value_t *kj, int *failed);


static unsigned typekey_hash(jl_typename_t *tn, jl_value_t **key, size_t n, int nofail) JL_NOTSAFEPOINT
{
    if (tn == jl_type_typename && key[0] == jl_bottom_type)
        return jl_typeofbottom_type->hash;
    size_t j;
    unsigned hash = 3;
    int failed = nofail;
    for (j = 0; j < n; j++) {
        jl_value_t *p = key[j];
        size_t repeats = 1;
        if (jl_is_vararg(p)) {
            jl_vararg_t *vm = (jl_vararg_t*)p;
            if (vm->N && jl_is_long(vm->N))
                repeats = jl_unbox_long(vm->N);
            else
                hash = bitmix(0x064eeaab, hash); // 0x064eeaab is just a randomly chosen constant
            p = vm->T ? vm->T : (jl_value_t*)jl_any_type;
        }
        unsigned hashp = type_hash(p, &failed);
        if (failed && !nofail)
            return 0;
        while (repeats--)
            hash = bitmix(hashp, hash);
    }
    // hash = bitmix(~tn->hash, hash);
    hash = bitmix(~hash, hash);
    return hash ? hash : 1;
}


static unsigned type_hash(jl_value_t *kj, int *failed)
{
    jl_value_t *uw = jl_is_unionall(kj) ? jl_unwrap_unionall(kj) : kj;
    if (jl_is_datatype(uw)) {
        jl_datatype_t *dt = (jl_datatype_t*)uw;
        unsigned hash = dt->hash;
        if (!hash) {
            // if (!*failed) {
            //     *failed = 1;
            //     return 0;
            // }
            // compute a hash now, only for the parent object we are putting in the cache
            hash = typekey_hash(dt->name, jl_svec_data(dt->parameters), jl_svec_len(dt->parameters), *failed);
        }
        return hash;
    }
    else if (jl_is_typevar(uw)) {
        // ignore var and lb, since those might get normalized out in equality testing
        return type_hash(((jl_tvar_t*)uw)->ub, failed);
    }
    else if (jl_is_uniontype(uw)) {
        if (!*failed) {
            *failed = 1;
            return 0;
        }
        // compute a hash now, only for the parent object we are putting in the cache
        unsigned hasha = type_hash(((jl_uniontype_t*)uw)->a, failed);
        unsigned hashb = type_hash(((jl_uniontype_t*)uw)->b, failed);
        // use a associative mixing function, with well-defined overflow
        // since Union is associative
        return hasha + hashb;
    }
    else {
        return jl_object_id(uw);
    }
}


uint64_t int64hash(uint64_t key)
{
    key = (~key) + (key << 21);            // key = (key << 21) - key - 1;
    key =   key  ^ (key >> 24);
    key = (key + (key << 3)) + (key << 8); // key * 265
    key =  key ^ (key >> 14);
    key = (key + (key << 2)) + (key << 4); // key * 21
    key =  key ^ (key >> 28);
    key =  key + (key << 31);
    return key;
}


static unsigned typekeyvalue_hash(jl_typename_t *tn, jl_value_t *key1, jl_value_t **key, size_t n, int leaf) JL_NOTSAFEPOINT
{
    size_t j;
    unsigned hash = 3;
    for (j = 0; j < n; j++) {
        // jl_value_t *kj = j == 0 ? key1 : key[j - 1];
        jl_value_t *kj = key1;
        uint_t hj;
        if (leaf && jl_is_kind(jl_typeof(kj))) {
            hj = typekey_hash(jl_type_typename, &kj, 1, 0);
            if (hj == 0)
                return 0;
        }
        else {
            hj = ((jl_datatype_t*)jl_typeof(kj))->hash;
        }
        hash = bitmix(hj, hash);
    }
    // hash = bitmix(~tn->hash, hash);
    hash = bitmix(~hash, hash);
    return hash ? hash : 1;
}

jl_svec_t mock_params;

static int typekeyvalue_eq(jl_datatype_t *tt, jl_value_t *key1, jl_value_t **key, size_t n, int leaf)
{
    size_t j;
    // TODO: This shouldn't be necessary
    JL_GC_PROMISE_ROOTED(tt);
    size_t tnp = n;// jl_nparams(tt);
    if (n != tnp)
        return 0;
    int mock_val = 0;
    if (leaf && tt->name == jl_type_typename && mock_val) {
        // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
        // dispatch from changing the type of something.
        // this should work because `Type`s don't have uids, and aren't the
        // direct tags of values so we don't rely on pointer equality.
        jl_value_t *kj = key1;
        jl_value_t *tj = jl_tparam0(tt);
        return (kj == tj || (jl_typeof(tj) == jl_typeof(kj) && jl_types_equal(tj, kj)));
    }
    for (j = 0; j < n; j++) {
        jl_value_t *kj = j == 0 ? key1 : key[j - 1];
        tt->parameters = &mock_params;
        mock_params.length = n;
        continue; // mock
        jl_value_t *tj = jl_svecref(tt->parameters, j);
        if (leaf && jl_is_type_type(tj)) {
            jl_value_t *tp0 = jl_tparam0(tj);
            if (!(kj == tp0 || (jl_typeof(tp0) == jl_typeof(kj) && jl_types_equal(tp0, kj))))
                return 0;
        }
        else if (jl_typeof(kj) != tj) {
            return 0;
        }
        else if (leaf && jl_is_kind(tj)) {
            return 0;
        }
    }
    return 0; // mock
    // return 1;
}


static ssize_t lookup_type_idx_linearvalue(jl_svec_t *cache, jl_value_t *key1, jl_value_t **key, size_t n)
{
    if (n == 0)
        return -1;
    _Atomic(jl_datatype_t*) *data = (_Atomic(jl_datatype_t*)*)jl_svec_data(cache);
    size_t cl = jl_svec_len(cache);
    ssize_t i;
    for (i = 0; i < cl; i++) {
        jl_datatype_t *tt = jl_atomic_load_relaxed(&data[i]);
        if ((jl_value_t*)tt == jl_nothing)
            return ~i;
        if (typekeyvalue_eq(tt, key1, key, n, 1))
            return i;
    }
    return ~cl;
}


#define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)
#define h2index(hv, sz) (size_t)(((hv) & ((sz)-1)) * 2)

jl_datatype_t mock_data_val;

static jl_datatype_t *lookup_type_setvalue(jl_svec_t *cache, jl_value_t *key1, jl_value_t **key, size_t n, uint_t hv, int leaf)
{
    size_t sz = jl_svec_len(cache);
    sz = n;
    if (sz == 0)
        return NULL;
    size_t maxprobe = max_probe(sz);
    _Atomic(jl_datatype_t*) *tab = (_Atomic(jl_datatype_t*)*)jl_svec_data(cache);
    size_t index = h2index(hv, sz);
    size_t orig = index;
    size_t iter = 0;
    do {
        jl_datatype_t *val = jl_atomic_load_relaxed(&tab[index]);
        val = &mock_data_val;
        val->hash = hv;

        if ((jl_value_t*)val == jl_nothing)
            return NULL;
        if (val->hash == hv && typekeyvalue_eq(val, key1, key, n, leaf))
            return val;
        index = (index + 1) & (sz - 1);
        iter++;
    } while (iter <= maxprobe && index != orig);
    return NULL;
}

jl_svec_t mock_cache;

static jl_value_t *lookup_typevalue(jl_typename_t *tn, jl_value_t *key1, jl_value_t **key, size_t n, int leaf)
{
    // JL_TIMING(TYPE_CACHE_LOOKUP, TYPE_CACHE_LOOKUP);
    unsigned hv = typekeyvalue_hash(tn, key1, key, n, leaf);
    if (hv) {
        // jl_svec_t *cache = jl_atomic_load_relaxed(&tn->cache);
        jl_svec_t *cache = &mock_cache;
        return (jl_value_t*)lookup_type_setvalue(cache, key1, key, n, hv, leaf);
    }
    else {
        assert(leaf);
        // jl_svec_t *linearcache = jl_atomic_load_relaxed(&tn->linearcache);
        jl_svec_t *linearcache = &mock_cache;
        ssize_t idx = lookup_type_idx_linearvalue(linearcache, key1, key, n);
        return (idx < 0) ? NULL : jl_svecref(linearcache, idx);
    }
}

JL_EXTENSION struct _jl_typestack_t {
    jl_datatype_t *tt;
    struct _jl_typestack_t *prev;
};

typedef struct _jl_typestack_t jl_typestack_t;


static jl_value_t *lookup_type(jl_typename_t *tn JL_PROPAGATES_ROOT, jl_value_t **key, size_t n)
{
    return NULL;
    // JL_TIMING(TYPE_CACHE_LOOKUP, TYPE_CACHE_LOOKUP);
    // if (tn == jl_type_typename) {
    //     assert(n == 1);
    //     jl_value_t *uw = jl_unwrap_unionall(key[0]);
    //     if (jl_is_datatype(uw) && key[0] == ((jl_datatype_t*)uw)->name->wrapper)
    //         return jl_atomic_load_acquire(&((jl_datatype_t*)uw)->name->Typeofwrapper);
    // }
    // unsigned hv = typekey_hash(tn, key, n, 0);
    // if (hv) {
    //     jl_svec_t *cache = jl_atomic_load_relaxed(&tn->cache);
    //     return (jl_value_t*)lookup_type_set(cache, key, n, hv);
    // }
    // else {
    //     jl_svec_t *linearcache = jl_atomic_load_relaxed(&tn->linearcache);
    //     ssize_t idx = lookup_type_idx_linear(linearcache, key, n);
    //     return (idx < 0) ? NULL : jl_svecref(linearcache, idx);
    // }
}


jl_value_t *extract_wrapper(jl_value_t *t JL_PROPAGATES_ROOT) JL_GLOBALLY_ROOTED
{
    return NULL;
    // t = jl_unwrap_unionall(t);
    // if (jl_is_datatype(t))
    //     return ((jl_datatype_t*)t)->name->wrapper;
    // if (jl_is_uniontype(t)) {
    //     jl_value_t *n1 = extract_wrapper(((jl_uniontype_t*)t)->a);
    //     if (n1 != NULL) return n1;
    //     return extract_wrapper(((jl_uniontype_t*)t)->b);
    // }
    // if (jl_is_typevar(t))
    //     return extract_wrapper(((jl_tvar_t*)t)->ub);
    // return NULL;
}


static int typekey_eq(jl_datatype_t *tt, jl_value_t **key, size_t n)
{
    size_t j;
    // TODO: This shouldn't be necessary
    JL_GC_PROMISE_ROOTED(tt);
    size_t tnp = jl_nparams(tt);
    if (n != tnp)
        return 0;
    if (tt->name == jl_type_typename) {
        // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
        // dispatch from changing the type of something.
        // this should work because `Type`s don't need unique pointers, and aren't the
        // direct tags of values (concrete) so we don't rely on pointer equality.
        jl_value_t *kj = key[0];
        jl_value_t *tj = jl_tparam0(tt);
        return (kj == tj || (jl_typeof(tj) == jl_typeof(kj) && jl_types_equal(tj, kj)));
    }
    for (j = 0; j < n; j++) {
        jl_value_t *kj = key[j];
        jl_value_t *tj = jl_svecref(tt->parameters, j);
        if (tj != kj) {
            if (tt->name == jl_tuple_typename) {
                // require exact same Type{T} in covariant context. see e.g. issue #22842
                // this should work because `Tuple{Type}`s don't need unique pointers, and aren't the
                // direct tags of values (concrete) so we don't rely on pointer equality.
                if (jl_is_type_type(tj) || jl_is_type_type(kj))
                    return 0;
            }
            if (jl_type_equality_is_identity(tj, kj))
                return 0;
            if (!jl_types_equal(tj, kj))
                return 0;
        }
    }
    return 1;
}

static jl_value_t *lookup_type_stack(jl_typestack_t *stack, jl_datatype_t *tt, size_t ntp,
                                     jl_value_t **iparams)
{
    // if an identical instantiation is already in process somewhere up the
    // stack, return it. this computes a fixed point for recursive types.
    jl_typename_t *tn = tt->name;
    while (stack != NULL) {
        JL_GC_PROMISE_ROOTED(stack->tt);
        if (stack->tt->name == tn &&
            ntp == jl_svec_len(stack->tt->parameters) &&
            typekey_eq(stack->tt, iparams, ntp)) {
            return (jl_value_t*)stack->tt;
        }
        stack = stack->prev;
    }
    return NULL;
}


static int check_datatype_parameters(jl_typename_t *tn, jl_value_t **params, size_t np, int nothrow)
{
    // jl_value_t *wrapper = tn->wrapper;
    // jl_value_t **bounds;
    // JL_GC_PUSHARGS(bounds, np*2);
    // int i = 0;
    // while (jl_is_unionall(wrapper)) {
    //     jl_tvar_t *tv = ((jl_unionall_t*)wrapper)->var;
    //     bounds[i++] = tv->lb;
    //     bounds[i++] = tv->ub;
    //     wrapper = ((jl_unionall_t*)wrapper)->body;
    // }
    // assert(i == np*2);
    // wrapper = tn->wrapper;
    // for (i = 0; i < np; i++) {
    //     assert(jl_is_unionall(wrapper));
    //     jl_tvar_t *tv = ((jl_unionall_t*)wrapper)->var;
    //     if (!within_typevar(params[i], bounds[2*i], bounds[2*i+1])) {
    //         if (nothrow) {
    //             JL_GC_POP();
    //             return 1;
    //         }
    //         if (tv->lb != bounds[2*i] || tv->ub != bounds[2*i+1])
    //             // pass a new version of `tv` containing the instantiated bounds
    //             tv = jl_new_typevar(tv->name, bounds[2*i], bounds[2*i+1]);
    //         JL_GC_PUSH1(&tv);
    //         jl_type_error_rt(jl_symbol_name(tn->name), jl_symbol_name(tv->name), (jl_value_t*)tv, params[i]);
    //     }
    //     int j;
    //     for (j = 2*i + 2; j < 2*np; j++) {
    //         jl_value_t *bj = bounds[j];
    //         if (bj != (jl_value_t*)jl_any_type && bj != jl_bottom_type) {
    //             int isub = j & 1;
    //             // use different nothrow level for lb and ub substitution.
    //             // TODO: This assuming the top instantiation could only start with
    //             // `nothrow == 2` or `nothrow == 0`. If `nothrow` is initially set to 1
    //             // then we might miss some inner error, perhaps the normal path should
    //             // also follow this rule？
    //             jl_value_t *nb = jl_substitute_var_nothrow(bj, tv, params[i], nothrow ? (isub ? 2 : 1) : 0 );
    //             if (nb == NULL) {
    //                 assert(nothrow);
    //                 JL_GC_POP();
    //                 return 1;
    //             }
    //             bounds[j] = nb;
    //         }
    //     }
    //     wrapper = ((jl_unionall_t*)wrapper)->body;
    // }
    // JL_GC_POP();
    return 0;
}


static jl_value_t *jl_tupletype_fill(size_t n, jl_value_t *v, int check, int nothrow)
{
    return NULL;
    // jl_value_t *p = NULL;
    // JL_GC_PUSH1(&p);
    // p = (jl_value_t*)jl_svec_fill(n, v);
    // p = inst_datatype_inner(jl_anytuple_type, (jl_svec_t*)p, jl_svec_data(p), n, NULL, NULL, check, nothrow);
    // JL_GC_POP();
    // return p;
}


jl_value_t *normalize_unionalls(jl_value_t *t)
{
    return NULL;
    // if (jl_is_uniontype(t)) {
    //     jl_uniontype_t *u = (jl_uniontype_t*)t;
    //     jl_value_t *a = NULL;
    //     jl_value_t *b = NULL;
    //     JL_GC_PUSH2(&a, &b);
    //     a = normalize_unionalls(u->a);
    //     b = normalize_unionalls(u->b);
    //     if (a != u->a || b != u->b) {
    //         t = jl_new_struct(jl_uniontype_type, a, b);
    //     }
    //     JL_GC_POP();
    // }
    // else if (jl_is_unionall(t)) {
    //     jl_unionall_t *u = (jl_unionall_t*)t;
    //     jl_value_t *body = normalize_unionalls(u->body);
    //     JL_GC_PUSH1(&body);
    //     if (body != u->body) {
    //         t = jl_new_struct(jl_unionall_type, u->var, body);
    //         u = (jl_unionall_t*)t;
    //     }

    //     if (u->var->lb == u->var->ub || may_substitute_ub(body, u->var)) {
    //         body = (jl_value_t*)u;
    //         JL_TRY {
    //             t = jl_instantiate_unionall(u, u->var->ub);
    //         }
    //         JL_CATCH {
    //             // just skip normalization
    //             // (may happen for bounds inconsistent with the wrapper's bounds)
    //         }
    //     }
    //     JL_GC_POP();
    // }
    // return t;
}


static jl_value_t *inst_type_w_(jl_value_t *t, jl_typeenv_t *env, jl_typestack_t *stack, int check, int nothrow)
{
    return NULL;
    // size_t i;
    // if (jl_is_typevar(t)) {
    //     jl_typeenv_t *e = env;
    //     while (e != NULL) {
    //         if (e->var == (jl_tvar_t*)t) {
    //             jl_value_t *val = e->val;
    //             return val;
    //         }
    //         e = e->prev;
    //     }
    //     return t;
    // }
    // if (jl_is_unionall(t)) {
    //     jl_unionall_t *ua = (jl_unionall_t*)t;
    //     jl_value_t *lb = NULL;
    //     jl_value_t *var = NULL;
    //     jl_value_t *newbody = NULL;
    //     JL_GC_PUSH3(&lb, &var, &newbody);
    //     // set nothrow <= 1 to ensure lb's accuracy.
    //     lb = inst_type_w_(ua->var->lb, env, stack, check, nothrow ? 1 : 0);
    //     if (lb == NULL) {
    //         assert(nothrow);
    //         t = NULL;
    //     }
    //     if (t != NULL) {
    //         var = inst_type_w_(ua->var->ub, env, stack, check, nothrow);
    //         if (var == NULL) {
    //             if (lb == jl_bottom_type)
    //                 var = jl_bottom_type;
    //             else
    //                 t = NULL;
    //         }
    //         else if (lb != ua->var->lb || var != ua->var->ub) {
    //             var = (jl_value_t*)jl_new_typevar(ua->var->name, lb, var);
    //         }
    //         else {
    //             var = (jl_value_t*)ua->var;
    //         }
    //     }
    //     if (t != NULL) {
    //         jl_typeenv_t newenv = { ua->var, var, env };
    //         newbody = inst_type_w_(ua->body, &newenv, stack, check, nothrow);
    //         if (newbody == NULL) {
    //             t = NULL;
    //         }
    //         else if (!jl_has_typevar(newbody, (jl_tvar_t *)var)) {
    //             // inner instantiation might make a typevar disappear, e.g.
    //             // NTuple{0,T} => Tuple{}
    //             t = newbody;
    //         }
    //         else if (newbody != ua->body || var != (jl_value_t*)ua->var) {
    //             // if t's parameters are not bound in the environment, return it uncopied (#9378)
    //             t = jl_new_struct(jl_unionall_type, var, newbody);
    //         }
    //     }
    //     JL_GC_POP();
    //     return t;
    // }
    // if (jl_is_uniontype(t)) {
    //     jl_uniontype_t *u = (jl_uniontype_t*)t;
    //     jl_value_t *a = inst_type_w_(u->a, env, stack, check, nothrow);
    //     jl_value_t *b = NULL;
    //     JL_GC_PUSH2(&a, &b);
    //     b = inst_type_w_(u->b, env, stack, check, nothrow);
    //     if (nothrow) {
    //         // ensure jl_type_union nothrow.
    //         if (a && !(jl_is_typevar(a) || jl_is_type(a)))
    //             a = NULL;
    //         if (b && !(jl_is_typevar(b) || jl_is_type(b)))
    //             b = NULL;
    //     }
    //     if (a != u->a || b != u->b) {
    //         if (!check) {
    //             // fast path for `jl_rename_unionall`.
    //             t = jl_new_struct(jl_uniontype_type, a, b);
    //         }
    //         else if (a == NULL || b == NULL) {
    //             assert(nothrow);
    //             t = nothrow == 1 ? NULL : a == NULL ? b : a;
    //         }
    //         else {
    //             assert(a != NULL && b != NULL);
    //             jl_value_t *uargs[2] = {a, b};
    //             t = jl_type_union(uargs, 2);
    //         }
    //     }
    //     JL_GC_POP();
    //     return t;
    // }
    // if (jl_is_vararg(t)) {
    //     jl_vararg_t *v = (jl_vararg_t*)t;
    //     jl_value_t *T = NULL;
    //     jl_value_t *N = NULL;
    //     JL_GC_PUSH2(&T, &N);
    //     if (v->T) {
    //         T = inst_type_w_(v->T, env, stack, check, nothrow);
    //         if (T == NULL) {
    //             if (nothrow == 2)
    //                 T = jl_bottom_type;
    //             else
    //                 t = NULL;
    //         }
    //         if (t && v->N) {
    //             // set nothrow <= 1 to ensure invariant parameter's accuracy.
    //             N = inst_type_w_(v->N, env, stack, check, nothrow ? 1 : 0);
    //             if (N == NULL)
    //                 t = NULL;
    //         }
    //     }
    //     if (t && (T != v->T || N != v->N))
    //         t = (jl_value_t*)jl_wrap_vararg(T, N, check, nothrow);
    //     JL_GC_POP();
    //     return t;
    // }
    // if (!jl_is_datatype(t))
    //     return t;
    // jl_datatype_t *tt = (jl_datatype_t*)t;
    // jl_svec_t *tp = tt->parameters;
    // if (tp == jl_emptysvec)
    //     return t;
    // jl_typename_t *tn = tt->name;
    // if (tn == jl_tuple_typename)
    //     return inst_tuple_w_(t, env, stack, check, nothrow);
    // size_t ntp = jl_svec_len(tp);
    // jl_value_t **iparams;
    // JL_GC_PUSHARGS(iparams, ntp);
    // int bound = 0;
    // for (i = 0; i < ntp; i++) {
    //     jl_value_t *elt = jl_svecref(tp, i);
    //     // set nothrow <= 1 to ensure invariant parameter's accuracy.
    //     jl_value_t *pi = inst_type_w_(elt, env, stack, check, nothrow ? 1 : 0);
    //     if (pi == NULL) {
    //         assert(nothrow);
    //         t = NULL;
    //         break;
    //     }
    //     iparams[i] = pi;
    //     bound |= (pi != elt);
    // }
    // // if t's parameters are not bound in the environment, return it uncopied (#9378)
    // if (t != NULL && bound)
    //     t = inst_datatype_inner(tt, NULL, iparams, ntp, stack, env, check, nothrow);
    // JL_GC_POP();
    // return t;
}


static jl_svec_t *inst_ftypes(jl_svec_t *p, jl_typeenv_t *env, jl_typestack_t *stack)
{
    return NULL;
    // size_t i;
    // size_t lp = jl_svec_len(p);
    // jl_svec_t *np = jl_alloc_svec(lp);
    // JL_GC_PUSH1(&np);
    // for (i = 0; i < lp; i++) {
    //     jl_value_t *pi = jl_svecref(p, i);
    //     JL_TRY {
    //         pi = inst_type_w_(pi, env, stack, 1, 0);
    //         if (!jl_is_type(pi) && !jl_is_typevar(pi)) {
    //             pi = jl_bottom_type;
    //         }
    //     }
    //     JL_CATCH {
    //         pi = jl_bottom_type;
    //     }
    //     jl_svecset(np, i, pi);
    // }
    // JL_GC_POP();
    // return np;
}


void jl_compute_field_offsets(jl_datatype_t *st)
{
    return;
    // const uint64_t max_offset = (((uint64_t)1) << 32) - 1;
    // const uint64_t max_size = max_offset >> 1;

    // if (st->name->wrapper == NULL)
    //     return; // we got called too early--we'll be back
    // jl_datatype_t *w = (jl_datatype_t*)jl_unwrap_unionall(st->name->wrapper);
    // if (st == w && st->layout) {
    //     // this check allows us to force re-computation of the layout for some types during init
    //     st->layout = NULL;
    //     st->zeroinit = 0;
    //     st->has_concrete_subtype = 1;
    // }
    // int isbitstype = st->isconcretetype && st->name->mayinlinealloc;
    // int ismutationfree = !w->layout || !jl_is_layout_opaque(w->layout);
    // int isidentityfree = !st->name->mutabl;
    // // If layout doesn't depend on type parameters, it's stored in st->name->wrapper
    // // and reused by all subtypes.
    // if (w->layout) {
    //     st->layout = w->layout;
    //     st->zeroinit = w->zeroinit;
    //     st->has_concrete_subtype = w->has_concrete_subtype;
    //     if (!jl_is_layout_opaque(st->layout)) { // e.g. jl_array_typename
    //         st->isbitstype = isbitstype && st->layout->npointers == 0;
    //         jl_maybe_allocate_singleton_instance(st);
    //     }
    //     return;
    // }
    // assert(st->types && w->types);
    // size_t i, nfields = jl_svec_len(st->types);
    // assert(st->name->n_uninitialized <= nfields);
    // if (nfields == 0) {
    //     // if we have no fields, we can trivially skip the rest
    //     if (st == jl_symbol_type || st == jl_string_type) {
    //         // opaque layout - heap-allocated blob
    //         static const jl_datatype_layout_t opaque_byte_layout = {0, 0, 1, -1, 1, 0, 0};
    //         st->layout = &opaque_byte_layout;
    //         return;
    //     }
    //     else if (st == jl_simplevector_type || st == jl_module_type || st->name == jl_array_typename) {
    //         static const jl_datatype_layout_t opaque_ptr_layout = {0, 0, 1, -1, sizeof(void*), 0, 0};
    //         st->layout = &opaque_ptr_layout;
    //         return;
    //     }
    //     else {
    //         // reuse the same layout for all singletons
    //         static const jl_datatype_layout_t singleton_layout = {0, 0, 0, -1, 1, 0, 0};
    //         st->layout = &singleton_layout;
    //     }
    // }
    // else {
    //     // compute a conservative estimate of whether there could exist an instance of a subtype of this
    //     for (i = 0; st->has_concrete_subtype && i < nfields - st->name->n_uninitialized; i++) {
    //         jl_value_t *fld = jl_svecref(st->types, i);
    //         if (fld == jl_bottom_type)
    //             st->has_concrete_subtype = 0;
    //         else
    //             st->has_concrete_subtype = !jl_is_datatype(fld) || ((jl_datatype_t *)fld)->has_concrete_subtype;
    //     }
    //     // compute layout for the wrapper object if the field types have no free variables
    //     if (!st->isconcretetype && !jl_has_fixed_layout(st)) {
    //         assert(st == w); // otherwise caller should not have requested this layout
    //         return;
    //     }
    // }

    // for (i = 0; (isbitstype || isidentityfree || ismutationfree) && i < nfields; i++) {
    //     jl_value_t *fld = jl_field_type(st, i);
    //     isbitstype &= jl_isbits(fld);
    //     ismutationfree &= (!st->name->mutabl || jl_field_isconst(st, i)) && is_type_mutationfree(fld);
    //     isidentityfree &= is_type_identityfree(fld);
    // }

    // // if we didn't reuse the layout above, compute it now
    // if (st->layout == NULL) {
    //     size_t descsz = nfields * sizeof(jl_fielddesc32_t);
    //     jl_fielddesc32_t *desc;
    //     uint32_t *pointers;
    //     int should_malloc = descsz >= jl_page_size;
    //     if (should_malloc)
    //         desc = (jl_fielddesc32_t*)malloc_s(descsz);
    //     else
    //         desc = (jl_fielddesc32_t*)alloca(descsz);
    //     size_t sz = 0;
    //     size_t alignm = 1;
    //     int zeroinit = 0;
    //     int haspadding = 0;
    //     int homogeneous = 1;
    //     int needlock = 0;
    //     uint32_t npointers = 0;
    //     jl_value_t *firstty = jl_field_type(st, 0);
    //     for (i = 0; i < nfields; i++) {
    //         jl_value_t *fld = jl_field_type(st, i);
    //         int isatomic = jl_field_isatomic(st, i);
    //         size_t fsz = 0, al = 1;
    //         if (jl_islayout_inline(fld, &fsz, &al) && (!isatomic || jl_is_datatype(fld))) { // aka jl_datatype_isinlinealloc
    //             if (__unlikely(fsz > max_size))
    //                 // Should never happen
    //                 throw_ovf(should_malloc, desc, st, fsz);
    //             desc[i].isptr = 0;
    //             if (jl_is_uniontype(fld)) {
    //                 haspadding = 1;
    //                 fsz += 1; // selector byte
    //                 zeroinit = 1;
    //             }
    //             else {
    //                 uint32_t fld_npointers = ((jl_datatype_t*)fld)->layout->npointers;
    //                 if (((jl_datatype_t*)fld)->layout->haspadding)
    //                     haspadding = 1;
    //                 if (i >= nfields - st->name->n_uninitialized && fld_npointers &&
    //                     fld_npointers * sizeof(void*) != fsz) {
    //                     // field may be undef (may be uninitialized and contains pointer),
    //                     // and contains non-pointer fields of non-zero sizes.
    //                     haspadding = 1;
    //                 }
    //                 if (!zeroinit)
    //                     zeroinit = ((jl_datatype_t*)fld)->zeroinit;
    //                 npointers += fld_npointers;
    //             }
    //         }
    //         else {
    //             fsz = sizeof(void*);
    //             if (fsz > MAX_ALIGN)
    //                 fsz = MAX_ALIGN;
    //             al = fsz;
    //             desc[i].isptr = 1;
    //             zeroinit = 1;
    //             npointers++;
    //             if (!jl_pointer_egal(fld)) {
    //                 // this somewhat poorly named flag says whether some of the bits can be non-unique
    //                 haspadding = 1;
    //             }
    //         }
    //         if (isatomic && fsz > MAX_ATOMIC_SIZE)
    //             needlock = 1;
    //         if (isatomic && fsz <= MAX_ATOMIC_SIZE)
    //             al = fsz = next_power_of_two(fsz);
    //         if (al != 0) {
    //             size_t alsz = LLT_ALIGN(sz, al);
    //             if (alsz != sz)
    //                 haspadding = 1;
    //             sz = alsz;
    //             if (al > alignm)
    //                 alignm = al;
    //         }
    //         homogeneous &= firstty == fld;
    //         desc[i].offset = sz;
    //         desc[i].size = fsz;
    //         if (__unlikely(max_offset - sz < fsz))
    //             throw_ovf(should_malloc, desc, st, sz);
    //         sz += fsz;
    //     }
    //     if (needlock) {
    //         size_t offset = LLT_ALIGN(sizeof(jl_mutex_t), alignm);
    //         for (i = 0; i < nfields; i++) {
    //             desc[i].offset += offset;
    //         }
    //         if (__unlikely(max_offset - sz < offset))
    //             throw_ovf(should_malloc, desc, st, sz);
    //         sz += offset;
    //         haspadding = 1;
    //     }
    //     if (homogeneous && jl_is_tuple_type(st)) {
    //         // Some tuples become LLVM vectors with stronger alignment than what was calculated above.
    //         unsigned al = jl_special_vector_alignment(nfields, firstty);
    //         assert(al % alignm == 0);
    //         if (al > alignm)
    //             alignm = al;
    //     }
    //     if (LLT_ALIGN(sz, alignm) > sz) {
    //         haspadding = 1;
    //         sz = LLT_ALIGN(sz, alignm);
    //     }
    //     if (should_malloc && npointers)
    //         pointers = (uint32_t*)malloc_s(npointers * sizeof(uint32_t));
    //     else
    //         pointers = (uint32_t*)alloca(npointers * sizeof(uint32_t));
    //     size_t ptr_i = 0;
    //     for (i = 0; i < nfields; i++) {
    //         jl_value_t *fld = jl_field_type(st, i);
    //         uint32_t offset = desc[i].offset / sizeof(jl_value_t**);
    //         if (desc[i].isptr)
    //             pointers[ptr_i++] = offset;
    //         else if (jl_is_datatype(fld)) {
    //             int j, npointers = ((jl_datatype_t*)fld)->layout->npointers;
    //             for (j = 0; j < npointers; j++) {
    //                 pointers[ptr_i++] = offset + jl_ptr_offset((jl_datatype_t*)fld, j);
    //             }
    //         }
    //     }
    //     assert(ptr_i == npointers);
    //     st->layout = jl_get_layout(sz, nfields, npointers, alignm, haspadding, desc, pointers);
    //     if (should_malloc) {
    //         free(desc);
    //         if (npointers)
    //             free(pointers);
    //     }
    //     st->zeroinit = zeroinit;
    // }
    // // now finish deciding if this instantiation qualifies for special properties
    // assert(!isbitstype || st->layout->npointers == 0); // the definition of isbits
    // st->isbitstype = isbitstype;
    // st->ismutationfree = ismutationfree;
    // st->isidentityfree = isidentityfree;
    // jl_maybe_allocate_singleton_instance(st);
    // return;
}


void jl_precompute_memoized_dt(jl_datatype_t *dt, int cacheable)
{
    return;
    // int istuple = (dt->name == jl_tuple_typename);
    // dt->hasfreetypevars = 0;
    // dt->maybe_subtype_of_cache = 1;
    // dt->isconcretetype = !dt->name->abstract;
    // dt->isdispatchtuple = istuple;
    // size_t i, l = jl_nparams(dt);
    // for (i = 0; i < l; i++) {
    //     jl_value_t *p = jl_tparam(dt, i);
    //     if (!dt->hasfreetypevars) {
    //         dt->hasfreetypevars = jl_has_free_typevars(p);
    //         if (dt->hasfreetypevars)
    //             dt->isconcretetype = 0;
    //     }
    //     if (istuple) {
    //         if (dt->isconcretetype)
    //             dt->isconcretetype = (jl_is_datatype(p) && ((jl_datatype_t*)p)->isconcretetype) || p == jl_bottom_type;
    //         if (dt->isdispatchtuple) {
    //             dt->isdispatchtuple = jl_is_datatype(p) &&
    //                 ((!jl_is_kind(p) && ((jl_datatype_t*)p)->isconcretetype) ||
    //                  (p == (jl_value_t*)jl_typeofbottom_type) || // == Type{Union{}}, so needs to be consistent
    //                  (((jl_datatype_t*)p)->name == jl_type_typename && !((jl_datatype_t*)p)->hasfreetypevars));
    //         }
    //     }
    //     if (jl_is_vararg(p))
    //         p = ((jl_vararg_t*)p)->T;
    //     if (istuple && dt->has_concrete_subtype) {
    //         // tuple types like Tuple{:x} and Tuple{Union{}} cannot have instances
    //         if (p && !jl_is_type(p) && !jl_is_typevar(p))
    //             dt->has_concrete_subtype = 0;
    //         if (p == jl_bottom_type)
    //             dt->has_concrete_subtype = 0;
    //     }
    //     if (dt->maybe_subtype_of_cache) {
    //         dt->maybe_subtype_of_cache = !p || maybe_subtype_of_cache(p, istuple) || !jl_has_free_typevars(p);
    //     }
    // }
    // assert(dt->isconcretetype || dt->isdispatchtuple ? dt->maybe_subtype_of_cache : 1);
    // if (dt->name == jl_type_typename) {
    //     jl_value_t *p = jl_tparam(dt, 0);
    //     if (!jl_is_type(p) && !jl_is_typevar(p)) // Type{v} has no subtypes, if v is not a Type
    //         dt->has_concrete_subtype = 0;
    //     dt->maybe_subtype_of_cache = 1;
    //     jl_value_t *uw = jl_unwrap_unionall(p);
    //     // n.b. the cache for Type ignores parameter normalization except for Typeofwrapper, so it can't be used to make a stable hash value
    //     if (!jl_is_datatype(uw) || ((jl_datatype_t*)uw)->name->wrapper != p)
    //         cacheable = 0;
    // }
    // dt->hash = typekey_hash(dt->name, jl_svec_data(dt->parameters), l, cacheable);
}


void jl_cache_type_(jl_datatype_t *type)
{
    return;
    // JL_TIMING(TYPE_CACHE_INSERT, TYPE_CACHE_INSERT);
    // assert(is_cacheable(type));
    // jl_value_t **key = jl_svec_data(type->parameters);
    // int n = jl_svec_len(type->parameters);
    // if (type->name == jl_type_typename) {
    //     assert(n == 1);
    //     jl_value_t *uw = jl_unwrap_unionall(key[0]);
    //     if (jl_is_datatype(uw) && key[0] == ((jl_datatype_t*)uw)->name->wrapper) {
    //         jl_typename_t *tn2 = ((jl_datatype_t*)uw)->name;
    //         jl_atomic_store_release(&tn2->Typeofwrapper, (jl_value_t*)type);
    //         jl_gc_wb(tn2, type);
    //         return;
    //     }
    // }
    // unsigned hv = typekey_hash(type->name, key, n, 0);
    // if (hv) {
    //     assert(hv == type->hash);
    //     cache_insert_type_set(type, hv);
    // }
    // else {
    //     ssize_t idx = lookup_type_idx_linear(jl_atomic_load_relaxed(&type->name->linearcache), key, n);
    //     assert(idx < 0);
    //     cache_insert_type_linear(type, ~idx);
    // }
}


int jl_type_equality_is_identity(jl_value_t *t1, jl_value_t *t2) JL_NOTSAFEPOINT
{
    return 0;
    // int c1 = jl_is_concrete_type(t1);
    // int c2 = jl_is_concrete_type(t2);
    // if (c1 && c2) {
    //     if (((jl_datatype_t*)t1)->name != jl_tuple_typename)
    //         return 1;
    //     if (((jl_datatype_t*)t2)->name != jl_tuple_typename)
    //         return 1;
    //     if (((jl_datatype_t*)t1)->has_concrete_subtype && ((jl_datatype_t*)t2)->has_concrete_subtype)
    //         return 1;
    //     // e.g. Tuple{Union{}} and Tuple{Int} are both concrete!
    // }
    // if (c1 && !has_concrete_supertype(t2))
    //     return 1;
    // if (c2 && !has_concrete_supertype(t1))
    //     return 1;
    // return 0;
}


static jl_value_t *inst_datatype_inner(jl_datatype_t *dt, jl_svec_t *p, jl_value_t **iparams, size_t ntp,
                                       jl_typestack_t *stack, jl_typeenv_t *env, int check, int nothrow)
{
    jl_typestack_t top;
    jl_typename_t *tn = dt->name;
    int istuple = (tn == jl_tuple_typename);
    int isnamedtuple = (tn == jl_namedtuple_typename);

    // check if type cache will be applicable
    int cacheable = 1;
    if (istuple) {
        size_t i;
        for (i = 0; i < ntp; i++) {
            jl_value_t *pi = iparams[i];
            if (jl_is_vararg(pi) && jl_unwrap_vararg(pi) == jl_bottom_type) {
                jl_value_t *va1 = jl_unwrap_vararg_num(pi);
                if (va1 && jl_is_long(va1)) {
                    ssize_t nt = jl_unbox_long(va1);
                    if (nt == 0)
                        va1 = NULL;
                    else
                        pi = jl_bottom_type; // trigger errorf below
                }
                // This imposes an implicit constraint that va1==0,
                // so we keep the Vararg if it has a TypeVar
                if (va1 == NULL) {
                    p = NULL;
                    ntp -= 1;
                    assert(i == ntp);
                    break;
                }
            }
            if (pi == jl_bottom_type) {
                if (nothrow)
                    return NULL;
                jl_errorf("Tuple field type cannot be Union{}");
            }
            if (cacheable && !jl_is_concrete_type(pi))
                cacheable = 0;
        }
    }
    else {
        size_t i;
        for (i = 0; cacheable && i < ntp; i++)
            if (jl_has_free_typevars(iparams[i]))
                cacheable = 0;
    }
    // if applicable, check the cache first for a match
    if (cacheable) {
        jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL)
            return lkup;
    }
    // if some normalization might be needed, do that now
    // it is probably okay to mutate iparams, and we only store globally rooted objects here
    if (check) {
        size_t i;
        for (i = 0; i < ntp; i++) {
            jl_value_t *pi = iparams[i];
            if (pi == jl_bottom_type)
                continue;
            if (jl_is_datatype(pi))
                continue;
            if (jl_is_vararg(pi))
                // This is already handled in jl_wrap_vararg instead
                continue;
            if (!cacheable && jl_has_free_typevars(pi))
                continue;
            // normalize types equal to wrappers (prepare for Typeofwrapper)
            jl_value_t *tw = extract_wrapper(pi);
            if (tw && tw != pi && (tn != jl_type_typename || jl_typeof(pi) == jl_typeof(tw)) &&
                    jl_types_equal(pi, tw)) {
                iparams[i] = tw;
                if (p) jl_gc_wb(p, tw);
            }
        }
        if (tn == jl_type_typename && jl_is_datatype(iparams[0]) && ((jl_datatype_t*)iparams[0])->name == jl_type_typename &&
            jl_tparam0(iparams[0]) == jl_bottom_type) {
            // normalize Type{Type{Union{}}} to Type{TypeofBottom}
            iparams[0] = (jl_value_t*)jl_typeofbottom_type;
        }
    }
    // then check the cache again, if applicable
    if (cacheable) {
        jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL)
            return lkup;
    }
    jl_value_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
    if (stack_lkup)
        return stack_lkup;

    // check parameters against bounds in type definition
    // for whether this is even valid
    if (check && !istuple) {
        assert(ntp > 0);
        if (check_datatype_parameters(tn, iparams, ntp, nothrow))
            return NULL;
    }
    else if (ntp == 0 && jl_emptytuple_type != NULL) {
        // empty tuple type case
        assert(istuple);
        return (jl_value_t*)jl_emptytuple_type;
    }

    jl_datatype_t *ndt = NULL;
    JL_GC_PUSH2(&p, &ndt);

    jl_value_t *last = iparams[ntp - 1];
    if (istuple && ntp > 0 && jl_is_vararg(last)) {
        // normalize Tuple{..., Vararg{Int, 3}} to Tuple{..., Int, Int, Int}
        jl_value_t *va = jl_unwrap_unionall(last);
        jl_value_t *va0 = jl_unwrap_vararg(va), *va1 = jl_unwrap_vararg_num(va);
        // return same `Tuple` object for types equal to it
        if (ntp == 1 && va0 == (jl_value_t*)jl_any_type && !va1) {
            JL_GC_POP();
            return (jl_value_t*)jl_anytuple_type;
        }
        if (va1 && jl_is_long(va1)) {
            ssize_t nt = jl_unbox_long(va1);
            assert(nt >= 0);
            if (nt == 0 || !jl_has_free_typevars(va0)) {
                if (ntp == 1) {
                    JL_GC_POP();
                    return jl_tupletype_fill(nt, va0, 0, 0);
                }
                size_t i, l;
                p = jl_alloc_svec(ntp - 1 + nt);
                for (i = 0, l = ntp - 1; i < l; i++)
                    jl_svecset(p, i, iparams[i]);
                l = ntp - 1 + nt;
                for (; i < l; i++)
                    jl_svecset(p, i, va0);
                size_t np = jl_svec_len(p);
                jl_value_t **pp = jl_svec_data(p);
                jl_value_t *ndt = inst_datatype_inner(jl_anytuple_type, p, pp, np, NULL, NULL, check, nothrow);
                JL_GC_POP();
                return ndt;
            }
        }
    }

    // move array of instantiated parameters to heap; we need to keep it
    if (p == NULL) {
        p = jl_alloc_svec_uninit(ntp);
        for (size_t i = 0; i < ntp; i++)
            jl_svecset(p, i, iparams[i]);
    }

    // try to simplify some type parameters
    if (check && tn != jl_type_typename) {
        size_t i;
        int changed = 0;
        if (istuple) // normalization might change Tuple's, but not other types's, cacheable status
            cacheable = 1;
        for (i = 0; i < ntp; i++) {
            jl_value_t *newp = normalize_unionalls(iparams[i]);
            if (newp != iparams[i]) {
                iparams[i] = newp;
                jl_svecset(p, i, newp);
                changed = 1;
            }
            if (istuple && cacheable && !jl_is_concrete_type(newp))
                cacheable = 0;
        }
        if (changed) {
            // If this changed something, we need to check the cache again, in
            // case we missed the match earlier before the normalizations
            //
            // e.g. return inst_datatype_inner(dt, p, iparams, ntp, stack, env, 0);
            if (cacheable) {
                jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
                if (lkup != NULL) {
                    JL_GC_POP();
                    return lkup;
                }
            }
            jl_value_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
            if (stack_lkup) {
                JL_GC_POP();
                return stack_lkup;
            }
        }
    }

    // acquire the write lock now that we know we need a new object
    // since we're going to immediately leak it globally via the instantiation stack
    if (cacheable) {
        // JL_LOCK(&typecache_lock); // Might GC
        jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
        if (lkup != NULL) {
            // JL_UNLOCK(&typecache_lock); // Might GC
            JL_GC_POP();
            return lkup;
        }
    }

    // // create and initialize new type
    // ndt = jl_new_uninitialized_datatype();
    // ndt->isprimitivetype = dt->isprimitivetype;
    // // Usually dt won't have ismutationfree set at this point, but it is
    // // overriden for `Type`, which we handle here.
    // ndt->ismutationfree = dt->ismutationfree;
    // // associate these parameters with the new type on
    // // the stack, in case one of its field types references it.
    // top.tt = (jl_datatype_t*)ndt;
    // top.prev = stack;
    // stack = &top;
    // ndt->name = tn;
    // jl_gc_wb(ndt, ndt->name);
    // ndt->super = NULL;
    // ndt->parameters = p;
    // jl_gc_wb(ndt, ndt->parameters);
    // ndt->types = NULL; // to be filled in below
    int invalid = 0;
    if (istuple) {
        ndt->types = p; // TODO: this may need to filter out certain types
    }
    else if (isnamedtuple) {
        jl_value_t *names_tup = jl_svecref(p, 0);
        jl_value_t *values_tt = jl_svecref(p, 1);
        if (!jl_has_free_typevars(names_tup) && !jl_has_free_typevars(values_tt)) {
            if (!jl_is_tuple(names_tup)) {
                if (!nothrow)
                    jl_type_error_rt("NamedTuple", "names", (jl_value_t*)jl_anytuple_type, names_tup);
                invalid = 1;
            }
            size_t nf = jl_nfields(names_tup);
            for (size_t i = 0; i < nf; i++) {
                jl_value_t *ni = jl_fieldref(names_tup, i);
                if (!jl_is_symbol(ni)) {
                    if (!nothrow)
                        jl_type_error_rt("NamedTuple", "name", (jl_value_t*)jl_symbol_type, ni);
                    invalid = 1; break;
                }
                for (size_t j = 0; j < i; j++) {
                    if (ni == jl_fieldref_noalloc(names_tup, j)) {
                        if (!nothrow)
                            jl_errorf("duplicate field name in NamedTuple: \"%s\" is not unique", jl_symbol_name((jl_sym_t*)ni));
                        invalid = 1; break;
                    }
                }
                if (invalid) break;
            }
            if (values_tt == jl_bottom_type && nf > 0) {
                ndt->types = jl_svec_fill(nf, jl_bottom_type);
            }
            else {
                if (!jl_is_datatype(values_tt)) {
                    // should have been checked within `check_datatype_parameters`.
                    jl_error("NamedTuple field type must be a tuple datatype");
                }
                if (jl_is_va_tuple((jl_datatype_t*)values_tt) || jl_nparams(values_tt) != nf) {
                    if (!nothrow)
                        jl_error("NamedTuple names and field types must have matching lengths");
                    invalid = 1;
                }
                ndt->types = ((jl_datatype_t*)values_tt)->parameters;
            }
            jl_gc_wb(ndt, ndt->types);
        }
        else {
            ndt->types = jl_emptysvec; // XXX: this is essentially always incorrect
        }
    }

    if (nothrow && invalid) {
        // if (cacheable)
        //     JL_UNLOCK(&typecache_lock);
        JL_GC_POP();
        return NULL;
    }
    jl_datatype_t *primarydt = ((jl_datatype_t*)jl_unwrap_unionall(tn->wrapper));
    jl_precompute_memoized_dt(ndt, cacheable);
    if (primarydt->layout)
        jl_compute_field_offsets(ndt);

    if (istuple || isnamedtuple) {
        ndt->super = jl_any_type;
    }
    else if (dt->super) {
        jl_value_t *super = inst_type_w_((jl_value_t*)dt->super, env, stack, check, nothrow);
        if (nothrow && super == NULL) {
            // if (cacheable)
            //     JL_UNLOCK(&typecache_lock);
            JL_GC_POP();
            return NULL;
        }
        ndt->super = (jl_datatype_t *)super;
        jl_gc_wb(ndt, ndt->super);
    }
    jl_svec_t *ftypes = dt->types;
    if (ftypes == NULL)
        ftypes = primarydt->types;
    if (ftypes == NULL || dt->super == NULL) {
        // in the process of creating this type definition:
        // need to instantiate the super and types fields later
        if (tn->partial == NULL) {
            tn->partial = jl_alloc_vec_any(0);
            jl_gc_wb(tn, tn->partial);
        }
        jl_array_ptr_1d_push(tn->partial, (jl_value_t*)ndt);
    }
    else if (!isnamedtuple && !istuple) {
        assert(ftypes != jl_emptysvec || jl_field_names(ndt) == jl_emptysvec);
        assert(ftypes == jl_emptysvec || !ndt->name->abstract);
        if (ftypes == jl_emptysvec) {
            ndt->types = ftypes;
        }
        else if (cacheable) {
            // recursively instantiate the types of the fields
            if (dt->types == NULL)
                ndt->types = jl_compute_fieldtypes(ndt, stack);
            else
                ndt->types = inst_ftypes(ftypes, env, stack);
            jl_gc_wb(ndt, ndt->types);
        }
    }

    // now publish the finished result
    // XXX: if the stack was used, this will publish in the wrong order,
    // leading to incorrect layouts and data races (#40050: the A{T} should be
    // an isbitstype singleton of size 0)
    if (cacheable) {
        if (ndt->layout == NULL && ndt->types != NULL && ndt->isconcretetype)
            jl_compute_field_offsets(ndt);
        jl_cache_type_(ndt);
        // JL_UNLOCK(&typecache_lock); // Might GC
    }

    JL_GC_POP();
    return (jl_value_t*)ndt;
}

jl_tupletype_t *jl_inst_arg_tuple_type(jl_value_t *arg1, jl_value_t **args, size_t nargs, int leaf)
{
    jl_tupletype_t *tt = (jl_datatype_t*)lookup_typevalue(jl_tuple_typename, arg1, args, nargs, leaf);
    if (tt == NULL) {
        size_t i;
        // jl_svec_t *params = jl_alloc_svec(nargs);
        jl_typemap_entry_t* tmp_cache = (jl_typemap_entry_t*)mt_mock_data->cache;
        jl_svec_t *params = tmp_cache->sig->parameters;
        // JL_GC_PUSH1(&params);
        for (i = 0; i < nargs; i++) {
            jl_value_t *ai = (i == 0 ? arg1 : args[i - 1]);
            if (leaf) {// && jl_is_type(ai)) {
                // if `ai` has free type vars this will not be a valid (concrete) type.
                // TODO: it would be really nice to only dispatch and cache those as
                // `jl_typeof(ai)`, but that will require some redesign of the caching
                // logic.
                // ai = (jl_value_t*)jl_wrap_Type(ai);
            }
            else {
                ai = jl_typeof(ai);
            }
            // jl_svecset(params, i, ai);
        }
        tt = (jl_tupletype_t*)arg1;
        // tt = (jl_datatype_t*)inst_datatype_inner(jl_anytuple_type, params, jl_svec_data(params), nargs, NULL, NULL, 1, 0);
        // JL_GC_POP();
    }
    return tt;
}

static int concretesig_equal(jl_value_t *tt, jl_value_t *simplesig) JL_NOTSAFEPOINT
{
    jl_value_t **types = jl_svec_data(((jl_datatype_t*)tt)->parameters);
    jl_value_t **sigs = jl_svec_data(((jl_datatype_t*)simplesig)->parameters);
    size_t i, lensig = jl_nparams(simplesig);
    assert(lensig == jl_nparams(tt));
    assert(lensig > 0 && !jl_is_vararg(jl_tparam(simplesig, lensig - 1)));
    for (i = 0; i < lensig; i++) {
        jl_value_t *decl = sigs[i];
        jl_value_t *a = types[i];
        if (a != decl && decl != (jl_value_t*)jl_any_type) {
            if (!(jl_is_type_type(a) && jl_typeof(jl_tparam0(a)) == decl))
                return 0;
        }
    }
    return 1;
}

static inline jl_typemap_entry_t *lookup_leafcache(jl_array_t *leafcache JL_PROPAGATES_ROOT, jl_value_t *tt, size_t world) JL_NOTSAFEPOINT
{
    // TODO: Implement it?
    jl_typemap_entry_t *entry = (jl_typemap_entry_t*)jl_eqtable_get(leafcache, (jl_value_t*)tt, NULL);
    if (entry) {
        do {
            if (entry->min_world <= world && world <= entry->max_world) {
                if (entry->simplesig == (void*)jl_nothing || concretesig_equal(tt, (jl_value_t*)entry->simplesig))
                    return entry;
            }
            entry = jl_atomic_load_relaxed(&entry->next);
        } while ((jl_value_t*)entry != jl_nothing);
    }
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


// Main function for search generic method
JL_DLLEXPORT jl_method_instance_t *jl_lookup_generic_(jl_value_t *F, jl_value_t **args, uint32_t nargs,
                                                uint32_t callsite, size_t world) {
    jl_method_instance_t *m = NULL;

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
    if (entry != NULL) {
        m = entry->func.linfo;
    }
    return m;
}

JL_DLLEXPORT jl_method_instance_t *jl_lookup_generic_EMPTY(jl_value_t *, jl_value_t **,
    uint32_t, uint32_t, size_t)
{
    return NULL;
}

JL_DLLEXPORT jl_method_instance_t *jl_lookup_generic_FAST_1(jl_value_t *F, jl_value_t **args,
                                                            uint32_t nargs, uint32_t callsite, size_t world) {

    jl_method_instance_t * m = NULL;

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
    // LOOP_BODY(1);
    // LOOP_BODY(2);
    // LOOP_BODY(3);
    #undef LOOP_BODY

have_entry:
    return entry ? entry->func.linfo : NULL;
                                                            
}


JL_DLLEXPORT jl_method_instance_t * jl_lookup_generic_FAST(jl_value_t *F, jl_value_t **args, uint32_t nargs,
                                                 uint32_t callsite, size_t world) {
    jl_method_instance_t * m = NULL;

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

have_entry:
    return entry ? entry->func.linfo : NULL;
}
