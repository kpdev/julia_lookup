#include <stdio.h>
#include "lookup_generic.h"

int main() {
    // Init types & limitto
    jl_svec_t *types = NULL;
    jl_value_t *limitto = NULL;

    // Invoke
    jl_method_t *method = jl_lookup_generic_(types, limitto);

    if (method) {
        printf("Method found!\n");
    } else {
        printf("No method found.\n");
    }

    return 0;
}