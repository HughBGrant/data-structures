#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef int AItem;
typedef struct ArrayList AList;

void al_insert(AList *list, size_t index, AItem data);
AItem al_delete(AList *list, size_t index);
AItem al_get(AList *list, size_t index);
size_t al_size(AList *list);
void al_print(AList *list);

AList *al_create(void);
void al_destroy(AList *list);

#endif