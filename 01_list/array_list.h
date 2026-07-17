#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int al_data;

typedef struct {
    al_data *items;
    size_t max_size;
    size_t count;
} array_list;

array_list *al_create(size_t max_size);
void al_insert(array_list *list, size_t pos, al_data data);
void al_delete(array_list *list, size_t pos);

al_data *al_get(array_list *list, size_t pos);
void al_destroy(array_list *list);

size_t al_size(array_list *list);
#endif