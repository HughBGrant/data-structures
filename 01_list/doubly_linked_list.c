#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _dl_node {
    DLItem data;
    struct _dl_node *next;
    struct _dl_node *prev;
} dl_node;

struct DoublyLinkedList {
    dl_node *head_sentinel;
    dl_node *tail_sentinel;
    size_t size;
};

static dl_node *dl_node_create(DLItem data);
static void dl_node_destroy(dl_node *node);
static dl_node *dl_node_get(DLList *list, size_t pos);

static dl_node *dl_node_create(DLItem data)
{
    dl_node *new_node = malloc(sizeof(dl_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
static void dl_node_destroy(dl_node *node)
{
    free(node);
}
static dl_node *dl_node_get(DLList *list, size_t pos)
{
    if (list == NULL || pos > list->size) {
        return NULL;
    }
    if (pos == list->size) {
        return list->tail_sentinel;
    }
    dl_node *target_node = NULL;

    if (pos < list->size / 2) {
        target_node = list->head_sentinel->next;

        for (size_t i = 0; i < pos; i++) {
            target_node = target_node->next;
        }
    } else {
        target_node = list->tail_sentinel->prev;

        for (size_t i = list->size - 1; i > pos; i--) {
            target_node = target_node->prev;
        }
    }

    return target_node;
}
DLList *dl_create(void)
{
    DLList *list = malloc(sizeof(DLList));
    if (list == NULL) {
        return NULL;
    }

    list->head_sentinel = dl_node_create(0);
    if (list->head_sentinel == NULL) {
        free(list);
        return NULL;
    }
    list->tail_sentinel = dl_node_create(0);
    if (list->tail_sentinel == NULL) {
        dl_node_destroy(list->head_sentinel);
        free(list);
        return NULL;
    }

    list->size = 0;
    list->head_sentinel->next = list->tail_sentinel;
    list->tail_sentinel->prev = list->head_sentinel;

    return list;
}
void dl_destroy(DLList *list)
{
    if (list == NULL) {
        return;
    }

    while (list->size > 0) {
        dl_delete(list, 0);
    }

    dl_node_destroy(list->head_sentinel);
    dl_node_destroy(list->tail_sentinel);
    free(list);
}
void dl_insert(DLList *list, size_t pos, DLItem data)
{
    if (list == NULL || pos > list->size) {
        return;
    }

    dl_node *new_node = dl_node_create(data);
    if (new_node == NULL) {
        return;
    }

    dl_node *next_node = dl_node_get(list, pos);

    next_node->prev->next = new_node;
    new_node->prev = next_node->prev;

    new_node->next = next_node;
    next_node->prev = new_node;

    list->size++;
}
DLItem dl_delete(DLList *list, size_t pos)
{
    if (list == NULL || pos >= list->size) {
        return 0;
    }

    dl_node *target_node = dl_node_get(list, pos);
    if (target_node == NULL) {
        return 0;
    }

    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;

    DLItem data = target_node->data;
    dl_node_destroy(target_node);
    list->size--;
    return data;
}
DLItem dl_get(DLList *list, size_t pos)
{
    if (list == NULL || pos >= list->size) {
        return 0;
    }

    return dl_node_get(list, pos)->data;
}
void dl_print(DLList *list)
{
    if (list == NULL || list->head_sentinel == NULL) {
        return;
    }
    dl_node *current_node = list->head_sentinel->next;

    while (current_node != list->tail_sentinel) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
size_t dl_size(DLList *list)
{
    return list ? list->size : 0;
}