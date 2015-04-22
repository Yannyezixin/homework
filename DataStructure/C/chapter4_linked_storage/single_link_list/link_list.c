#include <stdlib.h>
#include "link_list.h"

enum status ll_init(link_list *ll)
{
    *ll = (lnode *)malloc(sizeof(lnode));
    if (NULL == *ll) return LL_FALSE;
    (*ll)->next = NULL;
    return LL_OK;
}

enum status ll_destroy(link_list *ll)
{
    lnode *ln;
    while (NULL != *ll) {
        ln = *ll;
        *ll = (*ll)->next;
        free(ln);
    }

    return LL_OK;
}

enum status ll_clear(link_list *ll)
{
    if (NULL == *ll) return LL_FALSE;
    lnode *ln;
    while (NULL != (*ll)->next) {
        ln = *ll;
        *ll = (*ll)->next;
        free(ln);
    }

    return LL_OK;
}

enum status ll_empty(link_list ll)
{
    if (NULL == ll->next) return LL_TRUE;
    else return LL_FALSE;
}

int ll_length(link_list ll)
{
    int length = 0;
    ll = ll->next;
    while (NULL != ll) {
        length++;
        ll = ll->next;
    }

    return length;
}

lnode *ll_search(link_list ll, elem_type e)
{
    if (NULL == ll) return NULL;
    lnode *ln;
    ln = ll->next;
    while (NULL != ln && ln->data != e) ln = ln->next;

    return ln;
}

lnode *ll_next_elem(lnode *ln)
{
    ln = ln->next;

    return ln;
}

lnode *ll_make_node(elem_type e)
{
    lnode *ln;
    ln = (lnode *)malloc(sizeof(lnode));
    ln->data = e;
    ln->next = NULL;

    return ln;
}

enum status ll_insert_after(lnode *lb, lnode *la)
{
    if (NULL == lb || NULL == la) return LL_FALSE;
    la->next = lb->next;
    lb->next = la;
    return LL_OK;
}

enum status ll_delete_after(lnode *ln, elem_type *e)
{
    lnode *q;
    if (NULL == ln || NULL == ln->next) return LL_FALSE;
    q = ln->next;
    ln->next = q->next;
    *e = q->data;
    free(q);

    return LL_OK;
}

enum status ll_create_list(link_list *ll, int n, elem_type *A)
{
    lnode *p, *q;
    int i;
    if (LL_FALSE == ll_init(ll)) return LL_FALSE;
    p = *ll;
    for (i = 0; i < n; i++) {
        q = ll_make_node(A[i]);
        ll_insert_after(p, q);
        p = q;
    }

    return LL_OK;
}

enum status ll_inverse_list(link_list *ll)
{
    lnode *q, *p;
    if (NULL == (*ll)->next || NULL == (*ll)->next->next) return LL_FALSE;
    p = (*ll)->next;
    (*ll)->next = NULL;
    while (NULL != p) {
        q = p->next;
        ll_insert_after(*ll, p);
        p = q;
    }

    return LL_OK;
}

enum status ll_merge_list(link_list *lla, link_list *llb, link_list *llc)
{
    lnode *pa, *pb, *pc, *temp;
    pa = (*lla)->next;
    pb = (*llb)->next;
    if (ll_init(llc) == LL_FALSE) return LL_FALSE;
    pc = (*llc)->next = pa;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            temp = pa->next;
            ll_insert_after(pc, pa);
            pc = pa;
            pa = temp;
        } else {
            temp = pb->next;
            ll_insert_after(pc, pb);
            pc = pb;
            pb = temp;
        }
    }
    pc->next = pa ? pa : pb;

    return LL_OK;
}
