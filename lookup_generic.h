#ifndef LOOKUP_GENERIC_H
#define LOOKUP_GENERIC_H

#include "julia.h"

#ifdef __cplusplus
extern "C" {
#endif

JL_DLLEXPORT jl_method_t *jl_lookup_generic_(jl_value_t *F, jl_value_t **args, 
                                            uint32_t nargs, uint32_t callsite, size_t world);

JL_DLLEXPORT jl_method_t *jl_lookup_generic_FAST(jl_value_t *F, jl_value_t **args,
                                                uint32_t nargs, uint32_t callsite, size_t world);

#ifdef __cplusplus
}
#endif

#endif // LOOKUP_GENERIC_H
