
// #include "gf.h" // For generic functions
#include "julia.h"
#include "julia_internal.h"

#define N_CALL_CACHE 4096
_Atomic(jl_typemap_entry_t*) call_cache[N_CALL_CACHE];
static _Atomic(uint8_t) pick_which[N_CALL_CACHE];

jl_typemap_entry_t *jl_typemap_entry_assoc_exact(jl_typemap_entry_t *mn, jl_value_t *arg1, jl_value_t **args, size_t n, size_t world)
{
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


// static unsigned typekey_hash(jl_typename_t *tn, jl_value_t **key, size_t n, int nofail) JL_NOTSAFEPOINT;


// uint64_t int64hash(uint64_t key)
// {
//     key = (~key) + (key << 21);            // key = (key << 21) - key - 1;
//     key =   key  ^ (key >> 24);
//     key = (key + (key << 3)) + (key << 8); // key * 265
//     key =  key ^ (key >> 14);
//     key = (key + (key << 2)) + (key << 4); // key * 21
//     key =  key ^ (key >> 28);
//     key =  key + (key << 31);
//     return key;
// }


// static inline uint64_t bitmix(uint64_t a, uint64_t b)
// {
//     return int64hash(a^__builtin_bswap64(b));
// }


// // stable numbering for types--starts with name->hash, then falls back to objectid
// // sets *failed if the hash value isn't stable (if this param not set on entry)
// static unsigned type_hash(jl_value_t *kj, int *failed) JL_NOTSAFEPOINT
// {
//     jl_value_t *uw = jl_is_unionall(kj) ? jl_unwrap_unionall(kj) : kj;
//     if (jl_is_datatype(uw)) {
//         jl_datatype_t *dt = (jl_datatype_t*)uw;
//         unsigned hash = dt->hash;
//         if (!hash) {
//             if (!*failed) {
//                 *failed = 1;
//                 return 0;
//             }
//             // compute a hash now, only for the parent object we are putting in the cache
//             hash = typekey_hash(dt->name, jl_svec_data(dt->parameters), jl_svec_len(dt->parameters), *failed);
//         }
//         return hash;
//     }
//     else if (jl_is_typevar(uw)) {
//         // ignore var and lb, since those might get normalized out in equality testing
//         return type_hash(((jl_tvar_t*)uw)->ub, failed);
//     }
//     else if (jl_is_uniontype(uw)) {
//         if (!*failed) {
//             *failed = 1;
//             return 0;
//         }
//         // compute a hash now, only for the parent object we are putting in the cache
//         unsigned hasha = type_hash(((jl_uniontype_t*)uw)->a, failed);
//         unsigned hashb = type_hash(((jl_uniontype_t*)uw)->b, failed);
//         // use a associative mixing function, with well-defined overflow
//         // since Union is associative
//         return hasha + hashb;
//     }
//     else {
//         return jl_object_id(uw);
//     }
// }


// static unsigned typekey_hash(jl_typename_t *tn, jl_value_t **key, size_t n, int nofail) JL_NOTSAFEPOINT
// {
//     if (tn == jl_type_typename && key[0] == jl_bottom_type)
//         return jl_typeofbottom_type->hash;
//     size_t j;
//     unsigned hash = 3;
//     int failed = nofail;
//     for (j = 0; j < n; j++) {
//         jl_value_t *p = key[j];
//         size_t repeats = 1;
//         if (jl_is_vararg(p)) {
//             jl_vararg_t *vm = (jl_vararg_t*)p;
//             if (vm->N && jl_is_long(vm->N))
//                 repeats = jl_unbox_long(vm->N);
//             else
//                 hash = bitmix(0x064eeaab, hash); // 0x064eeaab is just a randomly chosen constant
//             p = vm->T ? vm->T : (jl_value_t*)jl_any_type;
//         }
//         unsigned hashp = type_hash(p, &failed);
//         if (failed && !nofail)
//             return 0;
//         while (repeats--)
//             hash = bitmix(hashp, hash);
//     }
//     hash = bitmix(~tn->hash, hash);
//     return hash ? hash : 1;
// }


// static unsigned typekeyvalue_hash(jl_typename_t *tn, jl_value_t *key1, jl_value_t **key, size_t n, int leaf) JL_NOTSAFEPOINT
// {
//     size_t j;
//     unsigned hash = 3;
//     for (j = 0; j < n; j++) {
//         jl_value_t *kj = j == 0 ? key1 : key[j - 1];
//         uint_t hj;
//         if (leaf && jl_is_kind(jl_typeof(kj))) {
//             hj = typekey_hash(jl_type_typename, &kj, 1, 0);
//             if (hj == 0)
//                 return 0;
//         }
//         else {
//             hj = ((jl_datatype_t*)jl_typeof(kj))->hash;
//         }
//         hash = bitmix(hj, hash);
//     }
//     hash = bitmix(~tn->hash, hash);
//     return hash ? hash : 1;
// }


// // These `value` functions return the same values as the primary functions,
// // but operate on the typeof/Typeof each object in an array
// static int typekeyvalue_eq(jl_datatype_t *tt, jl_value_t *key1, jl_value_t **key, size_t n, int leaf)
// {
//     size_t j;
//     // TODO: This shouldn't be necessary
//     JL_GC_PROMISE_ROOTED(tt);
//     size_t tnp = jl_nparams(tt);
//     if (n != tnp)
//         return 0;
//     if (leaf && tt->name == jl_type_typename) {
//         // for Type{T}, require `typeof(T)` to match also, to avoid incorrect
//         // dispatch from changing the type of something.
//         // this should work because `Type`s don't have uids, and aren't the
//         // direct tags of values so we don't rely on pointer equality.
//         jl_value_t *kj = key1;
//         jl_value_t *tj = jl_tparam0(tt);
//         return (kj == tj || (jl_typeof(tj) == jl_typeof(kj) && jl_types_equal(tj, kj)));
//     }
//     for (j = 0; j < n; j++) {
//         jl_value_t *kj = j == 0 ? key1 : key[j - 1];
//         jl_value_t *tj = jl_svecref(tt->parameters, j);
//         if (leaf && jl_is_type_type(tj)) {
//             jl_value_t *tp0 = jl_tparam0(tj);
//             if (!(kj == tp0 || (jl_typeof(tp0) == jl_typeof(kj) && jl_types_equal(tp0, kj))))
//                 return 0;
//         }
//         else if (jl_typeof(kj) != tj) {
//             return 0;
//         }
//         else if (leaf && jl_is_kind(tj)) {
//             return 0;
//         }
//     }
//     return 1;
// }


// #define max_probe(size) ((size) <= 1024 ? 16 : (size) >> 6)


// static jl_datatype_t *lookup_type_setvalue(jl_svec_t *cache, jl_value_t *key1, jl_value_t **key, size_t n, uint_t hv, int leaf)
// {
//     size_t sz = jl_svec_len(cache);
//     if (sz == 0)
//         return NULL;
//     size_t maxprobe = max_probe(sz);
//     _Atomic(jl_datatype_t*) *tab = (_Atomic(jl_datatype_t*)*)jl_svec_data(cache);
//     size_t index = h2index(hv, sz);
//     size_t orig = index;
//     size_t iter = 0;
//     do {
//         jl_datatype_t *val = jl_atomic_load_relaxed(&tab[index]);
//         if ((jl_value_t*)val == jl_nothing)
//             return NULL;
//         if (val->hash == hv && typekeyvalue_eq(val, key1, key, n, leaf))
//             return val;
//         index = (index + 1) & (sz - 1);
//         iter++;
//     } while (iter <= maxprobe && index != orig);
//     return NULL;
// }


// static ssize_t lookup_type_idx_linearvalue(jl_svec_t *cache, jl_value_t *key1, jl_value_t **key, size_t n)
// {
//     if (n == 0)
//         return -1;
//     _Atomic(jl_datatype_t*) *data = (_Atomic(jl_datatype_t*)*)jl_svec_data(cache);
//     size_t cl = jl_svec_len(cache);
//     ssize_t i;
//     for (i = 0; i < cl; i++) {
//         jl_datatype_t *tt = jl_atomic_load_relaxed(&data[i]);
//         if ((jl_value_t*)tt == jl_nothing)
//             return ~i;
//         if (typekeyvalue_eq(tt, key1, key, n, 1))
//             return i;
//     }
//     return ~cl;
// }


// static jl_value_t *lookup_typevalue(jl_typename_t *tn, jl_value_t *key1, jl_value_t **key, size_t n, int leaf)
// {
//     // JL_TIMING(TYPE_CACHE_LOOKUP, TYPE_CACHE_LOOKUP);
//     unsigned hv = typekeyvalue_hash(tn, key1, key, n, leaf);
//     if (hv) {
//         jl_svec_t *cache = jl_atomic_load_relaxed(&tn->cache);
//         return (jl_value_t*)lookup_type_setvalue(cache, key1, key, n, hv, leaf);
//     }
//     else {
//         assert(leaf);
//         jl_svec_t *linearcache = jl_atomic_load_relaxed(&tn->linearcache);
//         ssize_t idx = lookup_type_idx_linearvalue(linearcache, key1, key, n);
//         return (idx < 0) ? NULL : jl_svecref(linearcache, idx);
//     }
// }


// jl_tupletype_t *jl_lookup_arg_tuple_type(jl_value_t *arg1, jl_value_t **args, size_t nargs, int leaf)
// {
//     return (jl_datatype_t*)lookup_typevalue(jl_tuple_typename, arg1, args, nargs, leaf);
// }


// static int concretesig_equal(jl_value_t *tt, jl_value_t *simplesig) JL_NOTSAFEPOINT
// {
//     jl_value_t **types = jl_svec_data(((jl_datatype_t*)tt)->parameters);
//     jl_value_t **sigs = jl_svec_data(((jl_datatype_t*)simplesig)->parameters);
//     size_t i, lensig = jl_nparams(simplesig);
//     assert(lensig == jl_nparams(tt));
//     assert(lensig > 0 && !jl_is_vararg(jl_tparam(simplesig, lensig - 1)));
//     for (i = 0; i < lensig; i++) {
//         jl_value_t *decl = sigs[i];
//         jl_value_t *a = types[i];
//         if (a != decl && decl != (jl_value_t*)jl_any_type) {
//             if (!(jl_is_type_type(a) && jl_typeof(jl_tparam0(a)) == decl))
//                 return 0;
//         }
//     }
//     return 1;
// }


// // define a copy of exported data
// #define jl_max_tags 64
// jl_datatype_t *jl_small_typeof[(jl_max_tags << 4) / sizeof(void*)]; // 16-bit aligned, like the GC
// jl_typename_t* jl_tuple_typename;
// _Atomic(size_t) jl_world_counter = 1;



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


// typedef struct jl_typeenv_t {
//     jl_tvar_t *var;
//     jl_value_t *val;
//     struct jl_typeenv_t *prev;
// } jl_typeenv_t;

// JL_EXTENSION struct _jl_typestack_t {
//     jl_datatype_t *tt;
//     struct _jl_typestack_t *prev;
// };

// typedef struct _jl_typestack_t jl_typestack_t;


// jl_mutex_t typecache_lock;


// static jl_value_t *lookup_type_stack(jl_typestack_t *stack, jl_datatype_t *tt, size_t ntp,
//                                      jl_value_t **iparams)
// {
//     // if an identical instantiation is already in process somewhere up the
//     // stack, return it. this computes a fixed point for recursive types.
//     jl_typename_t *tn = tt->name;
//     while (stack != NULL) {
//         JL_GC_PROMISE_ROOTED(stack->tt);
//         if (stack->tt->name == tn &&
//             ntp == jl_svec_len(stack->tt->parameters) &&
//             typekey_eq(stack->tt, iparams, ntp)) {
//             return (jl_value_t*)stack->tt;
//         }
//         stack = stack->prev;
//     }
//     return NULL;
// }


// static jl_value_t *inst_datatype_inner(jl_datatype_t *dt, jl_svec_t *p, jl_value_t **iparams, size_t ntp,
//                                        jl_typestack_t *stack, jl_typeenv_t *env, int check, int nothrow)
// {
//     jl_typestack_t top;
//     jl_typename_t *tn = dt->name;
//     int istuple = (tn == jl_tuple_typename);
//     int isnamedtuple = (tn == jl_namedtuple_typename);

//     // check if type cache will be applicable
//     int cacheable = 1;
//     if (istuple) {
//         size_t i;
//         for (i = 0; i < ntp; i++) {
//             jl_value_t *pi = iparams[i];
//             if (jl_is_vararg(pi) && jl_unwrap_vararg(pi) == jl_bottom_type) {
//                 jl_value_t *va1 = jl_unwrap_vararg_num(pi);
//                 if (va1 && jl_is_long(va1)) {
//                     ssize_t nt = jl_unbox_long(va1);
//                     if (nt == 0)
//                         va1 = NULL;
//                     else
//                         pi = jl_bottom_type; // trigger errorf below
//                 }
//                 // This imposes an implicit constraint that va1==0,
//                 // so we keep the Vararg if it has a TypeVar
//                 if (va1 == NULL) {
//                     p = NULL;
//                     ntp -= 1;
//                     assert(i == ntp);
//                     break;
//                 }
//             }
//             if (pi == jl_bottom_type) {
//                 if (nothrow)
//                     return NULL;
//                 jl_errorf("Tuple field type cannot be Union{}");
//             }
//             if (cacheable && !jl_is_concrete_type(pi))
//                 cacheable = 0;
//         }
//     }
//     else {
//         size_t i;
//         for (i = 0; cacheable && i < ntp; i++)
//             if (jl_has_free_typevars(iparams[i]))
//                 cacheable = 0;
//     }
//     // if applicable, check the cache first for a match
//     if (cacheable) {
//         jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
//         if (lkup != NULL)
//             return lkup;
//     }
//     // if some normalization might be needed, do that now
//     // it is probably okay to mutate iparams, and we only store globally rooted objects here
//     if (check) {
//         size_t i;
//         for (i = 0; i < ntp; i++) {
//             jl_value_t *pi = iparams[i];
//             if (pi == jl_bottom_type)
//                 continue;
//             if (jl_is_datatype(pi))
//                 continue;
//             if (jl_is_vararg(pi))
//                 // This is already handled in jl_wrap_vararg instead
//                 continue;
//             if (!cacheable && jl_has_free_typevars(pi))
//                 continue;
//             // normalize types equal to wrappers (prepare for Typeofwrapper)
//             jl_value_t *tw = extract_wrapper(pi);
//             if (tw && tw != pi && (tn != jl_type_typename || jl_typeof(pi) == jl_typeof(tw)) &&
//                     jl_types_equal(pi, tw)) {
//                 iparams[i] = tw;
//                 if (p) jl_gc_wb(p, tw);
//             }
//         }
//         if (tn == jl_type_typename && jl_is_datatype(iparams[0]) && ((jl_datatype_t*)iparams[0])->name == jl_type_typename &&
//             jl_tparam0(iparams[0]) == jl_bottom_type) {
//             // normalize Type{Type{Union{}}} to Type{TypeofBottom}
//             iparams[0] = (jl_value_t*)jl_typeofbottom_type;
//         }
//     }
//     // then check the cache again, if applicable
//     if (cacheable) {
//         jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
//         if (lkup != NULL)
//             return lkup;
//     }
//     jl_value_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
//     if (stack_lkup)
//         return stack_lkup;

//     // check parameters against bounds in type definition
//     // for whether this is even valid
//     if (check && !istuple) {
//         assert(ntp > 0);
//         if (check_datatype_parameters(tn, iparams, ntp, nothrow))
//             return NULL;
//     }
//     else if (ntp == 0 && jl_emptytuple_type != NULL) {
//         // empty tuple type case
//         assert(istuple);
//         return (jl_value_t*)jl_emptytuple_type;
//     }

//     jl_datatype_t *ndt = NULL;
//     JL_GC_PUSH2(&p, &ndt);

//     jl_value_t *last = iparams[ntp - 1];
//     if (istuple && ntp > 0 && jl_is_vararg(last)) {
//         // normalize Tuple{..., Vararg{Int, 3}} to Tuple{..., Int, Int, Int}
//         jl_value_t *va = jl_unwrap_unionall(last);
//         jl_value_t *va0 = jl_unwrap_vararg(va), *va1 = jl_unwrap_vararg_num(va);
//         // return same `Tuple` object for types equal to it
//         if (ntp == 1 && va0 == (jl_value_t*)jl_any_type && !va1) {
//             JL_GC_POP();
//             return (jl_value_t*)jl_anytuple_type;
//         }
//         if (va1 && jl_is_long(va1)) {
//             ssize_t nt = jl_unbox_long(va1);
//             assert(nt >= 0);
//             if (nt == 0 || !jl_has_free_typevars(va0)) {
//                 if (ntp == 1) {
//                     JL_GC_POP();
//                     return jl_tupletype_fill(nt, va0, 0, 0);
//                 }
//                 size_t i, l;
//                 p = jl_alloc_svec(ntp - 1 + nt);
//                 for (i = 0, l = ntp - 1; i < l; i++)
//                     jl_svecset(p, i, iparams[i]);
//                 l = ntp - 1 + nt;
//                 for (; i < l; i++)
//                     jl_svecset(p, i, va0);
//                 size_t np = jl_svec_len(p);
//                 jl_value_t **pp = jl_svec_data(p);
//                 jl_value_t *ndt = inst_datatype_inner(jl_anytuple_type, p, pp, np, NULL, NULL, check, nothrow);
//                 JL_GC_POP();
//                 return ndt;
//             }
//         }
//     }

//     // move array of instantiated parameters to heap; we need to keep it
//     if (p == NULL) {
//         p = jl_alloc_svec_uninit(ntp);
//         for (size_t i = 0; i < ntp; i++)
//             jl_svecset(p, i, iparams[i]);
//     }

//     // try to simplify some type parameters
//     if (check && tn != jl_type_typename) {
//         size_t i;
//         int changed = 0;
//         if (istuple) // normalization might change Tuple's, but not other types's, cacheable status
//             cacheable = 1;
//         for (i = 0; i < ntp; i++) {
//             jl_value_t *newp = normalize_unionalls(iparams[i]);
//             if (newp != iparams[i]) {
//                 iparams[i] = newp;
//                 jl_svecset(p, i, newp);
//                 changed = 1;
//             }
//             if (istuple && cacheable && !jl_is_concrete_type(newp))
//                 cacheable = 0;
//         }
//         if (changed) {
//             // If this changed something, we need to check the cache again, in
//             // case we missed the match earlier before the normalizations
//             //
//             // e.g. return inst_datatype_inner(dt, p, iparams, ntp, stack, env, 0);
//             if (cacheable) {
//                 jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
//                 if (lkup != NULL) {
//                     JL_GC_POP();
//                     return lkup;
//                 }
//             }
//             jl_value_t *stack_lkup = lookup_type_stack(stack, dt, ntp, iparams);
//             if (stack_lkup) {
//                 JL_GC_POP();
//                 return stack_lkup;
//             }
//         }
//     }

//     // acquire the write lock now that we know we need a new object
//     // since we're going to immediately leak it globally via the instantiation stack
//     if (cacheable) {
//         JL_LOCK(&typecache_lock); // Might GC
//         jl_value_t *lkup = (jl_value_t*)lookup_type(tn, iparams, ntp);
//         if (lkup != NULL) {
//             JL_UNLOCK(&typecache_lock); // Might GC
//             JL_GC_POP();
//             return lkup;
//         }
//     }

//     // create and initialize new type
//     ndt = jl_new_uninitialized_datatype();
//     ndt->isprimitivetype = dt->isprimitivetype;
//     // Usually dt won't have ismutationfree set at this point, but it is
//     // overriden for `Type`, which we handle here.
//     ndt->ismutationfree = dt->ismutationfree;
//     // associate these parameters with the new type on
//     // the stack, in case one of its field types references it.
//     top.tt = (jl_datatype_t*)ndt;
//     top.prev = stack;
//     stack = &top;
//     ndt->name = tn;
//     jl_gc_wb(ndt, ndt->name);
//     ndt->super = NULL;
//     ndt->parameters = p;
//     jl_gc_wb(ndt, ndt->parameters);
//     ndt->types = NULL; // to be filled in below
//     int invalid = 0;
//     if (istuple) {
//         ndt->types = p; // TODO: this may need to filter out certain types
//     }
//     else if (isnamedtuple) {
//         jl_value_t *names_tup = jl_svecref(p, 0);
//         jl_value_t *values_tt = jl_svecref(p, 1);
//         if (!jl_has_free_typevars(names_tup) && !jl_has_free_typevars(values_tt)) {
//             if (!jl_is_tuple(names_tup)) {
//                 if (!nothrow)
//                     jl_type_error_rt("NamedTuple", "names", (jl_value_t*)jl_anytuple_type, names_tup);
//                 invalid = 1;
//             }
//             size_t nf = jl_nfields(names_tup);
//             for (size_t i = 0; i < nf; i++) {
//                 jl_value_t *ni = jl_fieldref(names_tup, i);
//                 if (!jl_is_symbol(ni)) {
//                     if (!nothrow)
//                         jl_type_error_rt("NamedTuple", "name", (jl_value_t*)jl_symbol_type, ni);
//                     invalid = 1; break;
//                 }
//                 for (size_t j = 0; j < i; j++) {
//                     if (ni == jl_fieldref_noalloc(names_tup, j)) {
//                         if (!nothrow)
//                             jl_errorf("duplicate field name in NamedTuple: \"%s\" is not unique", jl_symbol_name((jl_sym_t*)ni));
//                         invalid = 1; break;
//                     }
//                 }
//                 if (invalid) break;
//             }
//             if (values_tt == jl_bottom_type && nf > 0) {
//                 ndt->types = jl_svec_fill(nf, jl_bottom_type);
//             }
//             else {
//                 if (!jl_is_datatype(values_tt)) {
//                     // should have been checked within `check_datatype_parameters`.
//                     jl_error("NamedTuple field type must be a tuple datatype");
//                 }
//                 if (jl_is_va_tuple((jl_datatype_t*)values_tt) || jl_nparams(values_tt) != nf) {
//                     if (!nothrow)
//                         jl_error("NamedTuple names and field types must have matching lengths");
//                     invalid = 1;
//                 }
//                 ndt->types = ((jl_datatype_t*)values_tt)->parameters;
//             }
//             jl_gc_wb(ndt, ndt->types);
//         }
//         else {
//             ndt->types = jl_emptysvec; // XXX: this is essentially always incorrect
//         }
//     }

//     if (nothrow && invalid) {
//         if (cacheable)
//             JL_UNLOCK(&typecache_lock);
//         JL_GC_POP();
//         return NULL;
//     }
//     jl_datatype_t *primarydt = ((jl_datatype_t*)jl_unwrap_unionall(tn->wrapper));
//     jl_precompute_memoized_dt(ndt, cacheable);
//     if (primarydt->layout)
//         jl_compute_field_offsets(ndt);

//     if (istuple || isnamedtuple) {
//         ndt->super = jl_any_type;
//     }
//     else if (dt->super) {
//         jl_value_t *super = inst_type_w_((jl_value_t*)dt->super, env, stack, check, nothrow);
//         if (nothrow && super == NULL) {
//             if (cacheable)
//                 JL_UNLOCK(&typecache_lock);
//             JL_GC_POP();
//             return NULL;
//         }
//         ndt->super = (jl_datatype_t *)super;
//         jl_gc_wb(ndt, ndt->super);
//     }
//     jl_svec_t *ftypes = dt->types;
//     if (ftypes == NULL)
//         ftypes = primarydt->types;
//     if (ftypes == NULL || dt->super == NULL) {
//         // in the process of creating this type definition:
//         // need to instantiate the super and types fields later
//         if (tn->partial == NULL) {
//             tn->partial = jl_alloc_vec_any(0);
//             jl_gc_wb(tn, tn->partial);
//         }
//         jl_array_ptr_1d_push(tn->partial, (jl_value_t*)ndt);
//     }
//     else if (!isnamedtuple && !istuple) {
//         assert(ftypes != jl_emptysvec || jl_field_names(ndt) == jl_emptysvec);
//         assert(ftypes == jl_emptysvec || !ndt->name->abstract);
//         if (ftypes == jl_emptysvec) {
//             ndt->types = ftypes;
//         }
//         else if (cacheable) {
//             // recursively instantiate the types of the fields
//             if (dt->types == NULL)
//                 ndt->types = jl_compute_fieldtypes(ndt, stack);
//             else
//                 ndt->types = inst_ftypes(ftypes, env, stack);
//             jl_gc_wb(ndt, ndt->types);
//         }
//     }

//     // now publish the finished result
//     // XXX: if the stack was used, this will publish in the wrong order,
//     // leading to incorrect layouts and data races (#40050: the A{T} should be
//     // an isbitstype singleton of size 0)
//     if (cacheable) {
//         if (ndt->layout == NULL && ndt->types != NULL && ndt->isconcretetype)
//             jl_compute_field_offsets(ndt);
//         jl_cache_type_(ndt);
//         JL_UNLOCK(&typecache_lock); // Might GC
//     }

//     JL_GC_POP();
//     return (jl_value_t*)ndt;
// }


// Main function for search generic method
JL_DLLEXPORT jl_method_t *jl_lookup_generic_(jl_value_t *F, jl_value_t **args, uint32_t nargs,
                                                uint32_t callsite, size_t world) {
    jl_method_t *m = NULL;

    printf("Start jl_lookup_generic_\n");

    jl_value_t *FT = jl_to_typeof(((((jl_taggedvalue_t*)((char*)(F) - sizeof(jl_taggedvalue_t)))->header) & ~(uintptr_t)15));

    printf("Here we are 2\n");                                               

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

    printf("jl_lookup_generic_ after first cache\n");

    // Search in main cache
    i = 4;
    jl_tupletype_t *tt = NULL;
    int64_t last_alloc = 0;
    jl_methtable_t *mt = NULL;
    if (i == 4) {
        // if no method was found in the associative cache, check the full cache
        // mt = jl_gf_mtable(F);
        mt = malloc(sizeof(jl_methtable_t));
        
        return NULL; //TODO: Fix it
        
        printf("jl_lookup_generic_ second cache 1\n");
        jl_array_t *leafcache = jl_atomic_load_relaxed(&mt->leafcache);
        printf("jl_lookup_generic_ second cache 2\n");
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
                    tt = arg_type_tuple(F, args, nargs);
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