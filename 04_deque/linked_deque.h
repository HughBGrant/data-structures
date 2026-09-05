#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedDeque LDeque;

void l_push_front(LDeque *deque, int data);
void l_push_back(LDeque *deque, int data);
int l_pop_front(LDeque *deque);
int l_pop_back(LDeque *deque);
int l_front(LDeque *deque);
int l_back(LDeque *deque);
size_t l_size(LDeque *deque);
bool l_is_empty(LDeque *deque);

LDeque *l_create(void);
void l_destroy(LDeque *deque);

#endif