#include <stdlib.h>
#include "sq_stack.h"

enum status sq_stack_init(sq_stack *sq, int size, int inc)
{
    sq->elem = (elem_type *)malloc(size * sizeof(elem_type));
    if (NULL == sq->elem) return SQ_FALSE;
    sq->top = 0;
    sq->size = size;
    sq->increment = inc;

    return SQ_OK;
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
