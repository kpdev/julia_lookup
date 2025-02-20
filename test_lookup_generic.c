#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "lookup_generic.h"
#include "test_lookup_generic.h"
#include "ppp-mm-tag-disp/figure-rectangle.h"
#include "ppp-mm-tag-disp/figure-triangle.h"
#include "ppp-mm-tag-disp/multimethod-empty.h"


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

    volatile int count = 0;
    for (int i = 0; i < number_of_iters; i++) {
        count++;
    }

    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed empty loop: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    gettimeofday(&tval_before, NULL);

    jl_method_t *method = NULL;
    count = 0;
    for (int i = 0; i < number_of_iters; i++) {
        method = jl_lookup_generic_(F, args, nargs, callsite, world);
        if (method) {
            count++;
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
