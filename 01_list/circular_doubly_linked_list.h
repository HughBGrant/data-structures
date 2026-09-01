#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef int CDLItem;
typedef struct CircularDoublyLinkedList CDLList;

void cdll_insert(CDLList *list, size_t index, CDLItem data);
CDLItem cdll_delete(CDLList *list, size_t index);
CDLItem cdll_get(CDLList *list, size_t index);
size_t cdll_size(CDLList *list);
void cdll_print(CDLList *list);

CDLList *cdll_create(void);
void cdll_destroy(CDLList *list);

#endif
