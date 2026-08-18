#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stddef.h>

typedef int cll_data;

typedef struct _cll_node {
    cll_data data;
    struct _cll_node *next;
} cll_node;

typedef struct {
    cll_node *tail;
    size_t count;
} circular_linked_list;

circular_linked_list *cll_create(void);
void cll_destroy(circular_linked_list *list);
cll_node *cll_node_create(cll_data data);
void cll_node_destroy(cll_node *node);
void cll_insert(circular_linked_list *list, size_t pos, cll_data data);
void cll_remove(circular_linked_list *list, size_t pos);
cll_data *cll_get(circular_linked_list *list, size_t pos);
size_t cll_size(circular_linked_list *list);
void cll_print(circular_linked_list *list);

#endif
