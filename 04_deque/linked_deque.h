#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int ld_item;

typedef struct _ld_node {
    ld_item data;
    struct _ld_node *next;
    struct _ld_node *prev;
} ld_node;

typedef struct {
    ld_node *rear;
    ld_node *front;
} ld_deque;

void ld_push_front(ld_deque *deque, ld_item data);
void ld_push_back(ld_deque *deque, ld_item data);
void ld_pop_front(ld_deque *deque);
void ld_pop_back(ld_deque *deque);
ld_item *ld_front(ld_deque *deque);
ld_item *ld_back(ld_deque *deque);
size_t ld_size(ld_deque *deque);
bool ld_is_empty(ld_deque *deque);

ld_deque *ld_create(void);
void ld_destroy(ld_deque *deque);
ld_node *ld_node_create(ld_item data);
void ld_node_destroy(ld_node *node);

#endif