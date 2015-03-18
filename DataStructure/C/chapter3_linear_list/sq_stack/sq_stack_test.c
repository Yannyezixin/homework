#include "../../vendor/unit.h"

#include "sq_stack.h"

int tests_run = 0;

static char *test_list_push()
{
    sq_stack sq;

    assert("Init sequence stack failed.", sq_stack_init(&sq, 1, 4) == SQ_OK);
    assert("Push a to sequence stack failed.", sq_stack_push(&sq, 'a') == SQ_OK);
    assert("Push b to sequence stack failed.", sq_stack_push(&sq, 'b') == SQ_OK);

    return OK;
}

static char *run()
{
    run_test(test_list_push);

    return OK;
}

TEST_MAIN
