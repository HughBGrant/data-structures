#include "circular_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

circular_linked_list *cll_create(void)
{
    circular_linked_list *list = malloc(sizeof(circular_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->tail = NULL;

    return list;
}
void cll_destroy(circular_linked_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->tail) {
        cll_remove(list, 0);
    }
    free(list);
}
cll_node *cll_node_create(cll_data data)
{
    cll_node *new_node = malloc(sizeof(cll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
void cll_node_destroy(cll_node *node)
{
    free(node);
}
void cll_insert(circular_linked_list *list, size_t pos, cll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }
    cll_node *new_node = cll_node_create(data);
    if (new_node == NULL) {
        return;
    }
    if (list->tail == NULL) {
        new_node->next = new_node;
        list->tail = new_node;
    } else {
        cll_node *prev_node = list->tail;

        for (size_t i = 0; i < pos; i++) {
            prev_node = prev_node->next;
        }
        new_node->next = prev_node->next;
        prev_node->next = new_node;

        if (prev_node == list->tail) {
            list->tail = new_node;
        }
    }
    list->count++;
}
void cll_remove(circular_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    cll_node *prev_node = list->tail;

    for (size_t i = 0; i < pos; i++) {
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
    cll_node_destroy(target_node);
    list->count--;
}
cll_data *cll_get(circular_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }

    if (pos == list->count - 1) {
        return &list->tail->data;
    }

    cll_node *target_node = list->tail->next;
    for (size_t i = 0; i < pos; i++) {
        target_node = target_node->next;
    }
    return &target_node->data;
}
void cll_print(circular_linked_list *list)
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
size_t cll_size(circular_linked_list *list)
{
    return list ? list->count : 0;
}