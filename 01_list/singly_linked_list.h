#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef int SLItem;
typedef struct SinglyLinkedList SLList;

void sll_insert(SLList *list, size_t index, SLItem data);
SLItem sll_delete(SLList *list, size_t index);
SLItem sll_get(SLList *list, size_t index);
void sll_print(SLList *list);
size_t sll_size(SLList *list);

SLList *sll_create(void);
void sll_destroy(SLList *list);

#endif
