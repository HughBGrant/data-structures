#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stddef.h>

typedef int cll_item;

typedef struct _cll_node {
    cll_item data;
    struct _cll_node *next;
} cll_node;

typedef struct {
    cll_node *tail;
    size_t count;
} cll_list;

void cll_insert(cll_list *list, size_t pos, cll_item data);
void cll_remove(cll_list *list, size_t pos);
cll_item *cll_get(cll_list *list, size_t pos);
size_t cll_size(cll_list *list);
void cll_print(cll_list *list);

cll_list *cll_create(void);
void cll_destroy(cll_list *list);
cll_node *cll_node_create(cll_item data);
void cll_node_destroy(cll_node *node);

#endif
