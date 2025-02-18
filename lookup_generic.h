#ifndef LOOKUP_GENERIC_H
#define LOOKUP_GENERIC_H

#include "julia.h"

#ifdef __cplusplus
extern "C" {
#endif

JL_DLLEXPORT jl_method_t *jl_lookup_generic_(jl_svec_t *types, jl_value_t *const limitto);

#ifdef __cplusplus
}
#endif

#endif // LOOKUP_GENERIC_H
