#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef int DLItem;
typedef struct DoublyLinkedList DLList;

void dll_insert(DLList *list, size_t pos, DLItem data);
DLItem dll_delete(DLList *list, size_t pos);
DLItem dll_get(DLList *list, size_t pos);
size_t dll_size(DLList *list);
void dll_print(DLList *list);

DLList *dll_create(void);
void dll_destroy(DLList *list);

#endif
