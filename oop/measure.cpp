#include "visitor.h"
#include "../util.h"
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

START_TEST_FUNC(measure_visitor)

    volatile int i_vol = 0;

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        Element* e1 = get_element(r1);
        Element* e2 = get_element(r2);
        i_vol++;
        (void)e1;
        (void)e2;
    END_EMPTY_LOOP(measure_visitor)

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        Element* e1 = get_element(r1);
        Element* e2 = get_element(r2);
        e1->visit(e2);
    END_MAIN_LOOP()

END_TEST_FUNC(measure_visitor)

// void measure_visitor(int number_of_iters)
// {
//     Element* e1 = get_element(1);
//     Element* e2 = get_element(2);

//     struct timeval tval_before, tval_after, tval_result;
//     gettimeofday(&tval_before, NULL);

//     for (int i = 0; i < number_of_iters; i++) {
//         e1->visit(e2);
//     }

//     gettimeofday(&tval_after, NULL);
//     timersub(&tval_after, &tval_before, &tval_result);

//     printf("Time elapsed Visitor: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
// }

// void measure_visitor3d(int number_of_iters)
// {
//     Shape3D* e1 = get_shape3d(1);
//     Shape3D* e2 = get_shape3d(1);
//     Shape3D* e3 = get_shape3d(2);

//     struct timeval tval_before, tval_after, tval_result;
//     gettimeofday(&tval_before, NULL);

//     for (int i = 0; i < number_of_iters; i++) {
//         collide3D(*e1, *e2, *e3);
//     }

//     gettimeofday(&tval_after, NULL);
//     timersub(&tval_after, &tval_before, &tval_result);

//     printf("Time elapsed Visitor3D: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
// }

START_TEST_FUNC(measure_visitor3d)

    volatile int i_vol = 0;

    START_LOOP()
        int r1 = 1 + rand() % 2;
        int r2 = 1 + rand() % 2;
        int r3 = 1 + rand() % 2;
        Shape3D* e1 = get_shape3d(r1);
        Shape3D* e2 = get_shape3d(r2);
        Shape3D* e3 = get_shape3d(r3);
        (void)e1;
        (void)e2;
        (void)e3;
        i_vol++;
    END_EMPTY_LOOP(measure_visitor3d)

    START_LOOP()
        int r1 = 1 + rand() % 3;
        int r2 = 1 + rand() % 3;
        int r3 = 1 + rand() % 3;
        Shape3D* e1 = get_shape3d(r1);
        Shape3D* e2 = get_shape3d(r2);
        Shape3D* e3 = get_shape3d(r3);
        e1->collide(e2, e3);
    END_MAIN_LOOP()

END_TEST_FUNC(measure_visitor3d)


int main(int main_argc, char** main_argv)
{
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
        test_measure_visitor(number_of_iters);
        test_measure_visitor3d(number_of_iters);
    }
}
