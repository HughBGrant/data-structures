#include "linked_deque.h"

linked_deque *ld_create(void)
{
    linked_deque *deque = malloc(sizeof(linked_deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}
ld_node *ld_create_node(ld_data data)
{
    ld_node *new_node = malloc(sizeof(ld_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}
void ld_push_front(linked_deque *deque, ld_data data)
{
    if (deque == NULL) {
        return;
    }
    ld_node *new_front = ld_create_node(data);
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
void ld_push_back(linked_deque *deque, ld_data data)
{
    if (deque == NULL) {
        return;
    }
    ld_node *new_rear = ld_create_node(data);
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
void ld_pop_front(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return;
    }
    ld_node *target_node = deque->front;
    deque->front = target_node->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    free(target_node);
}
void ld_pop_back(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return;
    }
    ld_node *target_node = deque->rear;
    deque->rear = target_node->prev;

    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }

    free(target_node);
}
ld_data *ld_front(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return NULL;
    }
    return &deque->front->data;
}
ld_data *ld_back(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return NULL;
    }
    return &deque->rear->data;
}
size_t ld_size(linked_deque *deque)
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
bool ld_is_empty(linked_deque *deque)
{
    if (deque == NULL) {
        return true;
    }
    return deque->front == NULL;
}
void ld_destroy(linked_deque *deque)
{
    if (deque == NULL) {
        return;
    }
    while (deque->front) {
        ld_pop_front(deque);
    }
    free(deque);
}