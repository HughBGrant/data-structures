#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef int dll_item;
typedef struct doubly_linked_list dll_list;

void dll_insert(dll_list *list, size_t index, dll_item value);
void dll_remove(dll_list *list, size_t index);
dll_item *dll_get(dll_list *list, size_t index);
size_t dll_size(dll_list *list);
void dll_print(dll_list *list);

dll_list *dll_create(void);
void dll_destroy(dll_list *list);

#endif
