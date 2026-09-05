#include "circular_deque.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8

struct CircularDeque {
    int *items;
    size_t capacity;
    size_t front;
    size_t size;
};

CDeque *c_create(void)
{
    CDeque *deque = malloc(sizeof(CDeque));
    if (deque == NULL) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    deque->items = malloc(sizeof(int) * capacity);
    if (deque->items == NULL) {
        free(deque);
        return NULL;
    }

    deque->capacity = capacity;
    deque->front = 0;
    deque->size = 0;

    return deque;
}
void c_destroy(CDeque *deque)
{
    if (deque == NULL) {
        return;
    }
    free(deque->items);
    free(deque);
}
void c_push_front(CDeque *deque, int data)
{
    if (deque == NULL) {
        return;
    }
    if (deque->size == deque->capacity) {
        c_resize(deque);
        if (deque->size == deque->capacity) {
            return;
        }
    }

    deque->front = (deque->capacity + deque->front - 1) % deque->capacity;
    deque->items[deque->front] = data;
    deque->size++;
}
void c_push_back(CDeque *deque, int data)
{
    if (deque == NULL) {
        return;
    }
    if (deque->size == deque->capacity) {
        c_resize(deque);
        if (deque->size == deque->capacity) {
            return;
        }
    }
    size_t back = (deque->front + deque->size) % deque->capacity;
    deque->items[back] = data;
    deque->size++;
}
void c_resize(CDeque *deque)
{
    size_t new_capacity = deque->capacity * 2;
    int *new_items = malloc(sizeof(int) * new_capacity);
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
int c_pop_front(CDeque *deque)
{
    if (c_is_empty(deque)) {
        return 0;
    }
    int data = deque->items[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return data;
}
int c_pop_back(CDeque *deque)
{
    if (c_is_empty(deque)) {
        return 0;
    }
    size_t back = (deque->front + deque->size - 1) % deque->capacity;
    int data = deque->items[back];
    deque->size--;
    return data;
}
int c_front(CDeque *deque)
{
    if (c_is_empty(deque)) {
        return 0;
    }
    return deque->items[deque->front];
}
int c_back(CDeque *deque)
{
    if (c_is_empty(deque)) {
        return 0;
    }
    size_t back_index = (deque->front + deque->size - 1) % deque->capacity;
    return deque->items[back_index];
}
bool c_is_empty(CDeque *deque)
{
    return deque == NULL || deque->size == 0;
}
size_t c_size(CDeque *deque)
{
    return deque ? deque->size : 0;
}