#include "circular_doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _cdl_node {
    CDLItem data;
    struct _cdl_node *next;
    struct _cdl_node *prev;
} cdl_node;

struct CircularDoublyLinkedList {
    cdl_node *sentinel;
    size_t size;
};

static cdl_node *cdl_node_create(CDLItem data);

static void cdl_node_destroy(cdl_node *node);

static cdl_node *cdl_node_get(CDLList *list, size_t index);

static cdl_node *cdl_node_create(CDLItem data)
{
    cdl_node *new_node = malloc(sizeof(cdl_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
static void cdl_node_destroy(cdl_node *node)
{
    free(node);
}
static cdl_node *cdl_node_get(CDLList *list, size_t index)
{
    if (list == NULL || index > list->size) {
        return NULL;
    }
    if (index == list->size) {
        return list->sentinel; // 센티널 반환
    }

    cdl_node *target_node = NULL;

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
CDLList *cdl_create(void)
{
    CDLList *list = malloc(sizeof(CDLList));
    if (list == NULL) {
        return NULL;
    }
    list->sentinel = cdl_node_create(0);
    if (list->sentinel == NULL) {
        free(list);
        return NULL;
    }

    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    list->size = 0;

    return list;
}
void cdl_destroy(CDLList *list)
{
    if (list == NULL) {
        return;
    }
    while (list->size > 0) {
        cdl_delete(list, 0);
    }
    cdl_node_destroy(list->sentinel);
    free(list);
}
void cdl_insert(CDLList *list, size_t index, CDLItem data)
{
    if (list == NULL || index > list->size) {
        return;
    }

    cdl_node *new_node = cdl_node_create(data);
    if (new_node == NULL) {
        return;
    }

    cdl_node *next_node = cdl_node_get(list, index);
    if (next_node == NULL) {
        return;
    }
    cdl_node *prev_node = next_node->prev;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    new_node->next = next_node;
    next_node->prev = new_node;

    list->size++;
}
CDLItem cdl_delete(CDLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    cdl_node *target_node = cdl_node_get(list, index);
    if (target_node == NULL) {
        return 0;
    }
    cdl_node *prev_node = target_node->prev;
    cdl_node *next_node = target_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;
    CDLItem data = target_node->data;
    cdl_node_destroy(target_node);

    list->size--;
    return data;
}
CDLItem cdl_get(CDLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    return cdl_node_get(list, index)->data;
}
void cdl_print(CDLList *list)
{
    if (list == NULL || list->sentinel == NULL) {
        return;
    }
    cdl_node *current_node = list->sentinel->next;

    while (current_node != list->sentinel) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }

    printf("<- head\n");
}
size_t cdl_size(CDLList *list)
{
    return list ? list->size : 0;
}