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
    size_t count;
} doubly_linked_list;

doubly_linked_list *dll_create(void);
void dll_destroy(doubly_linked_list *list);
dll_node *dll_node_create(dll_data data);
void dll_node_destroy(dll_node *node);
void dll_insert(doubly_linked_list *list, size_t pos, dll_data data);
void dll_remove(doubly_linked_list *list, size_t pos);
dll_node *dll_node_get(doubly_linked_list *list, size_t pos);
dll_data *dll_get(doubly_linked_list *list, size_t pos);
size_t dll_size(doubly_linked_list *list);
void dll_print(doubly_linked_list *list);

#endif
