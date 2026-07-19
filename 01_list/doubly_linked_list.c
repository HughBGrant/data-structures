#include "doubly_linked_list.h"

doubly_linked_list *dll_create(void)
{
    doubly_linked_list *list = malloc(sizeof(doubly_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->head_sentinel = dll_create_node(0);
    if (list->head_sentinel == NULL) {
        free(list);
        return NULL;
    }
    list->tail_sentinel = dll_create_node(0);
    if (list->tail_sentinel == NULL) {
        free(list->head_sentinel);
        free(list);
        return NULL;
    }

    list->count = 0;
    list->head_sentinel->next = list->tail_sentinel;
    list->tail_sentinel->prev = list->head_sentinel;

    return list;
}
dll_node *dll_create_node(dll_data data)
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
dll_node *dll_get_node(doubly_linked_list *list, size_t pos)
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
void dll_insert(doubly_linked_list *list, size_t pos, dll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }

    dll_node *new_node = dll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    dll_node *next_node = dll_get_node(list, pos);

    new_node->prev = next_node->prev;
    new_node->next = next_node;

    next_node->prev->next = new_node;
    next_node->prev = new_node;

    list->count++;
}
void dll_delete(doubly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }

    dll_node *target_node = dll_get_node(list, pos);
    if (target_node == NULL) {
        return;
    }

    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;

    free(target_node);
    list->count--;
}
dll_data *dll_get(doubly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }

    return &dll_get_node(list, pos)->data;
}
size_t dll_size(doubly_linked_list *list)
{
    if (list == NULL) {
        return 0;
    }

    return list->count;
}
void dll_print(doubly_linked_list *list)
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
void dll_destroy(doubly_linked_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->count > 0) {
        dll_delete(list, 0);
    }

    free(list->head_sentinel);
    free(list->tail_sentinel);
    free(list);
}
