#include "../../vendor/unit.h"
#include <stdlib.h>
#include "dlink_list.h"

int tests_run = 0;

void print_ll(char *message, dlink_list ll)
{
    printf("%s link list ( ", message);
    ll = ll->next;
    while (NULL != ll) {
        printf("%c ", ll->data);
        ll = ll->next;
    }
    printf(")\n");
}

static char *test_dll_insert()
{
    dlink_list ll;
    dlnode *lb, *la;
    elem_type e;

    assert("Init link list failed.", dll_init(&ll) == LL_OK);
    assert("Length of link list false", dll_length(ll) == 0);
    lb = ll, la = dll_make_node('a');
    assert("Insert before a node to last link list failed.", dll_insert_before(la, lb) == LL_FALSE);
    assert("Insert after a node to last link list failed.", dll_insert_after(lb, la) == LL_OK);
    lb = dll_next_elem(ll), la = dll_make_node('b');
    assert("Insert b node before a node failed.", dll_insert_before(la, lb) == LL_OK);
    lb = dll_prev_elem(lb), la = dll_make_node('c');
    assert("Insert c node before b node failed.", dll_insert_before(la, lb) == LL_OK);

    return OK;
}

static char *test_dll_create()
{
    dlink_list ll, llb;
    elem_type e[6] = {'a', 'b', 'c', 'd', 'f', 'g'};
    assert("Create link list failed.", dll_create_list(&ll, 6, e) == LL_FALSE);
    elem_type b[10] = {'a', 'b', 'c', 'd', 'f', 'g', 'a', 'b', 'g', 'g'};
    assert("Create link list failed.", dll_create_list(&llb, 10, b) == LL_FALSE);

    return OK;
}

static char *test_dll_delete()
{
    dlink_list ll;
    dlnode *ln;
    elem_type e[6] = {'a', 'b', 'c', 'd', 'f', 'g'};
    elem_type el;
    assert("Create link list failed.", dll_create_list(&ll, 6, e) == LL_FALSE);
    ln = dll_next_elem(ll);
    assert("Delete a node failed.", (dll_delete(ln, &el) == LL_OK && el == 'a'));
    ln = dll_next_elem(ll);
    ln = dll_next_elem(ln);
    assert("Delete c node failed.", (dll_delete(ln, &el) == LL_OK && el == 'c'));

    return OK;
}

static char *test_dll_destroy()
{
    dlink_list ll, llb;
    elem_type e[6] = {'a', 'b', 'c', 'd', 'f', 'g'};
    assert("Create link list failed.", dll_create_list(&ll, 6, e) == LL_FALSE);

    assert("Clear of link list failed.", dll_clear(&ll) == LL_OK);
    assert("Empty of link list false.", dll_empty(ll) == LL_TRUE);
    assert("Destroy of link list false", dll_destroy(&ll) == LL_OK);

    return OK;
}

static char *test_dll_search()
{
    dlink_list ll, llb;
    elem_type e[6] = {'a', 'b', 'c', 'd', 'f', 'g'};
    assert("Create link list failed.", dll_create_list(&ll, 6, e) == LL_OK);
    assert("Search f node of link list failed.", dll_search(ll, 'f')->data == 'f');
    assert("Search a node of link list failed.", dll_search(ll, 'a')->data == 'a');

    return OK;
}



static char *test_dll_inverse()
{
    dlink_list ll;
    elem_type e[6] = {'a', 'b', 'c', 'd', 'f', 'g'};
    assert("Create link list failed.", dll_create_list(&ll, 6, e) == LL_OK);
    assert("Inverse link list failed.", dll_inverse_list(&ll) == LL_OK);

    return OK;
}

static char *run()
{
    run_test(test_dll_insert);
    run_test(test_dll_create);
    run_test(test_dll_delete);
    run_test(test_dll_destroy);
    run_test(test_dll_search);
    run_test(test_dll_inverse);
    return OK;
}


TEST_MAIN
