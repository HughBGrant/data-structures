#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef int sll_item;

typedef struct _sll_node {
    sll_item data;
    struct _sll_node *next;
} sll_node;

typedef struct {
    sll_node *head;
    size_t count;
} singly_linked_list;
typedef singly_linked_list sll_list;

void sll_insert(sll_list *list, size_t pos, sll_item data);
void sll_remove(sll_list *list, size_t pos);
sll_item *sll_get(sll_list *list, size_t pos);
sll_node *sll_linear_search_move2front(sll_list *list, sll_item key);
sll_node *sll_linear_search_transpose(sll_list *list, sll_item key);
void sll_print(sll_list *list);
size_t sll_size(sll_list *list);

sll_list *sll_create(void);
void sll_destroy(sll_list *list);
sll_node *sll_node_create(sll_item data);
void sll_node_destroy(sll_node *node);

#endif
