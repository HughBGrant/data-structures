#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_DEQUE_H
#define CIRCULAR_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int cd_item;
typedef struct circular_deque cd_deque;

void cd_push_front(cd_deque *deque, cd_item value);
void cd_push_back(cd_deque *deque, cd_item value);
void cd_resize(cd_deque *deque);
cd_item cd_pop_front(cd_deque *deque);
cd_item cd_pop_back(cd_deque *deque);
cd_item cd_front(cd_deque *deque);
cd_item cd_back(cd_deque *deque);
bool cd_is_empty(cd_deque *deque);
size_t cd_size(cd_deque *deque);

cd_deque *cd_create(void);
void cd_destroy(cd_deque *deque);

#endif