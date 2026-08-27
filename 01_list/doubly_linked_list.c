#include "doubly_linked_list.h"

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
    list->tail_sentinel = dll_node_create(0);
    if (list->tail_sentinel == NULL) {
        dll_node_destroy(list->head_sentinel);
        free(list);
        return NULL;
    }

    list->count = 0;
    list->head_sentinel->next = list->tail_sentinel;
    list->tail_sentinel->prev = list->head_sentinel;

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
    dll_node_destroy(list->tail_sentinel);
    free(list);
}
dll_node *dll_node_create(dll_data data)
{
    dll_node *new_node = malloc(sizeof(dll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
void dll_node_destroy(dll_node *node)
{
    free(node);
}
dll_node *dll_node_get(dll_list *list, size_t pos)
{
    if (list == NULL || pos > list->count) {
        return NULL;
    }
    if (pos == list->count) {
        return list->tail_sentinel;
    }
    dll_node *target_node = NULL;

    if (pos < list->count / 2) {
        target_node = list->head_sentinel->next;

        for (size_t i = 0; i < pos; i++) {
            target_node = target_node->next;
        }
    } else {
        target_node = list->tail_sentinel->prev;

        for (size_t i = list->count - 1; i > pos; i--) {
            target_node = target_node->prev;
        }
    }

    return target_node;
}
void dll_insert(dll_list *list, size_t pos, dll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }

    dll_node *new_node = dll_node_create(data);
    if (new_node == NULL) {
        return;
    }

    dll_node *next_node = dll_node_get(list, pos);

    next_node->prev->next = new_node;
    new_node->prev = next_node->prev;

    new_node->next = next_node;
    next_node->prev = new_node;

    list->count++;
}
void dll_remove(dll_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }

    dll_node *target_node = dll_node_get(list, pos);
    if (target_node == NULL) {
        return;
    }

    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;

    dll_node_destroy(target_node);
    list->count--;
}
dll_data *dll_get(dll_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }

    return &dll_node_get(list, pos)->data;
}
void dll_print(dll_list *list)
{
    if (list == NULL || list->head_sentinel == NULL) {
        return;
    }
    dll_node *current_node = list->head_sentinel->next;

    while (current_node != list->tail_sentinel) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
size_t dll_size(dll_list *list)
{
    return list ? list->count : 0;
}