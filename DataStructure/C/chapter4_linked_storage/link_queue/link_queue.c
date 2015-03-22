#include <stdlib.h>
#include "link_queue.h"

enum status lq_init(lqueue *lq)
{
    lq_node *q;
    q = (lq_node *)malloc(sizeof(lq_node));
    if (NULL == q) return LQ_FALSE;
    lq->front = lq->rear = q;
    lq->front->next = NULL;

    return LQ_OK;
}

enum status lq_destroy(lqueue *lq)
{
    while (NULL != lq->front) {
        lq->rear = lq->front->next;
        free(lq->front);
        lq->front = lq->rear;
    }

    return LQ_OK;
}

enum status lq_empty(lqueue lq)
{
    if (lq.rear == lq.front) return LQ_TRUE;
    else return LQ_FALSE;
}

int lq_length(lqueue lq)
{
    int length = 0;
    while (lq.rear != lq.front) {
        length++;
        lq.front = lq.front->next;
    }

    return length;
}

enum status lq_get_head(lqueue lq, elem_type *e)
{
    if (lq.rear == lq.front) return LQ_FALSE;
    *e = lq.front->next->data;

    return LQ_OK;
}

enum status lq_append(lqueue *lq, elem_type e)
{
    lq_node *q;
    q = (lq_node *)malloc(sizeof(lq_node));
    if (NULL == q) return LQ_FALSE;
    q->data = e;
    q->next = NULL;
    lq->rear->next = q;
    lq->rear = q;

    return LQ_OK;
}

enum status lq_delete(lqueue *lq, elem_type *e)
{
    lq_node *q;
    if (lq->rear == lq->front) return LQ_FALSE;
    q = lq->front->next;
    *e = q->data;
    lq->front->next = q->next;
    if (lq->rear == q) lq->rear = lq->front;
    free(q);
    return LQ_OK;
}
