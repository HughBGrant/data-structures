#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

sll_list *sll_create(void)
{
    sll_list *list = malloc(sizeof(sll_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;

    return list;
}
void sll_destroy(sll_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->head) {
        sll_remove(list, 0);
    }
    free(list);
}
sll_node *sll_node_create(sll_data data)
{
    sll_node *new_node = malloc(sizeof(sll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
void sll_node_destroy(sll_node *node)
{
    free(node);
}
void sll_insert(sll_list *list, size_t pos, sll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }
    sll_node *new_node = sll_node_create(data);
    if (new_node == NULL) {
        return;
    }
    if (pos == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        sll_node *prev = list->head;
        for (size_t i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }

    list->count++;
}
void sll_remove(sll_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    sll_node *target_node = NULL;

    if (pos == 0) {
        target_node = list->head;
        list->head = target_node->next;
    } else {
        sll_node *prev_node = list->head;

        for (size_t i = 0; i < pos - 1; i++) {
            prev_node = prev_node->next;
        }
        target_node = prev_node->next;
        prev_node->next = target_node->next;
    }
    sll_node_destroy(target_node);
    list->count--;
}
sll_data *sll_get(sll_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }
    sll_node *target_node = list->head;

    for (size_t i = 0; i < pos; i++) {
        target_node = target_node->next;
    }
    return &target_node->data;
}
sll_node *sll_linear_search_move2front(sll_list *list, sll_data key)
{
    if (list == NULL) {
        return NULL;
    }
    sll_node *prev_node = NULL;
    sll_node *current_node = list->head;

    while (current_node && current_node->data != key) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        return NULL;
    }
    if (prev_node) {
        prev_node->next = current_node->next;
        current_node->next = list->head;
        list->head = current_node;
    }
    return current_node;
}
sll_node *sll_linear_search_transpose(sll_list *list, sll_data key)
{
    if (list == NULL) {
        return NULL;
    }
    sll_node *prev_prev_node = NULL;
    sll_node *prev_node = NULL;
    sll_node *current_node = list->head;

    while (current_node && current_node->data != key) {
        prev_prev_node = prev_node;
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return NULL;
    }
    if (prev_node) {
        prev_node->next = current_node->next;
        current_node->next = prev_node;

        if (prev_prev_node) {
            prev_prev_node->next = current_node;
        } else {
            list->head = current_node;
        }
    }
    return current_node;
}
void sll_print(sll_list *list)
{
    if (list == NULL || list->head == NULL) {
        return;
    }
    sll_node *current_node = list->head;

    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
size_t sll_size(sll_list *list)
{
    return list ? list->count : 0;
}