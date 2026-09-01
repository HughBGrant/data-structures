#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _sll_node {
    SLItem data;
    struct _sll_node *next;
} sll_node;

struct SinglyLinkedList {
    sll_node *head;
    size_t size;
};

static sll_node *sll_node_create(SLItem data);

static void sll_node_destroy(sll_node *node);

static sll_node *sll_linear_search_move2front(SLList *list, SLItem key);

static sll_node *sll_linear_search_transpose(SLList *list, SLItem key);

static sll_node *sll_node_create(SLItem data)
{
    sll_node *new_node = malloc(sizeof(sll_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
static void sll_node_destroy(sll_node *node)
{
    free(node);
}
static sll_node *sll_linear_search_move2front(SLList *list, SLItem key)
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
static sll_node *sll_linear_search_transpose(SLList *list, SLItem key)
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
SLList *sll_create(void)
{
    SLList *list = malloc(sizeof(SLList));
    if (list == NULL) {
        return NULL;
    }

    list->size = 0;
    list->head = NULL;

    return list;
}
void sll_destroy(SLList *list)
{
    if (list == NULL) {
        return;
    }

    while (list->head) {
        sll_delete(list, 0);
    }
    free(list);
}
void sll_insert(SLList *list, size_t index, SLItem data)
{
    if (list == NULL || index > list->size) {
        return;
    }
    sll_node *new_node = sll_node_create(data);
    if (new_node == NULL) {
        return;
    }
    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        sll_node *prev = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }

    list->size++;
}
SLItem sll_delete(SLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    sll_node *target_node = NULL;

    if (index == 0) {
        target_node = list->head;
        list->head = target_node->next;
    } else {
        sll_node *prev_node = list->head;

        for (size_t i = 0; i < index - 1; i++) {
            prev_node = prev_node->next;
        }
        target_node = prev_node->next;
        prev_node->next = target_node->next;
    }
    SLItem data = target_node->data;
    sll_node_destroy(target_node);
    list->size--;
    return data;
}
SLItem sll_get(SLList *list, size_t index)
{
    if (list == NULL || index >= list->size) {
        return 0;
    }
    sll_node *target_node = list->head;

    for (size_t i = 0; i < index; i++) {
        target_node = target_node->next;
    }
    return target_node->data;
}
void sll_print(SLList *list)
{
    if (list == NULL || list->head == NULL) {
        return;
    }
    sll_node *current_node = list->head;

    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}
size_t sll_size(SLList *list)
{
    return list ? list->size : 0;
}