#include "singly_linked_list.h"

singly_linked_list *sll_create(void)
{
    singly_linked_list *list = malloc(sizeof(singly_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;

    return list;
}
sll_node *sll_create_node(sll_data data)
{
    sll_node *new_node = malloc(sizeof(sll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
void sll_insert(singly_linked_list *list, size_t pos, sll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }
    sll_node *new_node = sll_create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (pos == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        sll_node *prev = list->head;
        while (pos > 1) {
            prev = prev->next;
            pos--;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }

    list->count++;
}
void sll_delete(singly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    // 1
    sll_node *prev_node = NULL;
    sll_node *free_node = list->head;

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

    // 2
    // sll_node **link = &list->head;

    // while (pos > 0) {
    //     link = &(*link)->next;
    //     pos--;
    // }

    // sll_node *free_node = *link;
    //*link = free_node->next;
    //

    printf("Destroying Node : %d\n", free_node->data);
    free(free_node);
    list->count--;
}
sll_data *sll_get(singly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }

    sll_node *get_node = list->head;
    while (pos > 0) {
        get_node = get_node->next;
        pos--;
    }
    return &get_node->data;
}
sll_node *sll_search_move2front(singly_linked_list *list, sll_data key)
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
sll_node *sll_search_transpose(singly_linked_list *list, sll_data key)
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
size_t sll_size(singly_linked_list *list)
{
    if (list == NULL) {
        return 0;
    }
    return list->count;
}
void sll_destroy(singly_linked_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->head) {
        sll_delete(list, 0);
    }
    free(list);
}