#include "circular_doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _cdll_node {
    CDLItem data;
    struct _cdll_node *next;
    struct _cdll_node *prev;
} cdll_node;

struct CircularDoublyLinkedList {
    cdll_node *sentinel;
    size_t size;
};

static cdll_node *cdll_node_create(CDLItem value);

static void cdll_node_destroy(cdll_node *node);

static cdll_node *cdll_node_get(CDLList *list, size_t index);

static cdll_node *cdll_node_create(CDLItem value)
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
static cdll_node *cdll_node_get(CDLList *list, size_t index)
{
    if (list == NULL || index > list->size) {
        return NULL;
    }
    if (index == list->size) {
        return list->sentinel; // 센티널 반환
    }

    cdll_node *target_node = NULL;

    if (index < list->size / 2) {
        target_node = list->sentinel->next;

        for (size_t i = 0; i < index; i++) {
            target_node = target_node->next;
        }
    } else {
        target_node = list->sentinel->prev;

        for (size_t i = list->size - 1; i > index; i--) {
            target_node = target_node->prev;
        }
    }
    return target_node;
}
CDLList *cdll_create(void)
{
    CDLList *list = malloc(sizeof(CDLList));
    if (list == NULL) {
        return NULL;
    }
    list->sentinel = cdll_node_create(0);
    if (list->sentinel == NULL) {
        free(list);
        return NULL;
    }

    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    list->size = 0;

    return list;
}
void cdll_destroy(CDLList *list)
{
    if (list == NULL) {
        return;
    }
    while (list->size > 0) {
        cdll_delete(list, 0);
    }
    cdll_node_destroy(list->sentinel);
    free(list);
}
void cdll_insert(CDLList *list, size_t index, CDLItem value)
{
    if (list == NULL || index > list->size) {
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

    list->size++;
}
CDLItem cdll_delete(CDLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
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
    CDLItem data = target_node->data;
    cdll_node_destroy(target_node);

    list->size--;
    return data;
}
CDLItem cdll_get(CDLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    return cdll_node_get(list, index)->data;
}
void cdll_print(CDLList *list)
{
    if (list == NULL || list->sentinel == NULL) {
        return;
    }
    cdll_node *current_node = list->sentinel->next;

    while (current_node != list->sentinel) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }

    printf("<- head\n");
}
size_t cdll_size(CDLList *list)
{
    return list ? list->size : 0;
}