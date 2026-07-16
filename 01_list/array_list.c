#include "array_list.h"

array_list *al_create(size_t max_size)
{
    if (max_size == 0) {
        return NULL;
    }
    array_list *list = malloc(sizeof(array_list));
    if (list == NULL) {
        return NULL;
    }
    list->items = malloc(sizeof(al_data) * max_size);
    if (list->items == NULL) {
        free(list);
        return NULL;
    }
    list->max_size = max_size;
    list->count = 0;

    return list;
}
void al_insert(array_list *list, size_t pos, al_data data)
{
    if (list == NULL || pos > list->count ||
        list->count >= list->max_size) {
        return;
    }
    for (size_t i = list->count; i > pos; i--) {
        list->items[i] = list->items[i - 1];
    }
    list->items[pos] = data;
    list->count++;
}
void al_delete(array_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    for (size_t i = pos; i < list->count - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->count--;
}
al_data al_get(array_list *list, size_t pos)
{
    return list->items[pos];
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
    free(list->items);
    free(list);
}
