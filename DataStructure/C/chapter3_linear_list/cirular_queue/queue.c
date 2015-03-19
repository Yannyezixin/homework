#include <stdlib.h>
#include "queue.h"

enum status queue_init(sq_queue *sq, int size)
{
    sq->base = (elem_type *)malloc(size * sizeof(elem_type));
    if (NULL == sq->base) return QUEUE_FALSE;
    sq->maxsize = size;
    sq->front = sq->rear = 0;

    return QUEUE_OK;
}

enum status queue_destroy(sq_queue *sq)
{
    free(sq->base);
    sq->base = NULL;
    sq->maxsize = sq->front = sq->rear = 0;

    return QUEUE_OK;
}

void queue_clear(sq_queue *sq)
{
    sq->front = sq->rear = 0;
}

enum status queue_empty(sq_queue *sq)
{
    if (sq->front == sq->rear) return QUEUE_TRUE;
    return QUEUE_FALSE;
}

int queue_length(sq_queue sq)
{
    return abs(sq.rear - sq.front);
}

enum status queue_get_head(sq_queue *sq, elem_type *e)
{
    if (sq->front == sq->rear) return QUEUE_FALSE;
    *e = sq->base[sq->front];
    return QUEUE_OK;

}

enum status queue_insert(sq_queue *sq, elem_type e)
{
    if ((sq->rear + 1) % sq->maxsize == sq->front) return QUEUE_FALSE;
    sq->base[sq->rear] = e;
    sq->rear = (sq->rear + 1) % sq->maxsize;

    return QUEUE_OK;
}

enum status queue_delete(sq_queue *sq, elem_type *e)
{
    if (sq->rear == sq->front) return QUEUE_FALSE;
    *e = sq->base[sq->front];
    sq->front = (sq->front + 1) % sq->maxsize;

    return QUEUE_OK;
}
