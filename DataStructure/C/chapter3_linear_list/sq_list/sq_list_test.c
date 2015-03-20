#include "../../vendor/unit.h"
#include <stdlib.h>
#include "sq_list.h"

int tests_run = 0;

void print_list(char *message, sq_list sq)
{
    printf("%s : list ( ", message);
    int i;
    for (i = 0; i < sq.length; i++) {
        printf("%c ", sq.elem[i]);
    }
    printf(")\n");
}

static char *test_list_append()
{
    sq_list sq;
    elem_type e;
    int size = 5, increment = 5;

    assert("Init list failed.", list_init(&sq, size, increment) == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Length list is not true.", list_length(sq) == 12);
    assert("Destory list failed.", list_destroy(&sq) == LIST_OK);
    return OK;
}

static char *test_list_set_get_elem()
{
    sq_list sq;
    elem_type e;
    int size = 5, increment = 5;

    assert("Init list failed.", list_init(&sq, size, increment) == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Append d to list failed.", list_append(&sq, 'd') == LIST_OK);
    assert("get c from list failed.", list_get_elem(&sq, 3, &e) == LIST_OK);
    assert("get c from list failed, not equal.", e == 'c');
    assert("set c to g failed.", list_set_elem(&sq, 3, 'g') == LIST_OK);
    assert("get g from list failed.", list_get_elem(&sq, 3, &e) == LIST_OK);
    assert("get g from list failed, not equal.", e == 'g');
    assert("Destory list failed.", list_destroy(&sq) == LIST_OK);
    return OK;
}

static char *test_list_delete()
{
    sq_list sq;
    elem_type e;
    int size = 5, increment = 5;

    assert("Init list failed.", list_init(&sq, size, increment) == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Append d to list failed.", list_append(&sq, 'd') == LIST_OK);
    assert("Delete rear from list failed.", list_delete(&sq, &e) == LIST_OK);
    assert("Delete rear from list failed, not equal.", e == 'd');
    assert("Destory list failed.", list_destroy(&sq) == LIST_OK);
    return OK;
}

static char *test_list_search()
{
    sq_list sq;
    elem_type e;
    int size = 5, increment = 5;

    assert("Init list failed.", list_init(&sq, size, increment) == LIST_OK);
    assert("Append a to list failed.", list_append(&sq, 'a') == LIST_OK);
    assert("Append b to list failed.", list_append(&sq, 'b') == LIST_OK);
    assert("Append c to list failed.", list_append(&sq, 'c') == LIST_OK);
    assert("Append d to list failed.", list_append(&sq, 'd') == LIST_OK);
    assert("Search c failed.", list_search(sq, 'c') == 2);
    assert("Search failed.", list_search(sq, 'n') == -1);
    assert("Clear list failed.", list_clear(&sq) == LIST_OK);

    return OK;
}

static char *run()
{
    run_test(test_list_append);
    run_test(test_list_set_get_elem);
    run_test(test_list_delete);
    run_test(test_list_search);

    return OK;
}

TEST_MAIN
