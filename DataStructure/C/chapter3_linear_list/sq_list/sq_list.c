#include <stdlib.h>
#include "sq_list.h"

enum status list_init(sq_list *sq, int size, int increment)
{
    sq->elem = (elem_type *)malloc(size * sizeof(elem_type));
    if (NULL == sq->elem) return LIST_FALSE;
    sq->length = 0;
    sq->size = size;
    sq->increment = increment;

    return LIST_OK;
}

enum status list_destroy(sq_list *sq)
{
    free(sq->elem);
    sq->length = sq->size = sq->increment = 0;

    return LIST_OK;
}

enum status list_clear(sq_list *sq)
{
    sq->length = 0;

    return LIST_OK;
}

enum status list_empty(sq_list sq)
{
    if (0 == sq.length) return LIST_TRUE;
    return LIST_FALSE;
}

int list_length(sq_list sq)
{
    return sq.length;
}

enum status list_get_elem(sq_list *sq, int i, elem_type *e)
{
    if (sq->length < i) return LIST_FALSE;
    *e = sq->elem[i - 1];
    return LIST_OK;
}

int list_search(sq_list sq, elem_type e)
{
    int i = 0;
    while(i < sq.length && sq.elem[i] != e) i++;
    if (i < sq.length) return i;

    return -1;
}

enum status list_set_elem(sq_list *sq, int i, elem_type e)
{
    if (sq->length < i) return LIST_FALSE;
    sq->elem[i - 1] = e;

    return LIST_OK;
}

enum status list_append(sq_list *sq, elem_type e)
{
    elem_type *newbase;
    if (sq->length >= sq->size) {
        newbase = (elem_type *)realloc(sq->elem,
            (sq->size + sq->increment) * sizeof(elem_type));
        if (NULL == newbase) return LIST_FALSE;
        sq->elem = newbase;
        sq->size += sq->increment;
    }
    sq->elem[sq->length++] = e;

    return LIST_OK;
}

enum status list_delete(sq_list *sq, elem_type *e)
{
    if (0 == sq->length) return LIST_FALSE;
    *e = sq->elem[sq->length - 1];
    --sq->length;
    return LIST_OK;
}
