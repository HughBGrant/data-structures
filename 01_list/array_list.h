#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef int al_item;
typedef struct array_list al_list;

void al_insert(al_list *list, size_t pos, al_item data);
void al_remove(al_list *list, size_t pos);
al_item *al_get(al_list *list, size_t pos);
size_t al_size(al_list *list);
void al_print(al_list *list);

al_list *al_create(size_t capacity);
void al_destroy(al_list *list);

#endif