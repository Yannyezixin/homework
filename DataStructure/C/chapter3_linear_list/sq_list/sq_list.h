#ifndef SQ_LIST
#define SQ_LIST

typedef char elem_type;

enum status {
    LIST_OK,
    LIST_TRUE,
    LIST_FALSE
};

typedef struct {
    elem_type *elem;
    int length;
    int size;
    int increment;
} sq_list;

enum status list_init(sq_list *, int, int);
enum status list_destroy(sq_list *);
enum status list_clear(sq_list *);
enum status list_empty(sq_list);
int list_length(sq_list);
enum status list_get_elem(sq_list *, int, elem_type *);
int list_search(sq_list, elem_type);
//
enum status list_set_elem(sq_list *, int, elem_type);
enum status list_append(sq_list *, elem_type);
enum status list_delete(sq_list *, elem_type *);


#endif
