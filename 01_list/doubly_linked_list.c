#include "doubly_linked_list.h"

dll_list *dll_create(void)
{
    dll_list *list = malloc(sizeof(dll_list));
    if (list == NULL) {
        return NULL;
    }

    list->null_head = dll_node_create(0);
    if (list->null_head == NULL) {
        free(list);
        return NULL;
    }
    list->null_tail = dll_node_create(0);
    if (list->null_tail == NULL) {
        dll_node_destroy(list->null_head);
        free(list);
        return NULL;
    }

    list->size = 0;
    list->null_head->next = list->null_tail;
    list->null_tail->prev = list->null_head;

    return list;
}
void dll_destroy(dll_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->size > 0) {
        dll_delete(list, 0);
    }

    dll_node_destroy(list->null_head);
    dll_node_destroy(list->null_tail);
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
    if (list == NULL || pos > list->size) {
        return NULL;
    }
    if (pos == list->size) {
        return list->null_tail;
    }
    dll_node *target_node = NULL;

    if (pos < list->size / 2) {
        target_node = list->null_head->next;

        for (size_t i = 0; i < pos; i++) {
            target_node = target_node->next;
        }
    } else {
        target_node = list->null_tail->prev;

        for (size_t i = list->size - 1; i > pos; i--) {
            target_node = target_node->prev;
        }
    }

    return target_node;
}
void dll_insert(dll_list *list, size_t pos, dll_data data)
{
    if (list == NULL || pos > list->size) {
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

    list->size++;
}
dll_data dll_delete(dll_list *list, size_t pos)
{
    if (list == NULL || pos >= list->size) {
        return 0;
    }

    dll_node *target_node = dll_node_get(list, pos);
    if (target_node == NULL) {
        return 0;
    }

    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;

    dll_data data = target_node->data;
    dll_node_destroy(target_node);
    list->size--;
    return data;
}
dll_data dll_get(dll_list *list, size_t pos)
{
    if (list == NULL || pos >= list->size) {
        return 0;
    }

    return dll_node_get(list, pos)->data;
}
void dll_print(dll_list *list)
{
    if (list == NULL || list->null_head == NULL) {
        return;
    }
    dll_node *current_node = list->null_head->next;

    while (current_node != list->null_tail) {
        printf("<- %d ->", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
size_t dll_size(dll_list *list)
{
    return list ? list->size : 0;
}