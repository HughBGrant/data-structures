#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int dll_data;

typedef struct tagDLL_Node {
    dll_data data;
    struct tagDLL_Node *prev;
    struct tagDLL_Node *next;
} dll_node;

typedef struct {
    dll_node *head;
    dll_node *tail;
    size_t count;
} doubly_linked_list;

doubly_linked_list *dll_create(void);
dll_node *dll_create_node(dll_data data);
void dll_append(doubly_linked_list *list, dll_data data);
void dll_insert(doubly_linked_list *list, size_t pos, dll_data data);
void dll_delete(doubly_linked_list *list, size_t pos);
dll_node *dll_get_node(doubly_linked_list *list, size_t pos);
dll_data dll_get(doubly_linked_list *list, size_t pos);

void dll_destroy(doubly_linked_list *list);

size_t dll_size(doubly_linked_list *list);

#endif
