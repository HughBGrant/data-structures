#include "doubly_linked_list.h"

doubly_linked_list *dll_create(void)
{
    doubly_linked_list *list = malloc(sizeof(doubly_linked_list));
    if (list == NULL) {
        return NULL;
    }

    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

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
void dll_append(doubly_linked_list *list, dll_data data)
{
    dll_node *new_tail = dll_create_node(data);
    if (new_tail == NULL) {
        return;
    }

    if (list->head == NULL) {
        list->head = new_tail;
    } else {
        new_tail->prev = list->tail;
        list->tail->next = new_tail;
    }
    new_tail->next = list->head;
    list->head->prev = new_tail;
    list->tail = new_tail;

    list->count++;
}
void dll_insert(doubly_linked_list *list, size_t pos, dll_data data)
{
    if (pos > list->count) {
        return;
    }
    dll_node *new_node = dll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    dll_node *current = dll_get_node(list, pos);
    if (current == NULL) {
        return;
    }
    dll_node *previous = current->prev;
    previous->next = new_node;
    new_node->prev = previous;
    new_node->next = current;
    current->prev = new_node;

    if (current == list->head) {
        list->head = new_node;
    }
    list->count++;
}

void dll_delete(doubly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }
    dll_node *current = dll_get_node(list, pos);
    if (current == NULL) {
        return;
    }

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == list->head) {
            list->head = current->next;
        }
        if (current == list->tail) {
            list->tail = current->prev;
        }
    }
    printf("Destroying Node : %d\n", current->data);
    free(current);
    list->count--;
}
dll_node *dll_get_node(doubly_linked_list *list, size_t pos)
{
    size_t count = dll_size(list);

    if (pos >= count) {
        return NULL;
    }
    dll_node *current = NULL;

    if (pos < count / 2) {
        current = list->head;

        while (pos > 0) {
            current = current->next;
            pos--;
        }
    } else {
        current = list->tail;

        while (pos < count - 1) {
            current = current->prev;
            pos++;
        }
    }
    return current;
}
dll_data *dll_get(doubly_linked_list *list, size_t pos)
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
    free(list);
}