#ifndef QUEUE
#define QUEUE

typedef char elem_type;

typedef struct {
    elem_type *base;
    int front;
    int rear;
    int maxsize;
} sq_queue;

enum status {
    QUEUE_OK,
    QUEUE_FALSE,
    QUEUE_TRUE
};

enum status queue_init(sq_queue *, int);
enum status queue_destroy(sq_queue *);
void queue_clear(sq_queue *);
enum status queue_empty(sq_queue *);
int queue_length(sq_queue);
enum status queue_get_head(sq_queue *, elem_type *);
enum status queue_insert(sq_queue *, elem_type);
enum status queue_delete(sq_queue *, elem_type *);

#endif
