#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef int al_item;

typedef struct {
    al_item *data;
    size_t capacity;
    size_t count;
} array_list;

typedef array_list al_list;

void al_insert(al_list *list, size_t pos, al_item data);
void al_remove(al_list *list, size_t pos);
al_item *al_get(al_list *list, size_t pos);
int al_linear_search_transpose(al_list *list, al_item key);
int al_linear_search_move2front(al_list *list, al_item key);
int al_binary_search(al_list *list, al_item key);
size_t al_size(al_list *list);
void al_print(al_list *list);

al_list *al_create(size_t capacity);
void al_destroy(al_list *list);

#endif