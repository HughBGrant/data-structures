#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stddef.h>

typedef int CLItem;
typedef struct CircularLinkedList CLList;

void cll_insert(CLList *list, size_t index, CLItem data);
CLItem cll_delete(CLList *list, size_t index);
CLItem cll_get(CLList *list, size_t index);
size_t cll_size(CLList *list);
void cll_print(CLList *list);

CLList *cll_create(void);
void cll_destroy(CLList *list);

#endif
