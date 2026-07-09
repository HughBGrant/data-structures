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
    if (list == NULL) {
        return;
    }
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
    if (list == NULL) {
        return;
    }
    size_t size = ll_size(list);
    if (pos > size) {
        return;
    }
    if (pos == size) {
        ll_append(list, data);
        return;
    }
    ll_node *new_node = ll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    ll_node *prev_node = NULL;
    ll_node *next_node = list->head;

    while (pos > 0) {
        prev_node = next_node;
        next_node = next_node->next;
        pos--;
    }
    if (list->head == next_node) {
        list->head = new_node;
    } else {
        prev_node->next = new_node;
    }
    new_node->next = next_node;

    list->count++;
}
void ll_delete(linked_list *list, size_t pos)
{
    if (list == NULL || pos >= ll_size(list)) {
        return;
    }
    ll_node *prev_node = NULL;
    ll_node *free_node = list->head;
    while (pos > 0) {
        prev_node = free_node;
        free_node = free_node->next;
        pos--;
    }
    if (list->head == free_node) {
        list->head = free_node->next;
    } else {
        prev_node->next = free_node->next;
    }
    if (list->tail == free_node) {
        list->tail = NULL;
    }
    printf("Destroying Node : %d\n", free_node->data);
    free(free_node);
    list->count--;
}
ll_data ll_get(linked_list *list, size_t pos)
{
    if (pos == ll_size(list) - 1) {
        return list->tail->data;
    }

    ll_node *get_node = list->head;
    while (pos > 0) {
        get_node = get_node->next;
        pos--;
    }
    return get_node->data;
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

    while (list->head != NULL) {
        ll_delete(list, 0);
    }
    free(list);
}