#include <stdlib.h>
#include "expre.h"

enum status sq_stack_init(sq_stack *sq, int size, int inc)
{
    sq->elem = (elem_type *)malloc(size * sizeof(elem_type));
    if (NULL == sq->elem) return SQ_FALSE;
    sq->top = 0;
    sq->size = size;
    sq->increment = inc;

    return SQ_OK;
}

enum status sq_stack_destroy(sq_stack *sq)
{
    free(sq->elem);
    sq->elem = NULL;
    sq->top = 0;
    sq->size = 0;
    sq->increment = 0;

    return SQ_OK;
}

enum status sq_stack_empty(sq_stack sq)
{
    if (0 == sq.top) return SQ_TRUE;
    return SQ_FALSE;
}

void sq_stack_clear(sq_stack *sq)
{
    sq->top = 0;
}


enum status sq_stack_push(sq_stack *sq, elem_type e)
{
    elem_type *new_elem;
    if (sq->top >= sq->size) {
        new_elem = (elem_type *)realloc(sq->elem, (sq->size + sq->increment) * \
                sizeof(elem_type));
        if (NULL == new_elem) return SQ_FALSE;
        sq->elem = new_elem;
        sq->size = sq->size + sq->increment;
    }
    sq->elem[sq->top++] = e;

    return SQ_OK;
}

enum status sq_stack_pop(sq_stack *sq, elem_type *e)
{
    if (0 == sq->top) return SQ_FALSE;
    *e = sq->elem[sq->top-1];
    sq->top -= 1;
    return SQ_OK;
}

enum status sq_stack_top(sq_stack *sq, elem_type *e)
{
    if (0 == sq->top) return SQ_FALSE;
    *e = sq->elem[sq->top-1];
    return SQ_OK;
}
