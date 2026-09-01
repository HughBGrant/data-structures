#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int LItem;
typedef struct LinkedDeque LDeque;

void ld_push_front(LDeque *deque, LItem data);
void ld_push_back(LDeque *deque, LItem data);
LItem ld_pop_front(LDeque *deque);
LItem ld_pop_back(LDeque *deque);
LItem ld_front(LDeque *deque);
LItem ld_back(LDeque *deque);
size_t ld_size(LDeque *deque);
bool ld_is_empty(LDeque *deque);

LDeque *ld_create(void);
void ld_destroy(LDeque *deque);

#endif