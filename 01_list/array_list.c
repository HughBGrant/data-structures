#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8

struct array_list {
    al_item *items;
    size_t capacity;
    size_t count;
};

static int al_linear_search_transpose(al_list *list, al_item key);

static int al_linear_search_move2front(al_list *list, al_item key);

static int al_binary_search(al_list *list, al_item key);

static int al_linear_search_transpose(al_list *list, al_item key)
{
    if (list == NULL) {
        return -1;
    }
    int index = 0;

    while (index < list->count && list->items[index] != key) {
        index++;
    }
    if (index == list->count) {
        return -1;
    }
    if (index > 0) {
        al_item temp = list->items[index - 1];
        list->items[index - 1] = list->items[index];
        list->items[index] = temp;
        index--;
    }
    return index;
}
static int al_linear_search_move2front(al_list *list, al_item key)
{
    if (list == NULL) {
        return -1;
    }
    int index = 0;

    while (index < list->count && list->items[index] != key) {
        index++;
    }
    if (index == list->count) {
        return -1;
    }
    while (index > 0) {
        list->items[index] = list->items[index - 1];
        index--;
    }
    list->items[0] = key;

    return index;
}
static int al_binary_search(al_list *list, al_item key)
{
    if (list == NULL) {
        return -1;
    }
    int left = 0;
    int mid = 0;
    int right = (int)list->count - 1;

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
al_list *al_create(void)
{
    al_list *list = malloc(sizeof(al_list));
    if (list == NULL) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    list->items = malloc(sizeof(al_item) * capacity);
    if (list->items == NULL) {
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
    free(list->items);
    free(list);
}

void al_insert(al_list *list, size_t index, al_item data)
{
    if (list == NULL || index > list->count) {
        return;
    }
    if (list->count == list->capacity) {
        size_t new_capacity = list->capacity * 2;

        al_item *new_items = realloc(list->items, sizeof(al_item) * new_capacity);
        if (new_items == NULL) {
            return; // 메모리 부족
        }

        list->items = new_items;
        list->capacity = new_capacity;
    }

    for (size_t i = list->count; i > index; i--) {
        list->items[i] = list->items[i - 1];
    }
    list->items[index] = data;
    list->count++;
}
al_item al_delete(al_list *list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return 0;
    }
    al_item data = list->items[index];
    for (size_t i = index; i < list->count - 1; i++) {
        list->items[i] = list->items[i + 1];
    }
    list->count--;
    return data;
}
al_item al_get(al_list *list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return 0;
    }
    return list->items[index];
}
void al_print(al_list *list)
{
    if (list == NULL) {
        return;
    }
    printf("| ");
    for (size_t index = 0; index < list->count; index++) {
        printf("%d | ", list->items[index]);
    }
}
size_t al_size(al_list *list)
{
    return list ? list->count : 0;
}