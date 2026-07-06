#include "linked_list.h"

linked_list *ll_create(void)
{
    linked_list *list = malloc(sizeof(linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}
ll_node *ll_create_node(ll_data data)
{
    ll_node *new_node = malloc(sizeof(ll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
void ll_append(linked_list *list, ll_data data)
{
    ll_node *new_tail = ll_create_node(data);
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

void ll_insert(linked_list *list, size_t pos, ll_data data)
{
    if (pos > list->count) {
        return;
    }
    ll_node *new_node = ll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    ll_node *previous = NULL;
    ll_node *current = list->head;

    for (; pos > 0; pos--) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        list->tail = new_node;
    }
    if (current == list->head) {
        list->head = new_node;
    } else {
        previous->next = new_node;
    }
    new_node->next = current;

    list->count++;
}
void ll_delete(linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    ll_node *previous = NULL;
    ll_node *current = list->head;
    for (; pos > 0; pos--) {
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
ll_data ll_get(linked_list *list, size_t pos)
{
    if (pos == ll_size(list) - 1) {
        return list->tail->data;
    }

    ll_node *current = list->head;
    for (; pos > 0; pos--) {
        current = current->next;
    }
    return current->data;
}

size_t ll_size(linked_list *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->count;
}
void ll_destroy(linked_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->count > 0) {
        ll_delete(list, 0);
    }
    free(list);
}