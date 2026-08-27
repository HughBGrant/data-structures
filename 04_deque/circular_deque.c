#include "circular_deque.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8

struct circular_deque {
    cd_item *items;
    size_t capacity;
    size_t front;
    size_t size;
};

cd_deque *cd_create(void)
{
    cd_deque *deque = malloc(sizeof(cd_deque));
    if (deque == NULL) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    deque->items = malloc(sizeof(cd_item) * capacity);
    if (deque->items == NULL) {
        free(deque);
        return NULL;
    }

    deque->capacity = capacity;
    deque->front = 0;
    deque->size = 0;

    return deque;
}
void cd_destroy(cd_deque *deque)
{
    if (deque == NULL) {
        return;
    }
    free(deque->items);
    free(deque);
}
void cd_push_front(cd_deque *deque, cd_item value)
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
void cd_push_back(cd_deque *deque, cd_item value)
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
void cd_resize(cd_deque *deque)
{
    size_t new_capacity = deque->capacity * 2;
    cd_item *new_items = malloc(sizeof(cd_item) * new_capacity);
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
cd_item cd_pop_front(cd_deque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    cd_item data = deque->items[deque->front];
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return data;
}
cd_item cd_pop_back(cd_deque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    size_t back = (deque->front + deque->size - 1) % deque->capacity;
    cd_item data = deque->items[back];
    deque->size--;
    return data;
}
cd_item cd_front(cd_deque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    return deque->items[deque->front];
}
cd_item cd_back(cd_deque *deque)
{
    if (cd_is_empty(deque)) {
        return 0;
    }
    size_t back_index = (deque->front + deque->size - 1) % deque->capacity;
    return deque->items[back_index];
}
bool cd_is_empty(cd_deque *deque)
{
    return deque == NULL || deque->size == 0;
}
size_t cd_size(cd_deque *deque)
{
    return deque ? deque->size : 0;
}