#include "../../vendor/unit.h"

#include "sq_stack.h"

int tests_run = 0;

void print_sq_stack(char *message, sq_stack *sq)
{
    int i;
    printf("%s : sq_stack ( ", message);
    for (i = 0; i < sq->top; i++) {
        printf("%c ", sq->elem[i]);
    }
    printf(")\n");
}

static char *test_sq_push()
{
    sq_stack sq;
    elem_type e;

    assert("Init sequence stack failed.", sq_stack_init(&sq, 3, 4) == SQ_OK);
    print_sq_stack("Init sequence stack",&sq);
    assert("Push a to sequence stack failed.", sq_stack_push(&sq, 'a') == SQ_OK);
    assert("Get top of sequence stack failed.", sq_stack_top(&sq, &e) == SQ_OK);
    assert("Push a to sequence stack failed.", e == 'a');

    assert("Push b to sequence stack failed.", sq_stack_push(&sq, 'b') == SQ_OK);
    assert("Push c to sequence stack failed.", sq_stack_push(&sq, 'c') == SQ_OK);
    assert("Push d to sequence stack failed.", sq_stack_push(&sq, 'd') == SQ_OK);
    print_sq_stack("Push a b c d to sequence stack", &sq);
    assert("Get top of sequence stack failed.", sq_stack_top(&sq, &e) == SQ_OK);
    assert("Push d to sequence stack failed.", e == 'd');


    return OK;
}

static char *test_sq_pop()
{
    sq_stack sq;
    elem_type e;

    assert("Init sequence stack failed.", sq_stack_init(&sq, 3, 4) == SQ_OK);
    assert("Push a to sequence stack failed.", sq_stack_push(&sq, 'a') == SQ_OK);
    assert("Push b to sequence stack failed.", sq_stack_push(&sq, 'b') == SQ_OK);
    assert("Push c to sequence stack failed.", sq_stack_push(&sq, 'c') == SQ_OK);
    assert("Push d to sequence stack failed.", sq_stack_push(&sq, 'd') == SQ_OK);

    assert("Pop d of sequence stack failed.", sq_stack_pop(&sq, &e) == SQ_OK);
    print_sq_stack("Pop d from sequence stack", &sq);
    assert("Pop d from sequence stack failed.", e == 'd');
    assert("Get top of sequence stack failed.", sq_stack_top(&sq, &e) == SQ_OK);
    assert("Pop d from sequence stack failed.", e == 'c');
}

static char *test_sq_clear()
{
    sq_stack sq;
    elem_type e;

    assert("Init sequence stack failed.", sq_stack_init(&sq, 3, 4) == SQ_OK);
    assert("Push a to sequence stack failed.", sq_stack_push(&sq, 'a') == SQ_OK);
    assert("Push b to sequence stack failed.", sq_stack_push(&sq, 'b') == SQ_OK);
    assert("Push c to sequence stack failed.", sq_stack_push(&sq, 'c') == SQ_OK);
    assert("Push d to sequence stack failed.", sq_stack_push(&sq, 'd') == SQ_OK);
    sq_stack_clear(&sq);
    print_sq_stack("clear sequence stack", &sq);
    assert("Clear sequence stack failed, sq not empty", sq_stack_empty(sq) == SQ_OK);
}

static char *test_sq_destroy()
{
    sq_stack sq;
    elem_type e;

    assert("Init sequence stack failed.", sq_stack_init(&sq, 3, 4) == SQ_OK);
    assert("Push a to sequence stack failed.", sq_stack_push(&sq, 'a') == SQ_OK);
    assert("Push b to sequence stack failed.", sq_stack_push(&sq, 'b') == SQ_OK);
    assert("Push c to sequence stack failed.", sq_stack_push(&sq, 'c') == SQ_OK);
    assert("Push d to sequence stack failed.", sq_stack_push(&sq, 'd') == SQ_OK);
    assert("Destroy to sequence stack failed.", sq_stack_destroy(&sq) == SQ_OK);
    print_sq_stack("detroy sequence stack", &sq);
    assert("Destroy sequence stack failed, sq not empty", sq_stack_empty(sq) == SQ_OK);
}

static char *run()
{
    run_test(test_sq_push);
    run_test(test_sq_pop);
    run_test(test_sq_clear);
    run_test(test_sq_destroy);

    return OK;
}

TEST_MAIN
