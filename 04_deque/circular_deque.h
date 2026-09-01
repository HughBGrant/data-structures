#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_DEQUE_H
#define CIRCULAR_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int CItem;
typedef struct CircularDeque CDeque;

void cd_push_front(CDeque *deque, CItem data);
void cd_push_back(CDeque *deque, CItem data);
void cd_resize(CDeque *deque);
CItem cd_pop_front(CDeque *deque);
CItem cd_pop_back(CDeque *deque);
CItem cd_front(CDeque *deque);
CItem cd_back(CDeque *deque);
bool cd_is_empty(CDeque *deque);
size_t cd_size(CDeque *deque);

CDeque *cd_create(void);
void cd_destroy(CDeque *deque);

#endif