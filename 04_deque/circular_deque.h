#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_DEQUE_H
#define CIRCULAR_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int cd_item;

typedef struct {
    cd_item *data;
    size_t capacity;
    size_t front;
    size_t count;
} circular_deque;
typedef circular_deque cd_deque;

void cd_push_front(cd_deque *deque, cd_item data);
void cd_push_back(cd_deque *deque, cd_item data);
void cd_resize(cd_deque *deque);
void cd_pop_front(cd_deque *deque);
void cd_pop_back(cd_deque *deque);
cd_item *cd_front(cd_deque *deque);
cd_item *cd_back(cd_deque *deque);
bool cd_is_empty(cd_deque *deque);
size_t cd_size(cd_deque *deque);

cd_deque *cd_create(size_t capacity);
void cd_destroy(cd_deque *deque);

#endif