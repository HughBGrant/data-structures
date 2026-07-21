#include "circular_deque.h"

circular_deque *cd_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    circular_deque *deque = malloc(sizeof(circular_deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->items = malloc(sizeof(cd_data) * (capacity + 1));
    if (deque->items == NULL) {
        free(deque);
        return NULL;
    }

    deque->capacity = capacity + 1;
    deque->rear = 0;
    deque->front = 0;

    return deque;
}
void cd_push_front(circular_deque *deque, cd_data data)
{
    if (deque == NULL || cd_is_full(deque)) {
        return;
    }

    deque->front = (deque->capacity + deque->front - 1) % deque->capacity;
    deque->items[deque->front] = data;
}
void cd_push_back(circular_deque *deque, cd_data data)
{
    if (deque == NULL || cd_is_full(deque)) {
        return;
    }

    deque->items[deque->rear] = data;
    deque->rear = (deque->rear + 1) % deque->capacity;
}
void cd_pop_front(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return;
    }
    deque->front = (deque->front + 1) % deque->capacity;
}
void cd_pop_back(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return;
    }
    deque->rear = (deque->rear + deque->capacity - 1) % deque->capacity;
}
cd_data *cd_front(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return NULL;
    }
    return &deque->items[deque->front];
}
cd_data *cd_back(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return NULL;
    }
    return &deque->items[(deque->rear + deque->capacity - 1) % deque->capacity];
}
void cd_destroy(circular_deque *deque)
{
    if (deque == NULL) {
        return;
    }
    free(deque->items);
    free(deque);
}
bool cd_is_empty(circular_deque *deque)
{
    if (deque == NULL) {
        return false;
    }
    return deque->front == deque->rear;
}
bool cd_is_full(circular_deque *deque)
{
    if (deque == NULL) {
        return false;
    }
    return (deque->rear + 1) % deque->capacity == deque->front;
}
size_t cd_size(circular_deque *deque)
{
    if (deque == NULL) {
        return 0;
    }
    return (deque->rear + deque->capacity - deque->front) % deque->capacity;
}