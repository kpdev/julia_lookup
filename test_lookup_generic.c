#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#include "lookup_generic.h"
#include "test_lookup_generic.h"


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

    init_mock_data_for_test(2);

    jl_value_t **args; 
    uint32_t nargs = 2;
    uint32_t callsite = 0;
    size_t world = 0; // mock for test

    create_test_args(&args, nargs);

    jl_value_t *F = malloc(sizeof(jl_value_t));
    jl_method_t *method = NULL;
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


    nargs = 2;
    create_test_args(&args, nargs);
    gettimeofday(&tval_before, NULL);

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


    nargs = 5;
    init_mock_data_for_test(nargs);
    create_test_args(&args, nargs);
    gettimeofday(&tval_before, NULL);

    count = 0;
    for (int i = 0; i < number_of_iters; i++) {
        method = jl_lookup_generic_(F, args, nargs, callsite, world);
        if (method) {
            count++;
        }
    }

    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed Julia 5D: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);




    struct Object* spaceship = get_space_object(1);
    struct Object* asteroid  = get_space_object(2);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        MultiMethodCollide<spaceship, asteroid>();
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed PP: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    struct Object* spaceship3d = get_space_object(1);
    struct Object* asteroid3d_1  = get_space_object(2);
    struct Object* asteroid3d_2  = get_space_object(2);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        MultiMethodCollide3D<spaceship3d, asteroid3d_1, asteroid3d_2>();
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed PP 3D: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    struct Object* spaceship5d = get_space_object(1);
    struct Object* asteroid5d_1  = get_space_object(2);
    struct Object* asteroid5d_2  = get_space_object(2);
    struct Object* asteroid5d_3  = get_space_object(2);
    struct Object* asteroid5d_4  = get_space_object(2);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        MultiMethodCollide5D<spaceship5d,
                             asteroid5d_1,
                             asteroid5d_2,
                             asteroid5d_3,
                             asteroid5d_4>();
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed PP 5D: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);



    struct Figure* fr = get_figure(1);
    struct Figure* ft = get_figure(2);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        MultimethodEmpty<fr>(ft);
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed PP Dispatch: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    Shape* sh_circ = get_shape(1);
    Shape* sh_rect = get_shape(2);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        sh_rect->collide(sh_rect, sh_circ);
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed Procedural VT Dispatch: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);


    ShapeSwitch* ss_circ = get_shape_switch(1);
    ShapeSwitch* ss_rect = get_shape_switch(2);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        CollideSwitch(ss_circ, ss_rect);
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed Procedural Switch Dispatch: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);



    ShapeSwitch3D* ss_circ3D = get_ShapeSwitch3D(1);
    ShapeSwitch3D* ss_rect3D = get_ShapeSwitch3D(2);
    ShapeSwitch3D* ss_trian3D = get_ShapeSwitch3D(3);

    gettimeofday(&tval_before, NULL);
    for (int i = 0; i < number_of_iters; i++) {
        CollideSwitch3D(ss_trian3D, ss_trian3D, ss_circ3D);
        // CollideSwitch3D(ss_rect3D, ss_rect3D, ss_circ3D);
    }
    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed Procedural Switch Dispatch 3D: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

    return 0;
}
