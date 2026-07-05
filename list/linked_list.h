#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ll_data_type;

typedef struct _ll_node {
    ll_data_type data;
    struct _ll_node *next;
} ll_node;

typedef struct {
    ll_node *head;
    ll_node *tail;
    size_t count;
} linked_list;

linked_list *ll_create(void);
ll_node *ll_create_node(ll_data_type data);
void ll_append(linked_list *list, ll_data_type data);
void ll_insert(linked_list *list, size_t pos, ll_data_type data);
void ll_delete(linked_list *list, size_t pos);
ll_node *ll_get(linked_list *list, size_t pos); /////////
void ll_destroy(linked_list *list);

size_t ll_size(linked_list *list);
#endif
