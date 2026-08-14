#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int cdll_data;

typedef struct _cdll_node {
    cdll_data data;
    struct _cdll_node *next;
    struct _cdll_node *prev;
} cdll_node;

typedef struct {
    cdll_node *head_sentinel;
    size_t count;
} doubly_linked_list;

doubly_linked_list *cdll_create(void);
void cdll_destroy(doubly_linked_list *list);
cdll_node *cdll_node_create(cdll_data data);
void cdll_node_destroy(cdll_node *node);
void cdll_insert(doubly_linked_list *list, size_t pos, cdll_data data);
void cdll_remove(doubly_linked_list *list, size_t pos);
cdll_node *cdll_node_get(doubly_linked_list *list, size_t pos);
cdll_data *cdll_get(doubly_linked_list *list, size_t pos);
size_t cdll_size(doubly_linked_list *list);
void cdll_print(doubly_linked_list *list);

#endif
