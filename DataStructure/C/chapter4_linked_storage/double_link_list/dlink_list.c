#include <stdlib.h>
#include "dlink_list.h"

enum status dll_init(dlink_list *ll)
{
    *ll = (dlnode *)malloc(sizeof(dlnode));
    if (NULL == *ll) return LL_FALSE;
    (*ll)->prev = NULL;
    (*ll)->next = NULL;
    return LL_OK;
}

enum status dll_destroy(dlink_list *ll)
{
    dlnode *ln;
    while (NULL != *ll) {
        ln = *ll;
        *ll = (*ll)->next;
        free(ln);
    }

    return LL_OK;
}

enum status dll_clear(dlink_list *ll)
{
    if (NULL == *ll) return LL_FALSE;
    dlnode *ln;
    while (NULL != (*ll)->next) {
        ln = *ll;
        *ll = (*ll)->next;
        free(ln);
    }

    return LL_OK;
}

enum status dll_empty(dlink_list ll)
{
    if (NULL == ll->next) return LL_TRUE;
    else return LL_FALSE;
}

int dll_length(dlink_list ll)
{
    int length = 0;
    ll = ll->next;
    while (NULL != ll) {
        length++;
        ll = ll->next;
    }

    return length;
}

dlnode *dll_search(dlink_list ll, elem_type e)
{
    if (NULL == ll) return NULL;
    dlnode *ln;
    ln = ll->next;
    while (NULL != ln && ln->data != e) ln = ln->next;

    return ln;
}

dlnode *dll_prev_elem(dlnode *ln)
{
    ln = ln->prev;

    return ln;
}

dlnode *dll_next_elem(dlnode *ln)
{
    ln = ln->next;

    return ln;
}

dlnode *dll_make_node(elem_type e)
{
    dlnode *ln;
    ln = (dlnode *)malloc(sizeof(dlnode));
    ln->data = e;
    ln->prev = NULL;
    ln->next = NULL;

    return ln;
}


enum status dll_insert_before(dlnode *la, dlnode *lb)
{
    if (NULL == lb->prev) return LL_FALSE;
    la->prev = lb->prev;
    la->next = lb;
    la->prev->next = la;
    lb->prev = la;
    return LL_OK;
}

enum status dll_insert_after(dlnode *lb, dlnode *la)
{
    if (NULL == lb || NULL == la) return LL_FALSE;
    la->next = lb->next;
    la->prev = lb;
    if (NULL != lb->next) lb->next->prev = la;
    lb->next = la;
    return LL_OK;
}

enum status dll_delete(dlnode *ln, elem_type *e)
{
    if (NULL == ln || NULL == ln->next) return LL_FALSE;
    ln->next->prev = ln->prev;
    ln->prev->next = ln->next;
    *e = ln->data;
    free(ln);

    return LL_OK;
}

enum status dll_create_list(dlink_list *ll, int n, elem_type *A)
{
    dlnode *p, *q;
    int i;
    if (LL_FALSE == dll_init(ll)) return LL_FALSE;
    p = *ll;
    for (i = 0; i < n; i++) {
        q = dll_make_node(A[i]);
        dll_insert_after(p, q);
        p = q;
    }

    return LL_OK;
}

enum status dll_inverse_list(dlink_list *ll)
{
    dlnode *q, *p;
    if (NULL == (*ll)->next || NULL == (*ll)->next->next) return LL_FALSE;
    p = (*ll)->next;
    (*ll)->next = NULL;
    while (NULL != p) {
        q = p->next;
        dll_insert_after(*ll, p);
        p = q;
    }

    return LL_OK;
}

