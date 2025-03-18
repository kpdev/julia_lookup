#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef BUILD_JULIA
#include "lookup_generic.h"
#endif

#include "test_lookup_generic.h"
#include "util.h"


START_TEST_FUNC(PP2)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        struct Object* spaceship = get_space_object(r1);
        struct Object* asteroid  = get_space_object(r2);
        (void)spaceship;
        (void)asteroid;
    END_EMPTY_LOOP(PP2)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        struct Object* spaceship = get_space_object(r1);
        struct Object* asteroid  = get_space_object(r2);
        MultiMethodCollide<spaceship, asteroid>();
    END_MAIN_LOOP()

END_TEST_FUNC(PP2)


START_TEST_FUNC(PP3)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        int r3 = 1 + rand() % 2;
        struct Object* spaceship3d = get_space_object(r1);
        struct Object* asteroid3d_1  = get_space_object(r2);
        struct Object* asteroid3d_2  = get_space_object(r3);
        (void)spaceship3d;
        (void)asteroid3d_1;
        (void)asteroid3d_2;
    END_EMPTY_LOOP(PP3)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        int r3 = 1 + rand() % 2;
        struct Object* spaceship3d = get_space_object(r1);
        struct Object* asteroid3d_1  = get_space_object(r2);
        struct Object* asteroid3d_2  = get_space_object(r3);
        MultiMethodCollide3D<spaceship3d, asteroid3d_1, asteroid3d_2>();
    END_MAIN_LOOP()

END_TEST_FUNC(PP3)


START_TEST_FUNC(PP5)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        int r3 = 1 + rand() % 2;
        int r4 = 1 + rand() % 2;
        int r5 = 1 + rand() % 2;
        struct Object* spaceship5d = get_space_object(r1);
        struct Object* asteroid5d_1  = get_space_object(r2);
        struct Object* asteroid5d_2  = get_space_object(r3);
        struct Object* asteroid5d_3  = get_space_object(r4);
        struct Object* asteroid5d_4  = get_space_object(r5);
        (void)spaceship5d; (void)asteroid5d_1;
        (void)asteroid5d_2; (void)asteroid5d_3; (void)asteroid5d_4;
    END_EMPTY_LOOP(PP5)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        int r3 = 1 + rand() % 2;
        int r4 = 1 + rand() % 2;
        int r5 = 1 + rand() % 2;
        struct Object* spaceship5d = get_space_object(r1);
        struct Object* asteroid5d_1  = get_space_object(r2);
        struct Object* asteroid5d_2  = get_space_object(r3);
        struct Object* asteroid5d_3  = get_space_object(r4);
        struct Object* asteroid5d_4  = get_space_object(r5);
        (void)spaceship5d; (void)asteroid5d_1;
        (void)asteroid5d_2; (void)asteroid5d_3; (void)asteroid5d_4;
        MultiMethodCollide5D<spaceship5d, asteroid5d_1, asteroid5d_2, asteroid5d_3, asteroid5d_4>();
    END_MAIN_LOOP()

END_TEST_FUNC(PP5)


DEF_TEST_FUNC(PPDispatch,

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        struct Figure* fr = get_figure(r1);
        struct Figure* ft = get_figure(r2);
        (void)fr; (void)ft;
    END_EMPTY_LOOP(PPDispatch)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        struct Figure* fr = get_figure(r1);
        struct Figure* ft = get_figure(r2);
        (void)fr; (void)ft;
        MultimethodEmpty<fr>(ft);
    END_MAIN_LOOP()
)


DEF_TEST_FUNC(ProcedVTable,

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        Shape* sh_circ = get_shape(r1);
        Shape* sh_rect = get_shape(r2);
        (void)sh_circ; (void)sh_rect;
    END_EMPTY_LOOP(ProcedVTable)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        Shape* sh_circ = get_shape(r1);
        Shape* sh_rect = get_shape(r2);
        (void)sh_circ; (void)sh_rect;
        sh_rect->collide(sh_rect, sh_circ);
    END_MAIN_LOOP()
)

DEF_TEST_FUNC(ProcedSwitchX2,

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        ShapeSwitch* ss_circ = get_shape_switch(r1);
        ShapeSwitch* ss_rect = get_shape_switch(r2);
        (void)ss_circ; (void)ss_rect;
    END_EMPTY_LOOP(ProcedSwitchX2)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        ShapeSwitch* ss_circ = get_shape_switch(r1);
        ShapeSwitch* ss_rect = get_shape_switch(r2);
        (void)ss_circ; (void)ss_rect;
        CollideSwitch(ss_circ, ss_rect);
    END_MAIN_LOOP()
)

