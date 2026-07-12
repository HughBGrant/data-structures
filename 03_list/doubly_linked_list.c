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
    if (pos > list->count) {
        return NULL;
    }
    if (pos == list->count) {
        return list->tail;
    }
    dll_node *get_node = NULL;

    if (pos < list->count / 2) {
        get_node = list->head->next;

        while (pos > 0) {
            get_node = get_node->next;
            pos--;
        }
    } else {
        get_node = list->tail->prev;

        while (pos < list->count - 1) {
            get_node = get_node->prev;
            pos++;
        }
    }

    return get_node;
}
void dll_insert(doubly_linked_list *list, size_t pos, dll_data data)
{
    if (list == NULL || pos > list->count) {
        return;
    }

    dll_node *new_node = dll_create_node(data);
    if (new_node == NULL) {
        return;
    }

    dll_node *pos_node = dll_get_node(list, pos);

    new_node->prev = pos_node->prev;
    new_node->next = pos_node;

    pos_node->prev->next = new_node;
    pos_node->prev = new_node;

    list->count++;
}
void dll_delete(doubly_linked_list *list, size_t pos)
{
    if (list == NULL || pos >= list->count) {
        return;
    }

    dll_node *free_node = dll_get_node(list, pos);
    if (free_node == NULL) {
        return;
    }

    free_node->prev->next = free_node->next;
    free_node->next->prev = free_node->prev;

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
