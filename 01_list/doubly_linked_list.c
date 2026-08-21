#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _dll_node {
    dll_item data;
    struct _dll_node *next;
    struct _dll_node *prev;
} dll_node;

struct doubly_linked_list {
    dll_node *head_sentinel;
    size_t count;
};

static dll_node *dll_node_create(dll_item value);

static void dll_node_destroy(dll_node *node);

static dll_node *dll_node_get(dll_list *list, size_t index);

static dll_node *dll_node_create(dll_item value)
{
    dll_node *new_node = malloc(sizeof(dll_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
static void dll_node_destroy(dll_node *node)
{
    free(node);
}
static dll_node *dll_node_get(dll_list *list, size_t index)
{
    if (list == NULL || index > list->count) {
        return NULL;
    }
    if (index == list->count) {
        return list->head_sentinel; // 센티널 반환
    }

    dll_node *target_node = NULL;

    if (index < list->count / 2) {
        target_node = list->head_sentinel->next;

        for (size_t i = 0; i < index; i++) {
            target_node = target_node->next;
        }
    } else {
        target_node = list->head_sentinel->prev;

        for (size_t i = list->count - 1; i > index; i--) {
            target_node = target_node->prev;
        }
    }
    return target_node;
}
dll_list *dll_create(void)
{
    dll_list *list = malloc(sizeof(dll_list));
    if (list == NULL) {
        return NULL;
    }
    list->head_sentinel = dll_node_create(0);
    if (list->head_sentinel == NULL) {
        free(list);
        return NULL;
    }

    list->head_sentinel->next = list->head_sentinel;
    list->head_sentinel->prev = list->head_sentinel;
    list->count = 0;

    return list;
}
void dll_destroy(dll_list *list)
{
    if (list == NULL) {
        return;
    }
    while (list->count > 0) {
        dll_remove(list, 0);
    }
    dll_node_destroy(list->head_sentinel);
    free(list);
}
void dll_insert(dll_list *list, size_t index, dll_item value)
{
    if (list == NULL || index > list->count) {
        return;
    }

    dll_node *new_node = dll_node_create(value);
    if (new_node == NULL) {
        return;
    }

    dll_node *next_node = dll_node_get(list, index);
    if (next_node == NULL) {
        return;
    }
    dll_node *prev_node = next_node->prev;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    new_node->next = next_node;
    next_node->prev = new_node;

    list->count++;
}
void dll_remove(dll_list *list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return;
    }
    dll_node *target_node = dll_node_get(list, index);
    if (target_node == NULL) {
        return;
    }
    dll_node *prev_node = target_node->prev;
    dll_node *next_node = target_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    dll_node_destroy(target_node);

    list->count--;
}
dll_item *dll_get(dll_list *list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return NULL;
    }
    return &dll_node_get(list, index)->data;
}
void dll_print(dll_list *list)
{
    if (list == NULL || list->head_sentinel == NULL) {
        return;
    }
    dll_node *current_node = list->head_sentinel->next;

    while (current_node != list->head_sentinel) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }

    printf("<- head\n");
}
size_t dll_size(dll_list *list)
{
    return list ? list->count : 0;
}