#include "array_list.h"

array_list *al_create(size_t capacity)
{
    if (capacity == 0) {
        return NULL;
    }
    array_list *list = malloc(sizeof(array_list));
    if (list == NULL) {
        return NULL;
    }
    list->array = malloc(sizeof(al_data) * capacity);
    if (list->array == NULL) {
        free(list);
        return NULL;
    }
    list->capacity = capacity;
    list->count = 0;

    return list;
}
void al_insert(array_list *list, size_t pos, al_data data)
{
    if (list == NULL || pos > list->count ||
        list->count >= list->capacity) {
        return;
    }
    for (size_t i = list->count; i > pos; i--) {
        list->array[i] = list->array[i - 1];
    }
    list->array[pos] = data;
    list->count++;
}
void al_delete(array_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    for (size_t i = pos; i < list->count - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    list->count--;
}
al_data al_get(array_list *list, size_t pos)
{
    return list->array[pos];
}
size_t al_size(array_list *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->count;
}
void al_destroy(array_list *list)
{
    if (list == NULL) {
        return;
    }
    free(list->array);
    free(list);
}
