#include "circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _cll_node {
    cll_item data;
    struct _cll_node *next;
} cll_node;

struct circular_linked_list {
    cll_node *tail;
    size_t size;
};

static cll_node *cll_node_create(cll_item value);
static void cll_node_destroy(cll_node *node);

static cll_node *cll_node_create(cll_item value)
{
    cll_node *new_node = malloc(sizeof(cll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}
static void cll_node_destroy(cll_node *node)
{
    free(node);
}
cll_list *cll_create(void)
{
    cll_list *list = malloc(sizeof(cll_list));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->tail = NULL;

    return list;
}
void cll_destroy(cll_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->tail) {
        cll_delete(list, 0);
    }
    free(list);
}
void cll_insert(cll_list *list, size_t index, cll_item value)
{
    if (list == NULL || index > list->size) {
        return;
    }
    cll_node *new_node = cll_node_create(value);
    if (new_node == NULL) {
        return;
    }
    if (list->tail == NULL) {
        new_node->next = new_node;
        list->tail = new_node;
    } else {
        cll_node *prev_node = list->tail;

        for (size_t i = 0; i < index; i++) {
            prev_node = prev_node->next;
        }
        new_node->next = prev_node->next;
        prev_node->next = new_node;

        if (prev_node == list->tail) {
            list->tail = new_node;
        }
    }
    list->size++;
}
cll_item cll_delete(cll_list *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    cll_node *prev_node = list->tail;

    for (size_t i = 0; i < index; i++) {
        prev_node = prev_node->next;
    }
    cll_node *target_node = prev_node->next;

    if (prev_node == target_node) {
        list->tail = NULL;
    } else {
        prev_node->next = target_node->next;

        if (list->tail == target_node) {
            list->tail = prev_node;
        }
    }
    cll_item data = target_node->data;
    cll_node_destroy(target_node);
    list->size--;
    return data;
}
cll_item cll_get(cll_list *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }

    if (index == list->size - 1) {
        return list->tail->data;
    }

    cll_node *target_node = list->tail->next;
    for (size_t i = 0; i < index; i++) {
        target_node = target_node->next;
    }
    return target_node->data;
}
void cll_print(cll_list *list)
{
    if (list == NULL || list->tail == NULL) {
        return;
    }
    cll_node *current_node = list->tail->next;

    do {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    } while (current_node != list->tail->next);

    printf("head\n");
}
size_t cll_size(cll_list *list)
{
    return list ? list->size : 0;
}