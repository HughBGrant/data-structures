#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int al_data;

typedef struct {
    size_t capacity;
    size_t count;
    al_data *array;
} array_list;

array_list *al_create(size_t capacity);
void al_append(array_list *list, al_data data);
void al_insert(array_list *list, size_t pos, al_data data);
void al_delete(array_list *list, size_t pos);
void al_destroy(array_list *list);

size_t al_size(array_list *list);
#endif