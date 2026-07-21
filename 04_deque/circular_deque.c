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

    deque->items = malloc(sizeof(cd_data) * capacity);
    if (deque->items == NULL) {
        free(deque);
        return NULL;
    }

    deque->capacity = capacity;
    deque->front = 0;
    deque->count = 0;

    return deque;
}
void cd_push_front(circular_deque *deque, cd_data data)
{
    if (deque == NULL) {
        return;
    }
    if (deque->count == deque->capacity) {
        cd_resize(deque);
        if (deque->count == deque->capacity) {
            return;
        }
    }

    deque->front = (deque->capacity + deque->front - 1) % deque->capacity;
    deque->items[deque->front] = data;
    deque->count++;
}
void cd_push_back(circular_deque *deque, cd_data data)
{
    if (deque == NULL) {
        return;
    }
    if (deque->count == deque->capacity) {
        cd_resize(deque);
        if (deque->count == deque->capacity) {
            return;
        }
    }
    size_t rear = (deque->front + deque->count) % deque->capacity;
    deque->items[rear] = data;
    deque->count++;
}
void cd_resize(circular_deque *deque)
{
    size_t new_capacity = deque->capacity * 2;
    cd_data *new_items = malloc(sizeof(cd_data) * new_capacity);
    if (new_items == NULL) {
        return;
    }

    for (size_t i = 0; i < deque->count; ++i) {
        new_items[i] = deque->items[(deque->front + i) % deque->capacity];
    }
    free(deque->items);
    deque->items = new_items;
    deque->capacity = new_capacity;
    deque->front = 0;
}
void cd_pop_front(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return;
    }
    deque->front = (deque->front + 1) % deque->capacity;
    deque->count--;
}
void cd_pop_back(circular_deque *deque)
{
    if (deque == NULL || cd_is_empty(deque)) {
        return;
    }
    deque->count--;
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
    size_t back_index = (deque->front + deque->count - 1) % deque->capacity;
    return &deque->items[back_index];
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
        return true;
    }
    return deque->count == 0;
}
size_t cd_size(circular_deque *deque)
{
    if (deque == NULL) {
        return 0;
    }
    return deque->count;
}