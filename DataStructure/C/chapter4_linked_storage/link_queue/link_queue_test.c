#include "../../vendor/unit.h"
#include <stdlib.h>
#include "link_queue.h"

int tests_run = 0;

void print_lq(char *message, lqueue lq)
{
    printf("%s : link queue ( ", message);
    lq.front = lq.front->next;
    while(NULL != lq.front) {
        printf("%c ", lq.front->data);
        lq.front = lq.front->next;
    }
    printf(")\n");
}

static char *test_queue_append()
{
    lqueue lq;
    elem_type e;

    assert("Init link queue failed.", lq_init(&lq) == LQ_OK);
    assert("Length of link queue false.", lq_length(lq) == 0);
    assert("Append a to link queue failed.", lq_append(&lq, 'a') == LQ_OK);
    assert("Append b to link queue failed.", lq_append(&lq, 'b') == LQ_OK);
    assert("Append c to link queue failed.", lq_append(&lq, 'c') == LQ_OK);
    assert("Append d to link queue failed.", lq_append(&lq, 'd') == LQ_OK);
    assert("Length of link queue false.", lq_length(lq) == 4);

    return OK;
}

static char *test_queue_get_head()
{
    lqueue lq;
    elem_type e;

    assert("Init link queue failed.", lq_init(&lq) == LQ_OK);
    assert("Append a to link queue failed.", lq_append(&lq, 'a') == LQ_OK);
    assert("Append b to link queue failed.", lq_append(&lq, 'b') == LQ_OK);
    assert("Append c to link queue failed.", lq_append(&lq, 'c') == LQ_OK);
    assert("Append d to link queue failed.", lq_append(&lq, 'd') == LQ_OK);
    assert("Get head of link queue failed.", (lq_get_head(lq, &e) == LQ_OK && e == 'a'));

    return OK;
}

static char *test_queue_delete()
{
    lqueue lq;
    elem_type e;

    assert("Init link queue failed.", lq_init(&lq) == LQ_OK);
    assert("Append a to link queue failed.", lq_append(&lq, 'a') == LQ_OK);
    assert("Append b to link queue failed.", lq_append(&lq, 'b') == LQ_OK);
    assert("Append c to link queue failed.", lq_append(&lq, 'c') == LQ_OK);
    assert("Append d to link queue failed.", lq_append(&lq, 'd') == LQ_OK);
    assert("Delete a from link queue failed.", (lq_delete(&lq, &e) == LQ_OK && e == 'a'));
    assert("Delete b from link queue failed.", (lq_delete(&lq, &e) == LQ_OK && e == 'b'));

    return OK;
}

static char *test_queue_detroy()
{
    lqueue lq;
    elem_type e;

    assert("Init link queue failed.", lq_init(&lq) == LQ_OK);
    assert("Append a to link queue failed.", lq_append(&lq, 'a') == LQ_OK);
    assert("Append b to link queue failed.", lq_append(&lq, 'b') == LQ_OK);
    assert("Append c to link queue failed.", lq_append(&lq, 'c') == LQ_OK);
    assert("Append d to link queue failed.", lq_append(&lq, 'd') == LQ_OK);
    assert("Destroy link queue failed.", (lq_destroy(&lq) == LQ_OK && lq_length(lq) == 0));

    return OK;
}

static char *run()
{
    run_test(test_queue_append);
    run_test(test_queue_get_head);
    run_test(test_queue_delete);
    run_test(test_queue_detroy);

    return OK;
}

TEST_MAIN
