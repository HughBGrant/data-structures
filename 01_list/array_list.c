#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>

al_list *al_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    al_list *list = malloc(sizeof(al_list));
    if (list == NULL) {
        return NULL;
    }
    list->data = malloc(sizeof(al_item) * capacity);
    if (list->data == NULL) {
        free(list);
        return NULL;
    }
    list->capacity = capacity;
    list->count = 0;

    return list;
}
void al_destroy(al_list *list)
{
    if (list == NULL) {
        return;
    }
    free(list->data);
    free(list);
}

void al_insert(al_list *list, size_t pos, al_item data)
{
    if (list == NULL || pos > list->count) {
        return;
    }
    if (list->count == list->capacity) {
        size_t new_capacity = list->capacity * 2;

        al_item *new_items = realloc(list->data, sizeof(al_item) * new_capacity);
        if (new_items == NULL) {
            return; // 메모리 부족
        }

        list->data = new_items;
        list->capacity = new_capacity;
    }

    for (size_t i = list->count; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[pos] = data;
    list->count++;
}
void al_remove(al_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    for (size_t i = pos; i < list->count - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->count--;
}
al_item *al_get(al_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }
    return &list->data[pos];
}
int al_linear_search_transpose(al_list *list, al_item key)
{
    if (list == NULL) {
        return -1;
    }
    int pos = 0;

    while (pos < list->count && list->data[pos] != key) {
        pos++;
    }
    if (pos == list->count) {
        return -1;
    }
    if (pos > 0) {
        al_item temp = list->data[pos - 1];
        list->data[pos - 1] = list->data[pos];
        list->data[pos] = temp;
        pos--;
    }
    return pos;
}
int al_linear_search_move2front(al_list *list, al_item key)
{
    if (list == NULL) {
        return -1;
    }
    int pos = 0;

    while (pos < list->count && list->data[pos] != key) {
        pos++;
    }
    if (pos == list->count) {
        return -1;
    }
    while (pos > 0) {
        list->data[pos] = list->data[pos - 1];
        pos--;
    }
    list->data[0] = key;

    return pos;
}
int al_binary_search(al_list *list, al_item key)
{
    if (list == NULL) {
        return -1;
    }
    int left = 0;
    int mid = 0;
    int right = (int)list->count - 1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (key == list->data[mid]) {
            return mid;
        }
        if (key < list->data[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
void al_print(al_list *list)
{
    if (list == NULL) {
        return;
    }
    printf("| ");
    for (size_t index = 0; index < list->count; index++) {
        printf("%d | ", list->data[index]);
    }
}
size_t al_size(al_list *list)
{
    return list ? list->count : 0;
}