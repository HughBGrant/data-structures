#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stddef.h>

typedef struct CircularLinkedList CLList;

void cl_insert(CLList *list, size_t index, int data);
int cl_delete(CLList *list, size_t index);
int cl_get(CLList *list, size_t index);
size_t cl_size(CLList *list);
void cl_print(CLList *list);

CLList *cl_create(void);
void cl_destroy(CLList *list);

#endif
