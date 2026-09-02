#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stddef.h>

typedef int SLItem;
typedef struct SinglyLinkedList SLList;

void sl_insert(SLList *list, size_t index, SLItem data);
SLItem sl_delete(SLList *list, size_t index);
SLItem sl_get(SLList *list, size_t index);
void sl_print(SLList *list);
size_t sl_size(SLList *list);

SLList *sl_create(void);
void sl_destroy(SLList *list);

#endif
