#ifndef DLINK_LIST
#define DLINK_LIST

enum status {
    LL_OK,
    LL_TRUE,
    LL_FALSE,
};

typedef char elem_type;

typedef struct dlnode {
    elem_type data;
    struct dlnode *prev, *next;
} dlnode, *dlink_list;

enum status dll_init(dlink_list *);
enum status dll_destroy(dlink_list *);
enum status dll_clear(dlink_list *);
enum status dll_empty(dlink_list);
int dll_length(dlink_list);
dlnode *dll_search(dlink_list, elem_type);
dlnode *dll_prev_elem(dlnode *);
dlnode *dll_next_elem(dlnode *);
dlnode *dll_make_node(elem_type);
enum status dll_insert_before(dlnode *, dlnode *);
enum status dll_insert_after(dlnode *, dlnode *);
enum status dll_delete(dlnode *, elem_type *);
enum status dll_create_list(dlink_list *, int, elem_type *);
enum status dll_inverse_list(dlink_list *);
enum status dll_merge_list(dlink_list *, dlink_list *, dlink_list *);

#endif
