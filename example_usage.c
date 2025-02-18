#include <stdio.h>
#include <dlfcn.h>
#include "lookup_generic.h"

int main() {
    void *handle = dlopen("./lookup_generic.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    jl_method_t *(*jl_lookup_generic)(jl_svec_t *, jl_value_t *) =
        (jl_method_t *(*)(jl_svec_t *, jl_value_t *))dlsym(handle, "jl_lookup_generic_");

    if (!jl_lookup_generic) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // jl_lookup_generic can be used here
    printf("Function loaded successfully.\n");

    dlclose(handle);
    return 0;
}
