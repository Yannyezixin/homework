#ifndef LINK_QUEUE
#define LINK_QUEUE

typedef char elem_type;

typedef struct lq_node {
    elem_type data;
    struct lq_node *next;
} lq_node, *queue_ptr;

typedef struct {
    queue_ptr front;
    queue_ptr rear;
} lqueue;

enum status {
    LQ_OK,
    LQ_TRUE,
    LQ_FALSE
};

enum status lq_init(lqueue *lq);
enum status lq_destroy(lqueue *lq);
enum status lq_empty(lqueue lq);
int lq_length(lqueue lq);
enum status lq_get_head(lqueue lq, elem_type *);
enum status lq_append(lqueue *lq, elem_type);
enum status lq_delete(lqueue *lq, elem_type *);

#endif
