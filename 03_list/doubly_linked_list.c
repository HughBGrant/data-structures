#include "doubly_linked_list.h"

doubly_linked_list *dll_create(void)
{
    doubly_linked_list *list = malloc(sizeof(doubly_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->head = dll_create_node(0);
    if (list->head == NULL) {
        free(list);
        return NULL;
    }
    list->tail = dll_create_node(0);
    if (list->tail == NULL) {
        free(list->head);
        free(list);
        return NULL;
    }

    list->count = 0;
    list->head->next = list->tail;
    list->tail->prev = list->head;

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
    size_t count = dll_size(list);

    if (pos >= count) {
        return NULL;
    }

    dll_node *get_node = NULL;

    if (pos < count / 2) {
        get_node = list->head->next;

        while (pos > 0) {
            get_node = get_node->next;
            pos--;
        }
    } else {
        get_node = list->tail->prev;

        while (pos < count - 1) {
            get_node = get_node->prev;
            pos++;
        }
    }

    return get_node;
}
void dll_append(doubly_linked_list *list, dll_data data)
{
    if (list == NULL) {
        return;
    }

    dll_node *new_tail = dll_create_node(data);
    if (new_tail == NULL) {
        return;
    }
    dll_node *prev_node = list->tail->prev;

    prev_node->next = new_tail;
    new_tail->prev = prev_node;
    new_tail->next = list->tail;
    list->tail->prev = new_tail;

    list->count++;
}
void dll_insert(doubly_linked_list *list, size_t pos, dll_data data)
{
    if (list == NULL) {
        return;
    }

    size_t size = dll_size(list);
    if (pos > size) {
        return;
    }

    if (pos == size) {
        dll_append(list, data);
        return;
    }

    dll_node *new_node = dll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    dll_node *next_node = dll_get_node(list, pos);
    dll_node *prev_node = next_node->prev;

    prev_node->next = new_node;
    new_node->prev = prev_node;
    new_node->next = next_node;
    next_node->prev = new_node;

    list->count++;
}
void dll_delete(doubly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= dll_size(list)) {
        return;
    }

    dll_node *free_node = dll_get_node(list, pos);
    if (free_node == NULL) {
        return;
    }

    dll_node *prev_node = free_node->prev;
    dll_node *next_node = free_node->next;

    prev_node->next = next_node;
    next_node->prev = prev_node;

    printf("Destroying Node : %d\n", free_node->data);
    free(free_node);
    list->count--;
}
dll_data dll_get(doubly_linked_list *list, size_t pos)
{
    return dll_get_node(list, pos)->data;
}
size_t dll_size(doubly_linked_list *list)
{
    if (list == NULL) {
        return 0;
    }

    return list->count;
}

void dll_destroy(doubly_linked_list *list)
{
    if (list == NULL) {
        return;
    }

    while (list->count > 0) {
        dll_delete(list, 0);
    }

    free(list->head);
    free(list->tail);
    free(list);
}
