#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _sl_node {
    SLItem data;
    struct _sl_node *next;
} sl_node;

struct SinglyLinkedList {
    sl_node *head;
    size_t size;
};

static sl_node *sl_node_create(SLItem data);

static void sl_node_destroy(sl_node *node);

static sl_node *sl_linear_search_move2front(SLList *list, SLItem key);

static sl_node *sl_linear_search_transpose(SLList *list, SLItem key);

static sl_node *sl_node_create(SLItem data)
{
    sl_node *new_node = malloc(sizeof(sl_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
static void sl_node_destroy(sl_node *node)
{
    free(node);
}
static sl_node *sl_linear_search_move2front(SLList *list, SLItem key)
{
    if (list == NULL) {
        return NULL;
    }
    sl_node *prev = NULL;
    sl_node *current = list->head;

    while (current && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return NULL;
    }
    if (prev) {
        prev->next = current->next;
        current->next = list->head;
        list->head = current;
    }
    return current;
}
static sl_node *sl_linear_search_transpose(SLList *list, SLItem key)
{
    if (list == NULL) {
        return NULL;
    }
    sl_node *prev_prev = NULL;
    sl_node *prev = NULL;
    sl_node *current = list->head;

    while (current && current->data != key) {
        prev_prev = prev;
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return NULL;
    }
    if (prev) {
        prev->next = current->next;
        current->next = prev;

        if (prev_prev) {
            prev_prev->next = current;
        } else {
            list->head = current;
        }
    }
    return current;
}
SLList *sl_create(void)
{
    SLList *list = malloc(sizeof(SLList));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->head = NULL;

    return list;
}
void sl_destroy(SLList *list)
{
    if (list == NULL) {
        return;
    }

    while (list->head) {
        sl_delete(list, 0);
    }
    free(list);
}
void sl_insert(SLList *list, size_t index, SLItem data)
{
    if (list == NULL || index > list->size) {
        return;
    }
    sl_node *new_node = sl_node_create(data);
    if (new_node == NULL) {
        return;
    }
    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        sl_node *prev = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }

    list->size++;
}
SLItem sl_delete(SLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    sl_node *target = NULL;

    if (index == 0) {
        target = list->head;
        list->head = target->next;
    } else {
        sl_node *prev = list->head;

        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        target = prev->next;
        prev->next = target->next;
    }
    SLItem data = target->data;
    sl_node_destroy(target);
    list->size--;
    return data;
}
SLItem sl_get(SLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    sl_node *target = list->head;

    for (size_t i = 0; i < index; i++) {
        target = target->next;
    }
    return target->data;
}
void sl_print(SLList *list)
{
    if (list == NULL || list->head == NULL) {
        return;
    }
    sl_node *current = list->head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}
size_t sl_size(SLList *list)
{
    return list ? list->size : 0;
}