#include "linked_deque.h"

linked_deque *ld_create(void)
{
    linked_deque *deque = malloc(sizeof(linked_deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->front = NULL;
    deque->rear = NULL;
    deque->count = 0;

    return deque;
}

ld_node *ld_create_node(ld_data data)
{
    if (data == NULL) {
        return NULL;
    }
    ld_node *new_node = malloc(sizeof(ld_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        free(new_node);
        return NULL;
    }

    strcpy(new_node->data, data);
    new_node->next = NULL;

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
    }
    deque->front = new_front;

    deque->count++;
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
        deque->rear->next = new_rear;
    }
    deque->rear = new_rear;

    deque->count++;
}
void ld_pop_front(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return;
    }
    ld_node *free_node = deque->front;

    deque->front = free_node->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    }

    free(free_node->data);
    free(free_node);
    deque->count--;
}
void ld_pop_back(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return;
    }
    ld_node *free_node = deque->rear;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;

    } else {
        ld_node *prev_node = deque->front;
        while (prev_node->next != free_node) {
            prev_node = prev_node->next;
        }
        prev_node->next = NULL;
        deque->rear = prev_node;
    }

    free(free_node->data);
    free(free_node);

    deque->count--;
}
ld_data ld_front(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return NULL;
    }
    return deque->front->data;
}
ld_data ld_back(linked_deque *deque)
{
    if (deque == NULL || ld_is_empty(deque)) {
        return NULL;
    }
    return deque->rear->data;
}
bool ld_is_empty(linked_deque *deque)
{
    if (deque == NULL) {
        return true;
    }
    return deque->count == 0;
}
void ld_destroy(linked_deque *deque)
{
    if (deque == NULL) {
        return;
    }
    while (ld_is_empty(deque) == false) {
        ld_pop_front(deque);
    }
    free(deque);
}