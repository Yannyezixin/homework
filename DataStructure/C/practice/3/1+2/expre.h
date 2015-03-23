#ifndef EXPRE
#define EXPRE

typedef char elem_type;

enum status {
    SQ_OK,
    SQ_TRUE,
    SQ_FALSE
};


typedef struct {
    elem_type *elem;
    int top;
    int size;
    int increment;
} sq_stack;

enum status sq_stack_init(sq_stack *, int, int);
enum status sq_stack_destroy(sq_stack *);
enum status sq_stack_empty(sq_stack);
void sq_stack_clear(sq_stack *);
enum status sq_stack_push(sq_stack *, elem_type);
enum status sq_stack_pop(sq_stack *, elem_type *);
enum status sq_stack_top(sq_stack *, elem_type *);
char *infix_to_postfix(char *, sq_stack);
float cal_postfix(char *, float []);

#endif
