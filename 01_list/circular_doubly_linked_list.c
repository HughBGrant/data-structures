#include "circular_doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _cdll_node {
    cdll_item data;
    struct _cdll_node *next;
    struct _cdll_node *prev;
} cdll_node;

struct doubly_linked_list {
    cdll_node *head_sentinel;
    size_t count;
};

static cdll_node *cdll_node_create(cdll_item value);

static void cdll_node_destroy(cdll_node *node);

static cdll_node *cdll_node_get(cdll_list *list, size_t index);

static cdll_node *cdll_node_create(cdll_item value)
{
    cdll_node *new_node = malloc(sizeof(cdll_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
static void cdll_node_destroy(cdll_node *node)
{
    free(node);
}
static cdll_node *cdll_node_get(cdll_list *list, size_t index)
{
    if (list == NULL || index > list->count) {
        return NULL;
    }
    if (index == list->count) {
        return list->head_sentinel; // 센티널 반환
    }

    cdll_node *target_node = NULL;

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
cdll_list *cdll_create(void)
{
    cdll_list *list = malloc(sizeof(cdll_list));
    if (list == NULL) {
        return NULL;
    }
    list->head_sentinel = cdll_node_create(0);
    if (list->head_sentinel == NULL) {
        free(list);
        return NULL;
    }

    list->head_sentinel->next = list->head_sentinel;
    list->head_sentinel->prev = list->head_sentinel;
    list->count = 0;

    return list;
}
void cdll_destroy(cdll_list *list)
{
    if (list == NULL) {
        return;
    }
    while (list->count > 0) {
        cdll_delete(list, 0);
    }
    cdll_node_destroy(list->head_sentinel);
    free(list);
}
void cdll_insert(cdll_list *list, size_t index, cdll_item value)
{
    if (list == NULL || index > list->count) {
        return;
    }

    cdll_node *new_node = cdll_node_create(value);
    if (new_node == NULL) {
        return;
    }

    cdll_node *next_node = cdll_node_get(list, index);
    if (next_node == NULL) {
        return;
    }
    cdll_node *prev_node = next_node->prev;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    new_node->next = next_node;
    next_node->prev = new_node;

    list->count++;
}
cdll_item cdll_delete(cdll_list *list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return 0;
    }
    cdll_node *target_node = cdll_node_get(list, index);
    if (target_node == NULL) {
        return 0;
    }
    cdll_node *prev_node = target_node->prev;
    cdll_node *next_node = target_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    cdll_item data = target_node->data;
    cdll_node_destroy(target_node);

    list->count--;
    return data;
}
cdll_item cdll_get(cdll_list *list, size_t index)
{
    if (list == NULL || index >= list->count) {
        return 0;
    }
    return cdll_node_get(list, index)->data;
}
void cdll_print(cdll_list *list)
{
    if (list == NULL || list->head_sentinel == NULL) {
        return;
    }
    cdll_node *current_node = list->head_sentinel->next;

    while (current_node != list->head_sentinel) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }

    printf("<- head\n");
}
size_t cdll_size(cdll_list *list)
{
    return list ? list->count : 0;
}