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
    list->items = malloc(sizeof(al_data) * capacity);
    if (list->items == NULL) {
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
al_data *al_get(array_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }
    return &list->items[pos];
}
int al_linear_search_transpose(array_list *list, al_data key)
{
    if (list == NULL) {
        return -1;
    }
    int pos = 0;

    while (pos < list->count && list->items[pos] != key) {
        pos++;
    }
    if (pos == list->count) {
        return -1;
    }
    if (pos > 0) {
        al_data temp = list->items[pos - 1];
        list->items[pos - 1] = list->items[pos];
        list->items[pos] = temp;
        pos--;
    }
    return pos;
}
int al_linear_search_move2front(array_list *list, al_data key)
{
    if (list == NULL) {
        return -1;
    }
    int pos = 0;

    while (pos < list->count && list->items[pos] != key) {
        pos++;
    }
    if (pos == list->count) {
        return -1;
    }
    while (pos > 0) {
        list->items[pos] = list->items[pos - 1];
        pos--;
    }
    list->items[0] = key;

    return pos;
}
int al_binary_search(array_list *list, al_data key)
{
    if (list == NULL) {
        return -1;
    }
    int left = 0;
    int mid = 0;
    int right = list->count - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (key == list->items[mid]) {
            return mid;
        }
        if (key < list->items[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
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
