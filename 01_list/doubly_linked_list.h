#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef int dll_item;

typedef struct _dll_node {
    dll_item data;
    struct _dll_node *next;
    struct _dll_node *prev;
} dll_node;

typedef struct {
    dll_node *head_sentinel;
    size_t count;
} doubly_linked_list;
typedef doubly_linked_list dll_list;

void dll_insert(dll_list *list, size_t pos, dll_item data);
void dll_remove(dll_list *list, size_t pos);
dll_node *dll_node_get(dll_list *list, size_t pos);
dll_item *dll_get(dll_list *list, size_t pos);
size_t dll_size(dll_list *list);
void dll_print(dll_list *list);

dll_list *dll_create(void);
void dll_destroy(dll_list *list);
dll_node *dll_node_create(dll_item data);
void dll_node_destroy(dll_node *node);

#endif
