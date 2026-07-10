#include "circular_doubly_linked_list.h"

c_d_linked_list *cdll_create(void) ///////
{
    c_d_linked_list *list = malloc(sizeof(c_d_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;

    return list;
}
cdll_node *cdll_create_node(cdll_data data)
{
    cdll_node *new_node = malloc(sizeof(cdll_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
void cdll_append(c_d_linked_list *list, cdll_data data)
{
    if (list == NULL) {
        return;
    }
    cdll_node *new_tail = cdll_create_node(data);
    if (new_tail == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = new_tail;
    } else {
        cdll_node *prev_node = list->head->prev;
        new_tail->prev = prev_node;
        prev_node->next = new_tail;
    }
    new_tail->next = list->head;
    list->head->prev = new_tail;

    list->count++;
}
void cdll_insert(c_d_linked_list *list, size_t pos, cdll_data data)
{
    if (list == NULL) {
        return;
    }
    size_t size = cdll_size(list);
    if (pos > size) {
        return;
    }
    if (pos == size) {
        cdll_append(list, data);
        return;
    }

    cdll_node *new_node = cdll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    cdll_node *next_node = cdll_get_node(list, pos);
    cdll_node *prev_node = next_node->prev;

    prev_node->next = new_node;
    new_node->prev = prev_node;

    new_node->next = next_node;
    next_node->prev = new_node;

    if (pos == 0) {
        list->head = new_node;
    }

    list->count++;
}

void cdll_delete(c_d_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= cdll_size(list)) {
        return;
    }
    cdll_node *free_node = cdll_get_node(list, pos);
    if (free_node == NULL) {
        return;
    }

    if (free_node->next == free_node) {
        list->head = NULL;
    } else {
        cdll_node *prev_node = free_node->prev;
        cdll_node *next_node = free_node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        if (list->head == free_node) {
            list->head = next_node;
        }
    }
    printf("Destroying Node : %d\n", free_node->data);
    free(free_node);
    list->count--;
}
cdll_node *cdll_get_node(c_d_linked_list *list, size_t pos)
{
    size_t count = cdll_size(list);

    if (pos >= count) {
        return NULL;
    }
    cdll_node *get_node = NULL;

    if (pos < count / 2) {
        get_node = list->head;

        while (pos > 0) {
            get_node = get_node->next;
            pos--;
        }
    } else {
        get_node = list->head->prev;

        while (pos < count - 1) {
            get_node = get_node->prev;
            pos++;
        }
    }
    return get_node;
}
cdll_data cdll_get(c_d_linked_list *list, size_t pos)
{
    return cdll_get_node(list, pos)->data;
}
size_t cdll_size(c_d_linked_list *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->count;
}
void cdll_destroy(c_d_linked_list *list)
{
    if (list == NULL) {
        return;
    }
    while (list->head) {
        cdll_delete(list, 0);
    }
    free(list);
}