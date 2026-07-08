#include "circular_deque.h"

circular_deque *cd_create(size_t capacity)
{
    if (capacity == 0) {
        return NULL;
    }
    circular_deque *deque = malloc(sizeof(circular_deque));
    if (deque == NULL) {
        return NULL;
    }

    deque->array = malloc(sizeof(cd_data) * capacity);
    if (deque->array == NULL) {
        free(deque);
        return NULL;
    }

    deque->capacity = capacity;
    deque->front = 0;
    deque->rear = 0;
    deque->count = 0;

    return deque;
}
void cd_push_front(circular_deque *deque, cd_data data)
{
    if (cd_is_full(deque)) {
        return;
    }
    size_t index = (deque->front + deque->capacity - 1) % deque->capacity;
    deque->array[index] = data;
    deque->front = index;
    deque->count++;
}
void cd_push_back(circular_deque *deque, cd_data data)
{
    if (cd_is_full(deque)) {
        return;
    }
    deque->array[deque->rear] = data;
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->count++;
}
void cd_pop_front(circular_deque *deque)
{
    if (cd_is_empty(deque)) {
        return;
    }
    deque->front = (deque->front + 1) % deque->capacity;
    deque->count--;
}
void cd_pop_back(circular_deque *deque)
{
    if (cd_is_empty(deque)) {
        return;
    }
    deque->rear = (deque->rear + deque->capacity - 1) % deque->capacity;
    deque->count--;
}
cd_data cd_front(circular_deque *deque)
{
    return deque->array[deque->front];
}
cd_data cd_back(circular_deque *deque)
{
    size_t index = (deque->rear + deque->capacity - 1) % deque->capacity;
    return deque->array[index];
}
void cd_destroy(circular_deque *deque)
{
    if (deque == NULL) {
        return;
    }
    free(deque->array);
    free(deque);
}
bool cd_is_empty(circular_deque *deque)
{
    return deque->count == 0;
}
bool cd_is_full(circular_deque *deque)
{
    return deque->count == deque->capacity;
}
size_t cd_size(circular_deque *deque)
{
    if (deque == NULL) {
        return 0;
    }
    return deque->count;
}