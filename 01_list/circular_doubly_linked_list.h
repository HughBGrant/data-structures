#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

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
} c_d_linked_list;

c_d_linked_list *cdll_create(void);
cdll_node *cdll_node_create(cdll_data data);
void cdll_node_destroy(cdll_node *node);
void cdll_insert(c_d_linked_list *list, size_t pos, cdll_data data);
void cdll_remove(c_d_linked_list *list, size_t pos);
cdll_node *cdll_node_get(c_d_linked_list *list, size_t pos);
cdll_data *cdll_get(c_d_linked_list *list, size_t pos);
size_t cdll_size(c_d_linked_list *list);
void cdll_print(c_d_linked_list *list);

void cdll_destroy(c_d_linked_list *list);

#endif
