#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int dll_data;

typedef struct _dll_node {
    dll_data data;
    struct _dll_node *next;
    struct _dll_node *prev;
} dll_node;

typedef struct {
    dll_node *head_sentinel;
    dll_node *tail_sentinel;
    size_t count;
} dll_list;

dll_list *dll_create(void);
void dll_destroy(dll_list *list);
dll_node *dll_node_create(dll_data data);
void dll_node_destroy(dll_node *node);
void dll_insert(dll_list *list, size_t pos, dll_data data);
dll_data dll_delete(dll_list *list, size_t pos);
dll_node *dll_node_get(dll_list *list, size_t pos);
dll_data dll_get(dll_list *list, size_t pos);

size_t dll_size(dll_list *list);
void dll_print(dll_list *list);

#endif
