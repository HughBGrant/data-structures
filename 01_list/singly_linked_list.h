#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef int sll_data;

typedef struct _sll_node {
    sll_data data;
    struct _sll_node *next;
} sll_node;

typedef struct {
    sll_node *head;
    size_t count;
} sll_list;

void sll_insert(sll_list *list, size_t pos, sll_data data);
void sll_remove(sll_list *list, size_t pos);
sll_data *sll_get(sll_list *list, size_t pos);
sll_node *sll_linear_search_move2front(sll_list *list, sll_data key);
sll_node *sll_linear_search_transpose(sll_list *list, sll_data key);
void sll_print(sll_list *list);
size_t sll_size(sll_list *list);

sll_list *sll_create(void);
void sll_destroy(sll_list *list);
sll_node *sll_node_create(sll_data data);
void sll_node_destroy(sll_node *node);

#endif
