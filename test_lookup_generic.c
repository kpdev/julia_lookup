#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "julia.h"
#include "lookup_generic.h"

#include "ppp-mm-tag-disp/figure-rectangle.h"
#include "ppp-mm-tag-disp/figure-triangle.h"
#include "ppp-mm-tag-disp/multimethod-empty.h"


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
            (*args)[i] = (jl_value_t *)jl_int32_type; // Первый аргумент: Int32
        } else if (i == 1) {
            (*args)[i] = (jl_value_t *)jl_float64_type; // Второй аргумент: Float64
        } else {
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

struct Spaceship{};
struct Asteroid{};
struct Object{}< struct Spaceship; struct Asteroid; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>() {}
void MultiMethodCollide<struct Object.Spaceship* f1, struct Object.Asteroid* f2>() {}

extern jl_methtable_t* mt_mock_data;
extern jl_array_t* jl_an_empty_vec_any_mock_data;
extern jl_datatype_t* jl_typemap_level_type_mock_data;

void init_mock_data_for_test()
{
    mt_mock_data = malloc(sizeof(jl_methtable_t));
    mt_mock_data->leafcache = malloc(sizeof(jl_array_t));
    mt_mock_data->cache = malloc(sizeof(jl_typemap_entry_t));
    ((jl_typemap_entry_t*)mt_mock_data->cache)->sig = malloc(sizeof(jl_tuple_type));
    ((jl_typemap_entry_t*)mt_mock_data->cache)->sig->parameters = malloc(sizeof(jl_svec_t));
    ((jl_typemap_entry_t*)mt_mock_data->cache)->sig->parameters->length = 2;

    jl_an_empty_vec_any_mock_data = malloc(sizeof(jl_array_t));
    jl_typemap_level_type_mock_data = malloc(sizeof(jl_datatype_t));
}

int main(int main_argc, char** main_argv) {

    if (main_argc != 2) {
        printf("ERROR: Command line: <program> <number_of_iters>\n");
        exit(EXIT_FAILURE);
    }

    const int number_of_iters = atoi(main_argv[1]);
    printf("number_of_iters = %d\n", number_of_iters);
    if (number_of_iters <=0) {
        printf("ERROR: number_of_iters should be >= 0\n");
        exit(EXIT_FAILURE);
    }

    init_mock_data_for_test();

    jl_value_t **args; 
    uint32_t nargs = 2;
    uint32_t callsite = 0;
    size_t world = 0; // mock for test

    create_test_args(&args, nargs);

    jl_value_t *F = malloc(sizeof(jl_value_t));

    if (F == NULL) {
        printf("F is NULL\n");
    }

    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);

    jl_method_t *method = NULL;
    for (int i = 0; i < number_of_iters; i++) {
        method = jl_lookup_generic_(F, args, nargs, callsite, world);
        if (method) {
            printf("%d\n", (int)method->name->hash);
        }
    }

    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed Julia: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    struct Object.Spaceship spaceship;
    struct Object.Asteroid asteroid;
    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        MultiMethodCollide<&spaceship, &asteroid>();
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed PP: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    struct Figure.trian ft;
    struct Figure.rect fr;

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        MultimethodEmpty<&fr>(&ft);
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed PP Dispatch: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    return 0;
}
