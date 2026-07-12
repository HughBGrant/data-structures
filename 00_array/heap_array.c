#include "heap_array.h"

heap_array *ha_create(size_t capacity)
{
    heap_array *array = malloc(sizeof(heap_array));
    if (array == NULL) {
        return NULL;
    }

    array->array = malloc(sizeof(ha_data) * capacity);
    if (array->array == NULL) {
        free(array);
        return NULL;
    }

    array->capacity = capacity;

    return array;
}
void ha_set(heap_array *array, size_t pos, ha_data data)
{
    if (array == NULL || pos >= array->capacity) {
        return;
    }

    array->array[pos] = data;
}
ha_data ha_get(heap_array *array, size_t pos)
{
    return array->array[pos];
}
void ha_destroy(heap_array *array)
{
    if (array == NULL) {
        return;
    }

    free(array->array);
    free(array);
}
size_t ha_size(heap_array *array)
{
    if (array == NULL) {
        return 0;
    }

    return array->capacity;
}