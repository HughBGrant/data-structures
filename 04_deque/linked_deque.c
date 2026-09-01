#include "linked_deque.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _ld_node {
    LItem data;
    struct _ld_node *next;
    struct _ld_node *prev;
} ld_node;

struct LinkedDeque {
    ld_node *rear;
    ld_node *front;
};

static ld_node *ld_node_create(LItem value);

static void ld_node_destroy(ld_node *node);

static ld_node *ld_node_create(LItem value)
{
    ld_node *new_node = malloc(sizeof(ld_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}
static void ld_node_destroy(ld_node *node)
{
    free(node);
}
LDeque *ld_create(void)
{
    LDeque *deque = malloc(sizeof(LDeque));
    if (deque == NULL) {
        return NULL;
    }

    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}
void ld_destroy(LDeque *deque)
{
    if (deque == NULL) {
        return;
    }
    while (deque->front) {
        ld_pop_front(deque);
    }
    free(deque);
}
void ld_push_front(LDeque *deque, LItem value)
{
    if (deque == NULL) {
        return;
    }
    ld_node *new_front = ld_node_create(value);
    if (new_front == NULL) {
        return;
    }
    if (deque->rear == NULL) {
        deque->rear = new_front;
    } else {
        new_front->next = deque->front;
        deque->front->prev = new_front;
    }
    deque->front = new_front;
}
void ld_push_back(LDeque *deque, LItem value)
{
    if (deque == NULL) {
        return;
    }
    ld_node *new_rear = ld_node_create(value);
    if (new_rear == NULL) {
        return;
    }

    if (deque->front == NULL) {
        deque->front = new_rear;
    } else {
        new_rear->prev = deque->rear;
        deque->rear->next = new_rear;
    }
    deque->rear = new_rear;
}
LItem ld_pop_front(LDeque *deque)
{
    if (ld_is_empty(deque)) {
        return 0;
    }
    ld_node *target_node = deque->front;
    deque->front = target_node->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    LItem data = target_node->data;
    ld_node_destroy(target_node);
    return data;
}
LItem ld_pop_back(LDeque *deque)
{
    if (ld_is_empty(deque)) {
        return 0;
    }
    ld_node *target_node = deque->rear;
    deque->rear = target_node->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    LItem data = target_node->data;
    ld_node_destroy(target_node);
    return data;
}
LItem ld_front(LDeque *deque)
{
    if (ld_is_empty(deque)) {
        return 0;
    }
    return deque->front->data;
}
LItem ld_back(LDeque *deque)
{
    if (ld_is_empty(deque)) {
        return 0;
    }
    return deque->rear->data;
}
size_t ld_size(LDeque *deque)
{
    if (deque == NULL) {
        return 0;
    }
    size_t size = 0;
    ld_node *current_node = deque->front;

    while (current_node) {
        size++;
        current_node = current_node->next;
    }
    return size;
}
bool ld_is_empty(LDeque *deque)
{
    return deque == NULL || deque->front == NULL;
}