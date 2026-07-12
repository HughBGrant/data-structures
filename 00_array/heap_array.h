#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef int ha_data;

typedef struct {
    ha_data *array;
    size_t capacity;
} heap_array;

heap_array *ha_create(size_t capacity);
void ha_set(heap_array *array, size_t pos, ha_data data);
ha_data ha_get(heap_array *array, size_t pos);
void ha_destroy(heap_array *array);

size_t ha_size(heap_array *array);
#endif