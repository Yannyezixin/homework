#include "../../vendor/unit.h"
#include <stdlib.h>
#include "link_list.h"

int tests_run = 0;

void print_ll(char *message, link_list ll)
{
    printf("%s link list ( ", message);
    ll = ll->next;
    while (NULL != ll) {
        printf("%c ", ll->data);
        ll = ll->next;
    }
    printf(")\n");
}

static char *test_ll_insert()
{
    link_list ll;
    lnode *lb, *la;
    elem_type e;

    assert("Init link list failed.", ll_init(&ll) == LL_OK);
    assert("Length of link list false", ll_length(ll) == 0);
    lb = ll, la = ll_make_node('a');
    assert("Insert a node to last link list failed.", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('b');
    assert("Insert b node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('d');
    assert("Insert d node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll, la = ll_make_node('f');
    assert("Insert f node to first of link list failed", ll_insert_after(lb, la) == LL_OK);
    assert("Length of link list false", ll_length(ll) == 4);
    print_ll("Insert", ll);

    return OK;
}

static char *test_ll_delete()
{
    link_list ll;
    lnode *lb, *la, *ln;
    elem_type e;

    assert("Init link list failed.", ll_init(&ll) == LL_OK);
    lb = ll, la = ll_make_node('a');
    assert("Insert a node to last link list failed.", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('b');
    assert("Insert b node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('d');
    assert("Insert d node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll, la = ll_make_node('f');
    assert("Insert f node to first of link list failed", ll_insert_after(lb, la) == LL_OK);
    ln = ll;
    assert("Delete f node of link list failed.", (ll_delete_after(ln, &e) == LL_OK && e == 'f'));
    ln = ll;
    assert("Delete a node of link list failed.", (ll_delete_after(ln, &e) == LL_OK && e == 'a'));
    ln = ll_next_elem(ln);
    assert("Delete a node of link list failed.", (ll_delete_after(ln, &e) == LL_OK && e == 'd'));
    print_ll("Delete", ll);

    return OK;
}

static char *test_ll_destroy()
{
    link_list ll;
    lnode *lb, *la;
    elem_type e;

    assert("Init link list failed.", ll_init(&ll) == LL_OK);
    assert("Length of link list false", ll_length(ll) == 0);
    lb = ll, la = ll_make_node('a');
    assert("Insert a node to last link list failed.", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('b');
    assert("Insert b node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('d');
    assert("Insert d node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll, la = ll_make_node('f');
    assert("Insert f node to first of link list failed", ll_insert_after(lb, la) == LL_OK);
    assert("Length of link list false", ll_length(ll) == 4);

    assert("Clear of link list failed.", ll_clear(&ll) == LL_OK);
    assert("Empty of link list false.", ll_empty(ll) == LL_TRUE);
    assert("Destroy of link list false", ll_destroy(&ll) == LL_OK);
    return OK;
}

static char *test_ll_search()
{
    link_list ll;
    lnode *lb, *la, *ls;
    elem_type e;

    assert("Init link list failed.", ll_init(&ll) == LL_OK);
    assert("Length of link list false", ll_length(ll) == 0);
    lb = ll, la = ll_make_node('a');
    assert("Insert a node to last link list failed.", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('b');
    assert("Insert b node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll_next_elem(lb), la = ll_make_node('d');
    assert("Insert d node to last of link list failed", ll_insert_after(lb, la) == LL_OK);
    lb = ll, la = ll_make_node('f');
    assert("Insert f node to first of link list failed", ll_insert_after(lb, la) == LL_OK);
    assert("Length of link list false", ll_length(ll) == 4);

    /*
     * FIXME why can't compare as follow
     * TODO better compare way
     * assert("Search f node of link list failed.", ll_search(ll, 'f') == la);
     */
    assert("Search f node of link list failed.", ll_search(ll, 'f')->data == 'f');
    assert("Search f node of link list failed.", ll_search(ll, 'a')->data == 'a');

    return OK;
}


static char *run()
{
    run_test(test_ll_insert);
    run_test(test_ll_delete);
    run_test(test_ll_destroy);
    run_test(test_ll_search);
    return OK;
}


TEST_MAIN
