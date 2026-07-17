#include "circular_deque.h"

circular_deque *cd_create(size_t max_size)
{
    if (max_size == 0) {
        return NULL;
    }
    circular_deque *deque = malloc(sizeof(circular_deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->items = malloc(sizeof(cd_data) * (max_size + 1));
    if (deque->items == NULL) {
        free(deque);
        return NULL;
    }

    deque->max_size = max_size + 1;
    deque->rear = 0;
    deque->front = 0;

    return deque;
}
void cd_push_front(circular_deque *deque, cd_data data)
{
    if (deque == NULL || cd_is_full(deque)) {
        return;
    }
    deque->front = (deque->max_size + deque->front - 1) % deque->max_size;
    deque->items[deque->front] = data;
}
void cd_push_back(circular_deque *deque, cd_data data)
{
    if (deque == NULL || cd_is_full(deque)) {
        return;
    }
    deque->items[deque->rear] = data;
    deque->rear = (deque->rear + 1) % deque->max_size;
}
void cd_pop_front(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return;
    }
    deque->front = (deque->front + 1) % deque->max_size;
}
void cd_pop_back(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return;
    }
    deque->rear = (deque->rear + deque->max_size - 1) % deque->max_size;
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
    size_t index = (deque->rear + deque->max_size - 1) % deque->max_size;
    return &deque->items[index];
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
    return (deque->rear + 1) % deque->max_size == deque->front;
}
size_t cd_size(circular_deque *deque)
{
    if (deque == NULL) {
        return 0;
    }
    return (deque->rear + deque->max_size - deque->front) % deque->max_size;
}