#include "visitor.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void measure_visitor(int number_of_iters)
{
    Element* e1 = new ElementA();
    Element* e2 = new ElementB();

    struct timeval tval_before, tval_after, tval_result;
    gettimeofday(&tval_before, NULL);

    for (int i = 0; i < number_of_iters; i++) {
        e1->visit(e2);
    }

    gettimeofday(&tval_after, NULL);
    timersub(&tval_after, &tval_before, &tval_result);

    printf("Time elapsed Visitor: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
}

int main(int main_argc, char** main_argv)
{
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

    measure_visitor(number_of_iters);
}