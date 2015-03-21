#include "../../vendor/unit.h"
#include <stdlib.h>
#include "link_stack.h"

int tests_run = 0;

void print_ls(char *messsage, lstack ls)
{
    printf("%s link stack ( ", messsage);
    while(NULL != ls) {
        printf("%c ", ls->data);
        ls = ls->next;
    }
    printf(")\n");
}

static char *test_ls_push()
{
    ls_node *ls;
    elem_type e;

    assert("Init link stack failed.", ls_init(&ls) == LS_OK);
    assert("Push a to link stack failed.", ls_push(&ls, 'a') == LS_OK);
    assert("Push b to link stack failed.", ls_push(&ls, 'b') == LS_OK);
    assert("Push c to link stack failed.", ls_push(&ls, 'c') == LS_OK);
    assert("Push d to link stack failed.", ls_push(&ls, 'd') == LS_OK);
    assert("Push f to link stack failed.", ls_push(&ls, 'f') == LS_OK);

    return OK;
}

static char *test_ls_top_pop()
{
    ls_node *ls;
    elem_type e;

    assert("Init link stack failed.", ls_init(&ls) == LS_OK);
    assert("Push a to link stack failed.", ls_push(&ls, 'a') == LS_OK);
    assert("Push f to link stack failed.", ls_push(&ls, 'f') == LS_OK);
    assert("Top f from link stack failed.", (ls_get_top(&ls, &e) == LS_OK && e == 'f'));
    assert("Pop f from link stack failed.", (ls_pop(&ls, &e) == LS_OK && e == 'f'));
    assert("Pop a from link stack failed.", (ls_pop(&ls, &e) == LS_OK && e == 'a'));
    assert("Pop from link stack failed.", ls_pop(&ls, &e) == LS_FALSE);

    return OK;
}

static char *test_ls_detroy()
{
    ls_node *ls;
    elem_type e;

    assert("Init link stack failed.", ls_init(&ls) == LS_OK);
    assert("Push a to link stack failed.", ls_push(&ls, 'a') == LS_OK);
    assert("Push b to link stack failed.", ls_push(&ls, 'b') == LS_OK);
    assert("Push c to link stack failed.", ls_push(&ls, 'c') == LS_OK);
    assert("Push d to link stack failed.", ls_push(&ls, 'd') == LS_OK);
    assert("Push f to link stack failed.", ls_push(&ls, 'f') == LS_OK);
    assert("Destory link stack failed.", ls_detroy(&ls) == LS_OK);
    assert("Destory link stack failed, link stack not empty", ls_empty(ls) == LS_TRUE);

    return OK;
}

static char *run()
{
    run_test(test_ls_push);
    run_test(test_ls_top_pop);
    run_test(test_ls_detroy);
    return OK;
}

TEST_MAIN
