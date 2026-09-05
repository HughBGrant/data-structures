#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct ArrayList AList;

void a_insert(AList *list, size_t index, int data);
int a_delete(AList *list, size_t index);
int a_get(AList *list, size_t index);
size_t a_size(AList *list);
void a_print(AList *list);

AList *a_create(void);
void a_destroy(AList *list);

#endif