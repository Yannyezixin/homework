#include <stdlib.h>
#include "link_stack.h"

enum status ls_init(lstack *ls)
{
    ls_node *t;
    t = (ls_node *)malloc(sizeof(ls_node));
    if (NULL == t) return LS_FALSE;
    t->next = NULL;
    *ls = t;

    return LS_OK;
}

enum status ls_detroy(lstack *ls)
{
    while (NULL != *ls) {
        ls_node *t;
        t = *ls;
        *ls = (*ls)->next;
        free(t);
    }

    return LS_OK;
}

enum status ls_empty(lstack ls)
{
    if (NULL == ls) return LS_TRUE;
    return LS_FALSE;
}

enum status ls_push(lstack *ls, elem_type e)
{
    ls_node *t;
    t = (ls_node *)malloc(sizeof(ls_node));
    if (NULL == t) return LS_FALSE;
    t->data = e;
    t->next = *ls;
    *ls = t;
    return LS_OK;
}

enum status ls_pop(lstack *ls, elem_type *e)
{
    if(NULL == *ls) return LS_FALSE;
    ls_node *t;
    t = *ls;
    *e = (*ls)->data;
    *ls = (*ls)->next;
    free(t);
    return LS_OK;
}

enum status ls_get_top(lstack *ls, elem_type *e)
{
    if (NULL == *ls) return LS_FALSE;
    *e = (*ls)->data;
    return LS_OK;
}
