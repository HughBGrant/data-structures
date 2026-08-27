#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stddef.h>

typedef int cll_item;
typedef struct circular_linked_list cll_list;

void cll_insert(cll_list *list, size_t index, cll_item value);
cll_item cll_delete(cll_list *list, size_t index);
cll_item cll_get(cll_list *list, size_t index);
size_t cll_size(cll_list *list);
void cll_print(cll_list *list);

cll_list *cll_create(void);
void cll_destroy(cll_list *list);

#endif
