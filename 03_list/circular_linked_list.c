#include "circular_linked_list.h"

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
    if (list == NULL) {
        return;
    }
    cll_node *new_tail = cll_create_node(data);
    if (new_tail == NULL) {
        return;
    }

    if (list->tail) {
        new_tail->next = list->tail->next;
        list->tail->next = new_tail;
    } else {
        new_tail->next = new_tail;
    }
    list->tail = new_tail;

    list->count++;
}

void cll_insert(circular_linked_list *list, size_t pos, cll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }

    if (pos == list->count) {
        cll_append(list, data);
        return;
    }
    cll_node *new_node = cll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    cll_node *prev_node = list->tail;
    cll_node *next_node = prev_node->next;

    while (pos > 0) {
        prev_node = next_node;
        next_node = next_node->next;
        pos--;
    }
    prev_node->next = new_node;
    new_node->next = next_node;

    list->count++;
}

void cll_delete(circular_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }

    cll_node *prev_node = list->tail;
    cll_node *free_node = prev_node->next;

    while (pos > 0) {
        prev_node = free_node;
        free_node = free_node->next;
        pos--;
    }

    if (prev_node == free_node) {
        list->tail = NULL;
    } else {
        prev_node->next = free_node->next;

        if (list->tail == free_node) {
            list->tail = prev_node;
        }
    }

    printf("Destroying Node : %d\n", free_node->data);
    free(free_node);
    list->count--;
}
cll_data cll_get(circular_linked_list *list, size_t pos)
{
    if (pos == list->count - 1) {
        return list->tail->data;
    }

    cll_node *get_node = list->tail->next;
    while (pos > 0) {
        get_node = get_node->next;
        pos--;
    }
    return get_node->data;
}
size_t cll_size(circular_linked_list *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->count;
}
void cll_destroy(circular_linked_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->tail) {
        cll_delete(list, 0);
    }
    free(list);
}
