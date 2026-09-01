#include "circular_deque.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8

struct CircularDeque {
    CItem *items;
    size_t capacity;
    size_t front;
    size_t size;
};

CDeque *cd_create(void)
{
    CDeque *deque = malloc(sizeof(CDeque));
    if (deque == NULL) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    deque->items = malloc(sizeof(CItem) * capacity);
    if (deque->items == NULL) {
        free(deque);
        return NULL;
    }

    deque->capacity = capacity;
    deque->front = 0;
    deque->size = 0;

    return deque;
}
void cd_destroy(CDeque *deque)
{
    if (deque == NULL) {
        return;
    }
    free(deque->items);
    free(deque);
}
void cd_push_front(CDeque *deque, CItem value)
{
    if (deque == NULL) {
        return;
    }
    if (deque->size == deque->capacity) {
        cd_resize(deque);
        if (deque->size == deque->capacity) {
            return;
        }
    }

    deque->front = (deque->capacity + deque->front - 1) % deque->capacity;
    deque->items[deque->front] = value;
    deque->size++;
}
void cd_push_back(CDeque *deque, CItem value)
{
    if (deque == NULL) {
        return;
    }
    if (deque->size == deque->capacity) {
        cd_resize(deque);
        if (deque->size == deque->capacity) {
            return;
        }
    }
    size_t back = (deque->front + deque->size) % deque->capacity;
    deque->items[back] = value;
    deque->size++;
}
void cd_resize(CDeque *deque)
{
    size_t new_capacity = deque->capacity * 2;
    CItem *new_items = malloc(sizeof(CItem) * new_capacity);
    if (new_items == NULL) {
        return;
    }

    for (size_t i = 0; i < deque->size; ++i) {
        new_items[i] = deque->items[(deque->front + i) % deque->capacity];
    }
    free(deque->items);
    deque->items = new_items;
    deque->capacity = new_capacity;
    deque->front = 0;
}
CItem cd_pop_front(CDeque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    CItem data = deque->items[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return data;
}
CItem cd_pop_back(CDeque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    size_t back = (deque->front + deque->size - 1) % deque->capacity;
    CItem data = deque->items[back];
    deque->size--;
    return data;
}
CItem cd_front(CDeque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    return deque->items[deque->front];
}
CItem cd_back(CDeque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    size_t back_index = (deque->front + deque->size - 1) % deque->capacity;
    return deque->items[back_index];
}
bool cd_is_empty(CDeque *deque)
{
    return deque == NULL || deque->size == 0;
}
size_t cd_size(CDeque *deque)
{
    return deque ? deque->size : 0;
}