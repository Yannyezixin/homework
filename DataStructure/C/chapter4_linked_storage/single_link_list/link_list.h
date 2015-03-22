#ifndef LINK_LIST
#define LINK_LIST

enum status {
    LL_OK,
    LL_TRUE,
    LL_FALSE,
};

typedef char elem_type;

typedef struct lnode {
    elem_type data;
    struct lnode *next;
} lnode, *link_list;

enum status ll_init(link_list *);
enum status ll_destroy(link_list *);
enum status ll_clear(link_list *);
enum status ll_empty(link_list);
int ll_length(link_list);
lnode *ll_search(link_list, elem_type);
lnode *ll_next_elem(lnode *);
lnode *ll_make_node(elem_type);
enum status ll_insert_after(lnode *, lnode *);
enum status ll_delete_after(lnode *, elem_type *);

#endif
