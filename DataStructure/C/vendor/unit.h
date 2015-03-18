#ifndef UNIT_H
#define UNIT_H

#define assert(message, test) \
    do { \
        if (!test) \
            return message; \
    } while(0)

#define run_test(test) \
    do { \
        char *message = test(); \
        tests_run++; \
        if (message) \
            return message; \
    } while(0)

#define OK NULL

#include <stdio.h>

extern int tests_run;

#define TEST_MAIN int main(void) \
{\
    char *result = run(); \
    if (0 != result) \
        printf("%s\n", result); \
    else \
        printf("All test passed.\n"); \
    printf("Total %d test(s) runned.\n", tests_run); \
    return 0; \
}

#endif
