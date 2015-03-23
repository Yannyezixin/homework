#include "../../../vendor/unit.h"
#include "expre.h"
#include <string.h>
#include <math.h>

int tests_run = 0;

static char *test_infix_to_postfix()
{
    sq_stack sq;
    char *infix = "a+b*c+(d*e+f)*g", *postfix = "abc*+de*f+g*+";

    assert("Init sq_stack failed.", sq_stack_init(&sq, 30, 5) == SQ_OK);
    assert("Infix to Postfix failed.", strcmp(infix_to_postfix(infix, sq),postfix) == 0);
    infix = "a+b-c", postfix = "ab+c-";
    assert("Infix to Postfix failed.", strcmp(infix_to_postfix(infix, sq),postfix) == 0);
    infix = "(a+b)*g+(c-b)*d", postfix = "ab+g*cb-d*+";
    assert("Infix to Postfix failed.", strcmp(infix_to_postfix(infix, sq),postfix) == 0);
    infix = " 100 + 2 - 9 +( 10 - 2 )* 9 ", postfix = " 100  2 + 9 - 10  2 - 9 *+";
    assert("Infix to Postfix failed.", strcmp(infix_to_postfix(infix, sq),postfix) == 0);

    return OK;
}

static char *test_cal_postfix()
{
    float stack[1000];
    char *postfix = "100 2 10 + -";

    assert("Cal postfix error.", fabs(cal_postfix(postfix, stack) - 88) < 0.00001);
    postfix = "100 2 + 9 - 10 2 - 9 *+";
    assert("Cal postfix error.", fabs(cal_postfix(postfix, stack) - 165) < 0.00001);

    return OK;
}

static char *run()
{
    run_test(test_infix_to_postfix);
    run_test(test_cal_postfix);
    return OK;
}

TEST_MAIN
