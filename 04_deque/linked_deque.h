#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int ld_item;
typedef struct linked_deque ld_deque;

void ld_push_front(ld_deque *deque, ld_item value);
void ld_push_back(ld_deque *deque, ld_item value);
ld_item ld_pop_front(ld_deque *deque);
ld_item ld_pop_back(ld_deque *deque);
ld_item ld_front(ld_deque *deque);
ld_item ld_back(ld_deque *deque);
size_t ld_size(ld_deque *deque);
bool ld_is_empty(ld_deque *deque);

ld_deque *ld_create(void);
void ld_destroy(ld_deque *deque);

#endif