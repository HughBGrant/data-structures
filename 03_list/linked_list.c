#include "linked_list.h"

linked_list *ll_create(void)
{
    linked_list *list = malloc(sizeof(linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;

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
void ll_insert(linked_list *list, size_t pos, ll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }
    ll_node *new_node = ll_create_node(data);
    if (new_node == NULL) {
        return;
    }
    if (pos == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        ll_node *prev = list->head;
        while (pos > 1) {
            prev = prev->next;
            pos--;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }

    list->count++;
}
void ll_delete(linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    // 1
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

    // 2
    // ll_node **link = &list->head;

    // while (pos > 0) {
    //     link = &(*link)->next;
    //     pos--;
    // }

    // ll_node *free_node = *link;
    //*link = free_node->next;
    //

    printf("Destroying Node : %d\n", free_node->data);
    free(free_node);
    list->count--;
}
ll_data ll_get(linked_list *list, size_t pos)
{

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

    while (list->head) {
        ll_delete(list, 0);
    }
    free(list);
}