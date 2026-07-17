#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int sll_data;

typedef struct _sll_node {
    sll_data data;
    struct _sll_node *next;

} sll_node;

typedef struct {
    sll_node *head;
    size_t count;
} singly_linked_list;

singly_linked_list *sll_create(void);
sll_node *sll_create_node(sll_data data);
void sll_insert(singly_linked_list *list, size_t pos, sll_data data);
void sll_delete(singly_linked_list *list, size_t pos);
sll_data sll_get(singly_linked_list *list, size_t pos);
void sll_destroy(singly_linked_list *list);

size_t sll_size(singly_linked_list *list);
#endif
