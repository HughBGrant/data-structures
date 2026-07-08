#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_DEQUE_H
#define CIRCULAR_DEQUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int cd_data;

typedef struct {
    size_t capacity;
    size_t front;
    size_t rear;
    cd_data *array;
    size_t count;
} circular_deque;

circular_deque *cd_create(size_t capacity);
void cd_push_front(circular_deque *deque, cd_data data);
void cd_push_back(circular_deque *deque, cd_data data);
void cd_pop_front(circular_deque *deque);

void cd_pop_back(circular_deque *deque);
cd_data cd_front(circular_deque *deque);
cd_data cd_back(circular_deque *deque);

void cd_destroy(circular_deque *deque);

bool cd_is_empty(circular_deque *deque);
bool cd_is_full(circular_deque *deque);
size_t cd_size(circular_deque *deque);

#endif