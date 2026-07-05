#include "circular_linked_list.h"

circular_linked_list *cll_create(void)
{
    circular_linked_list *list = malloc(sizeof(circular_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}
cll_node *cll_create_node(cll_data data)
{
    cll_node *new_node = malloc(sizeof(cll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
void cll_append(circular_linked_list *list, cll_data data)
{
    cll_node *new_tail = cll_create_node(data);
    if (new_tail == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = new_tail;
    } else {
        list->tail->next = new_tail;
    }
    list->tail = new_tail;
    list->count++;
}
cll_node *cll_get(circular_linked_list *list, size_t pos) //////
{
    if (pos >= cll_size(list)) {
        return NULL;
    }
    if (pos == cll_size(list) - 1) {
        return list->tail;
    }

    cll_node *current = list->head;
    while (current != NULL && pos > 0) {
        current = current->next;
        pos--;
    }
    return current;
}
void cll_insert(circular_linked_list *list, size_t pos, cll_data data)
{
    cll_node *new_node = cll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    cll_node *previous = NULL;
    cll_node *current = list->head;
    for (size_t i = 0; i < pos; i++) {
        previous = current;
        current = current->next;
    }
    if (current == list->head) {
        list->head = new_node;
    } else {
        previous->next = new_node;
    }
    new_node->next = current;
    list->count++;
}
void cll_delete(circular_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }

    cll_node *previous = NULL;
    cll_node *current = list->head;
    for (size_t i = 0; i < pos; i++) {
        previous = current;
        current = current->next;
    }
    if (current == list->head) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    if (current == list->tail) {
        list->tail = NULL;
    }
    printf("Destroying Node : %d\n", current->data);
    free(current);
    list->count--;
}
void cll_destroy(circular_linked_list *list)
{
    if (list == NULL) {
        return;
    }
    cll_node *current = list->head;

    while (list->count > 0) {
        cll_delete(list, 0);
    }
    free(list);
}
size_t cll_size(circular_linked_list *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->count;
}