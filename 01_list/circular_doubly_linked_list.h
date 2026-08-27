#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef int cdll_item;
typedef struct doubly_linked_list cdll_list;

void cdll_insert(cdll_list *list, size_t index, cdll_item value);
cdll_item cdll_delete(cdll_list *list, size_t index);
cdll_item cdll_get(cdll_list *list, size_t index);
size_t cdll_size(cdll_list *list);
void cdll_print(cdll_list *list);

cdll_list *cdll_create(void);
void cdll_destroy(cdll_list *list);

#endif
