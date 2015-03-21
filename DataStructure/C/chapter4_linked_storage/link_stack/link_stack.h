#ifndef LINK_STACK
#define LINK_STACK

typedef char elem_type;

typedef struct ls_node{
    elem_type data;
    struct ls_node *next;
} ls_node, *lstack;

enum status {
    LS_OK,
    LS_TRUE,
    LS_FALSE
};

enum status ls_init(lstack *);
enum status ls_detroy(lstack *);
enum status ls_empty(lstack);
enum status ls_push(lstack *, elem_type);
enum status ls_pop(lstack *, elem_type *);
enum status ls_get_top(lstack *, elem_type *);

#endif
