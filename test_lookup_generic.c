#include <stdio.h>
#include "julia.h"
// #include "julia_internal.h"
#include "lookup_generic.h"

struct _jl_value_t
{

};


static int8_t jl_cachearg_offset(jl_methtable_t *mt)
{
    return mt->offs;
}


jl_typemap_entry_t *jl_typemap_level_assoc_exact(jl_typemap_level_t *cache, jl_value_t *arg1, jl_value_t **args, size_t n, int8_t offs, size_t world);
jl_typemap_entry_t *jl_typemap_entry_assoc_exact(jl_typemap_entry_t *mn, jl_value_t *arg1, jl_value_t **args, size_t n, size_t world);
jl_typemap_entry_t *jl_typemap_assoc_exact(
    jl_typemap_t *ml_or_cache JL_PROPAGATES_ROOT,
    jl_value_t *arg1, jl_value_t **args, size_t n, int8_t offs, size_t world)
{
    // NOTE: This function is a huge performance hot spot!!
    if (jl_typeof(ml_or_cache) == (jl_value_t *)jl_typemap_entry_type) {
        // return jl_typemap_entry_assoc_exact(
        //     (jl_typemap_entry_t *)ml_or_cache, arg1, args, n, world);
        return NULL;
    }
    else if (jl_typeof(ml_or_cache) == (jl_value_t*)jl_typemap_level_type) {
        // return jl_typemap_level_assoc_exact(
        //     (jl_typemap_level_t *)ml_or_cache, arg1, args, n, offs, world);
        return NULL;
    }
    return NULL;
}


void create_test_args(jl_value_t ***args, uint32_t nargs) {
    // Выделяем память для массива указателей
    *args = (jl_value_t **)malloc(nargs * sizeof(jl_value_t *));

    // jl_value_t *float64_value = jl_box_float64(0.0); // Create a Float64 value
    // jl_value_t *float64_type = jl_typeof(float64_value); // Get the type of the value


    // Заполняем массив примерными значениями
    for (uint32_t i = 0; i < nargs; i++) {
        if (i == 0) {
            printf("111\n");
            (*args)[i] = (jl_value_t *)jl_int32_type; // Первый аргумент: Int32
        } else if (i == 1) {
            printf("222\n");
            (*args)[i] = (jl_value_t *)jl_float64_type; // Второй аргумент: Float64
        } else {
            printf("333\n");
            (*args)[i] = (jl_value_t *)jl_any_type; // Дополнительные аргументы: Any
        }
    }
}

// Define a simple function in C that will be wrapped as a Julia function
static jl_value_t *my_custom_function(jl_value_t **args, uint32_t nargs) {
    if (nargs != 2) {
        printf("OUCH\n");
        return NULL;
    }
    jl_value_t *x = args[0];
    jl_value_t *y = args[1];
    return jl_box_int32(jl_unbox_int32(x) + jl_unbox_int32(y));
}

static int my_c_function(int x, int y) {
    return x + y;
}

int main() {
    // 
    printf("Start main\n");

    jl_value_t **args; 
    uint32_t nargs = 2;
    uint32_t callsite = 0;
    size_t world = 0; // test purpose

    create_test_args(&args, nargs);

    // jl_init();
    // jl_eval_string("using Base");
    printf("Start F\n");
    jl_value_t *F = malloc(sizeof(jl_value_t));
    // jl_value_t *F = jl_eval_string("+");
    // jl_value_t *F = jl_get_global(jl_base_module, jl_symbol("+"));

    // Wrap the C function as a Julia function
    // jl_function_t *F = jl_cfunction(
    //     (void *)my_custom_function, // Pointer to the C function
    //     args,              // Return type
    //     "my_custom_function"        // Name of the function
    // );

    // void *cfunc_ptr = (void *)my_c_function;
    // jl_value_t *F = jl_box_voidpointer(cfunc_ptr);


    printf("After F\n");
    if (F == NULL) {
        printf("F is NULL\n");
    }



    // Invoke
    // JL_DLLEXPORT jl_method_t *jl_lookup_generic_(jl_value_t *F, jl_value_t **args, 
    //     uint32_t nargs, uint32_t callsite, size_t world);
    jl_method_t *method = jl_lookup_generic_(F, args, nargs, callsite, world);

    if (method) {
        printf("Method found!\n");
    } else {
        printf("No method found.\n");
    }

    return 0;
}