DEF_TEST_FUNC(ProcedSwitchX3,

    START_LOOP()
        int r1 = 1 + rand() % 3;
        int r2 = 1 + rand() % 3;
        int r3 = 1 + rand() % 3;
        ShapeSwitch3D* ss_circ3D = get_ShapeSwitch3D(r1);
        ShapeSwitch3D* ss_rect3D = get_ShapeSwitch3D(r2);
        ShapeSwitch3D* ss_trian3D = get_ShapeSwitch3D(r3);
        (void)ss_circ3D; (void)ss_rect3D; (void)ss_trian3D;
    END_EMPTY_LOOP(ProcedSwitchX3)

    START_LOOP()
        int r1 = 1 + rand() % 3;
        int r2 = 1 + rand() % 3;
        int r3 = 1 + rand() % 3;
        ShapeSwitch3D* ss_circ3D = get_ShapeSwitch3D(r1);
        ShapeSwitch3D* ss_rect3D = get_ShapeSwitch3D(r2);
        ShapeSwitch3D* ss_trian3D = get_ShapeSwitch3D(r3);
        (void)ss_circ3D; (void)ss_rect3D; (void)ss_trian3D;
        CollideSwitch3D(ss_trian3D, ss_trian3D, ss_circ3D);
    END_MAIN_LOOP()
)

DEF_TEST_FUNC(ProcedSwitchX10,

    START_LOOP()
        int r1 = rand() % 10;
        int r2 = rand() % 10;
        struct Obj* h_obj = get_obj((ObjEnum)r1);
        struct Obj* i_obj = get_obj((ObjEnum)r2);
        (void)h_obj; (void)i_obj;
    END_EMPTY_LOOP(ProcedSwitchX10)

    START_LOOP()
        int r1 = rand() % 10;
        int r2 = rand() % 10;
        struct Obj* h_obj = get_obj((ObjEnum)r1);
        struct Obj* i_obj = get_obj((ObjEnum)r2);
        (void)h_obj; (void)i_obj;
        CollideSwitchX10(h_obj, i_obj);
    END_MAIN_LOOP()
)


#ifdef BUILD_JULIA
START_TEST_FUNC_WITH_PARAM(Julia)

    jl_value_t **args; 
    uint32_t nargs = param;
    uint32_t callsite = 0;
    size_t world = 0; // mock for test

    init_mock_data_for_test(nargs);
    create_test_args(&args, nargs);

    jl_value_t *F = malloc(sizeof(jl_value_t));
    jl_method_t *method = NULL;
    if (F == NULL) {
        exit(EXIT_FAILURE);
    }

    volatile int count = 0;

    START_LOOP()
        count++;
    END_EMPTY_LOOP_WITH_PARAM(Julia)

    START_LOOP()
        method = jl_lookup_generic_(F, args, nargs, callsite, world);
        if (method) {
            count++;
        }
    END_MAIN_LOOP()

END_TEST_FUNC_WITH_PARAM(Julia)
#endif


int main(int main_argc, char** main_argv) {

    if (main_argc != 3) {
        printf("ERROR: Command line: <program> <number_of_iters> <repetition>\n");
        exit(EXIT_FAILURE);
    }

    const int number_of_iters = atoi(main_argv[1]);
    printf("number_of_iters = %d\n", number_of_iters);
    if (number_of_iters <=0) {
        printf("ERROR: number_of_iters should be >= 0\n");
        exit(EXIT_FAILURE);
    }

    const int repetitions = atoi(main_argv[2]);
    printf("repetitions = %d\n", repetitions);
    if (repetitions <=0) {
        printf("ERROR: repetitions should be >= 0\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < repetitions; ++i)
    {
        printf("Rep: %d\n", i);
        test_PP2(number_of_iters);
        test_PP3(number_of_iters);
        test_PP5(number_of_iters);
        test_PPDispatch(number_of_iters);
        test_ProcedVTable(number_of_iters);
        test_ProcedSwitchX2(number_of_iters);
        test_ProcedSwitchX3(number_of_iters);
        test_ProcedSwitchX10(number_of_iters);

#ifdef BUILD_JULIA
        test_Julia(number_of_iters, 2);
        test_Julia(number_of_iters, 3);
        test_Julia(number_of_iters, 5);
#endif
    }


    return 0;
}
