#include "circular_doubly_linked_list.h"

c_d_linked_list *cdll_create(void)
{
    c_d_linked_list *list = malloc(sizeof(c_d_linked_list));
    if (list == NULL) {
        return NULL;
    }
    list->head = cdll_create_node(0);
    if (list->head == NULL) {
        free(list);
        return NULL;
    }

    list->head->next = list->head;
    list->head->prev = list->head;
    list->count = 0;

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
cdll_node *cdll_get_node(c_d_linked_list *list, size_t pos)
{
    if (list == NULL || pos > list->count) {
        return NULL;
    }
    if (pos == list->count) {
        return list->head; // 센티널 반환
    }

    cdll_node *target_node = NULL;

    if (pos < list->count / 2) {
        target_node = list->head->next;

        while (pos > 0) {
            target_node = target_node->next;
            pos--;
        }
    } else {
        target_node = list->head->prev;

        while (pos < list->count - 1) {
            target_node = target_node->prev;
            pos++;
        }
    }
    return target_node;
}
void cdll_insert(c_d_linked_list *list, size_t pos, cdll_data data)
{
    if (list == NULL || pos > list->count) {
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

    list->count++;
}
void cdll_delete(c_d_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    cdll_node *target_node = cdll_get_node(list, pos);
    if (target_node == NULL) {
        return;
    }

    target_node->prev->next = target_node->next;
    target_node->next->prev = target_node->prev;

    printf("Destroying Node : %d\n", target_node->data);
    free(target_node);

    list->count--;
}
cdll_data *cdll_get(c_d_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return NULL;
    }
    return &cdll_get_node(list, pos)->data;
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
    while (list->count > 0) {
        cdll_delete(list, 0);
    }
    free(list->head);
    free(list);
}