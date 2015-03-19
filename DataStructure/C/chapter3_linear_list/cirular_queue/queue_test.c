#include "../../vendor/unit.h"
#include <stdlib.h>

#include "queue.h"

int tests_run = 0;

void print_queue(char *message, sq_queue sq)
{
    printf("%s : queue ( ", message);
    while(sq.front != sq.rear) {
        printf("%c ", sq.base[sq.front]);
        sq.front = (sq.front + 1) % sq.maxsize;
    }

    printf(")\n");
}

static char *test_queue_insert()
{
    sq_queue sq;
    elem_type e;
    int size = 5;

    assert("Init queue failed.", queue_init(&sq, size) == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'a') == QUEUE_OK);
    assert("queue length not true.", queue_length(sq) == 1);
    assert("Insert queue failed.", queue_insert(&sq, 'b') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'c') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'd') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'f') == QUEUE_FALSE);
    assert("queue length not true.", queue_length(sq) == 4);
    print_queue("Insert", sq);

    return OK;
}

static char *test_queue_get_head()
{
    sq_queue sq;
    elem_type e;
    int size = 5;

    assert("Init queue failed.", queue_init(&sq, size) == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'a') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'b') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'c') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'd') == QUEUE_OK);
    assert("get head queue failed.", queue_get_head(&sq, &e) == QUEUE_OK);
    assert("get 'a' from queue head failed.", e == 'a');
    print_queue("Get head", sq);

    return OK;
}

static char *test_queue_delete()
{
    sq_queue sq;
    elem_type e;
    int size = 5;

    assert("Init queue failed.", queue_init(&sq, size) == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'a') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'b') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'c') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'd') == QUEUE_OK);
    assert("Insert queue failed.", queue_insert(&sq, 'f') == QUEUE_FALSE);
    assert("Delete queue failed.", queue_delete(&sq, &e) == QUEUE_OK);
    assert("Delete d from queue failed.", e == 'a');
    print_queue("Delete a", sq);
    assert("Delete queue failed.", queue_delete(&sq, &e) == QUEUE_OK);
    assert("Delete b from queue failed.", e == 'b');
    print_queue("Delete b", sq);
    assert("Delete queue failed.", queue_delete(&sq, &e) == QUEUE_OK);
    assert("Delete c from queue failed.", e == 'c');
    print_queue("Delete c", sq);

    assert("empty queue failed.", queue_empty(&sq) == QUEUE_FALSE);
    assert("destory queue failed.", queue_destroy(&sq) == QUEUE_OK);
    assert("destory queue failed, not empty.", queue_empty(&sq) == QUEUE_TRUE);
    print_queue("Destroy queue", sq);


    return OK;
}

static char *run()
{
    run_test(test_queue_insert);
    run_test(test_queue_get_head);
    run_test(test_queue_delete);

    return OK;
}

TEST_MAIN
