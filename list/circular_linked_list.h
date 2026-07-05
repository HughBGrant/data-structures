#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int cll_data;

typedef struct _cll_node {
    cll_data data;
    struct _cll_node *next;
} cll_node;

typedef struct {
    cll_node *head;
    cll_node *tail;
    size_t count;
} circular_linked_list;

circular_linked_list *cll_create(void);
cll_node *cll_create_node(cll_data data);
void cll_append(circular_linked_list *list, cll_data data);
void cll_insert(circular_linked_list *list, size_t pos, cll_data data);
void cll_delete(circular_linked_list *list, size_t pos);
cll_node *cll_get(circular_linked_list *list, size_t pos); /////////
void cll_destroy(circular_linked_list *list);

size_t cll_size(circular_linked_list *list);
#endif
