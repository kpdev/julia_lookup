#define TEST_FUNC_NAME(Name) test_ ## Name

#define START_TEST_FUNC(Name) \
void TEST_FUNC_NAME(Name)(const int number_of_iters) \
{ \
    struct timeval tval_before, tval_after, tval_result, \
                    tval_empty_result, tval_delta;

#define END_TEST_FUNC(Name) \
printf(#Name " Main: %ld.%06ld\n", \
    (long int)tval_result.tv_sec, \
    (long int)tval_result.tv_usec); \
timersub(&tval_result, &tval_empty_result, &tval_delta); \
printf(#Name ": %ld.%06ld\n", \
    (long int)tval_delta.tv_sec, \
    (long int)tval_delta.tv_usec); \
}

#define DEF_TEST_FUNC(Name, Body) \
START_TEST_FUNC(Name) \
Body \
END_TEST_FUNC(Name)

#define START_LOOP() \
srand(1); \
gettimeofday(&tval_before, NULL); \
for (int i = 0; i < number_of_iters; i++) {

#define END_LOOP(tval_res_name) \
} \
gettimeofday(&tval_after, NULL); \
timersub(&tval_after, &tval_before, &tval_res_name);

#define END_MAIN_LOOP() \
END_LOOP(tval_result)

#define END_EMPTY_LOOP(Name) \
END_LOOP(tval_empty_result) \
printf(#Name " Empty: %ld.%06ld\n", \
    (long int)tval_empty_result.tv_sec, \
    (long int)tval_empty_result.tv_usec);

    #define START_TEST_FUNC_WITH_PARAM(Name) \
void TEST_FUNC_NAME(Name)(const int number_of_iters, const int param) \
{ \
    struct timeval tval_before, tval_after, tval_result, \
                    tval_empty_result, tval_delta;

#define END_TEST_FUNC_WITH_PARAM(Name) \
printf(#Name "[%d] Main: %ld.%06ld\n", \
    param, \
    (long int)tval_result.tv_sec, \
    (long int)tval_result.tv_usec); \
timersub(&tval_result, &tval_empty_result, &tval_delta); \
printf(#Name "[%d]: %ld.%06ld\n", \
    param, \
    (long int)tval_delta.tv_sec, \
    (long int)tval_delta.tv_usec); \
}

#define END_EMPTY_LOOP_WITH_PARAM(Name) \
END_LOOP(tval_empty_result) \
printf(#Name "[%d] Empty: %ld.%06ld\n", \
    param, \
    (long int)tval_empty_result.tv_sec, \
    (long int)tval_empty_result.tv_usec);
