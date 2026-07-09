#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *ld_data;

typedef struct _ld_node {
    ld_data data;
    struct _ld_node *next;
} ld_node;

typedef struct {
    ld_node *rear;
    ld_node *front;
} linked_deque;

linked_deque *ld_create(void);
ld_node *ld_create_node(ld_data data);
void ld_push_front(linked_deque *deque, ld_data data);
void ld_push_back(linked_deque *deque, ld_data data);
void ld_pop_front(linked_deque *deque);
void ld_pop_back(linked_deque *deque);
ld_data ld_front(linked_deque *deque);
ld_data ld_back(linked_deque *deque);
void ld_destroy(linked_deque *deque);
size_t ld_size(linked_deque *deque);
bool ld_is_empty(linked_deque *deque);

#endif