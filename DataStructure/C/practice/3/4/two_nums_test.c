#include "../../../vendor/unit.h"
#include <stdlib.h>
#include "two_nums.h"

int tests_run = 0;

static char *test_two_nums()
{
    pair p;
    int arr[10] = {4, 3, 11, 10, 20, 100, 99, 1, 0, 1000};

    assert("sum = 30, test false.", two_nums(arr, 10, 30, &p) == P_OK);
    assert("find a pair of 30 error.", (30 == p.x + p.y));
    assert("sum = 100, test false.", two_nums(arr, 10, 100, &p) == P_OK);
    assert("find a pair of 30 error.", (100 == p.x + p.y));
    assert("sum = 1020, test false.", two_nums(arr, 10, 1020, &p) == P_OK);
    assert("find a pair of 1020 error.", (1020 == p.x + p.y));
    assert("sum = 8888, test false.", two_nums(arr, 10, 8888, &p) == P_FALSE);
    assert("sum = 8, test false.", two_nums(arr, 10, 8, &p) == P_FALSE);

    return OK;
}

static char *run()
{
    run_test(test_two_nums);
    return OK;
}

TEST_MAIN
