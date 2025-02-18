#include "julia.h"
// #include "gf.h" // For generic functions

// define a copy of exported data
#define jl_max_tags 64
jl_datatype_t *jl_small_typeof[(jl_max_tags << 4) / sizeof(void*)]; // 16-bit aligned, like the GC
jl_typename_t* jl_tuple_typename;
_Atomic(size_t) jl_world_counter = 1;


//Search in cache
static jl_method_t *jl_lookup_cache(jl_svec_t *types, jl_value_t *limitto) {
    // TDB
    if (types && jl_is_tuple(types)) {
        // Add logic
        return NULL;
    }
    return NULL;
}

// Search by type
static jl_method_t *jl_match_method(uintptr_t world, jl_svec_t *types, jl_value_t *limitto, int cache) {
    // TDB
    if (types && jl_is_tuple(types)) {
        // Add logic
        return NULL;
    }
    return NULL;
}

// Main function for search generic method
JL_DLLEXPORT jl_method_t *jl_lookup_generic_(jl_svec_t *types, jl_value_t *const limitto) {
    jl_method_t *m = NULL;

    if (types == NULL)
        return NULL;

    // Check types
    if (jl_is_type(types)) {
        m = jl_lookup_cache(types, limitto);
        if (m != NULL)
            return m;
    }

    // Doing full search
    return jl_match_method(jl_world_counter, types, limitto, 0);
}