#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int ls_data;

typedef struct _ls_node {
    ls_data data;
    struct _ls_node *next;
} ls_node;

typedef struct {
    ls_node *top;
} ls_stack;

void ls_push(ls_stack *stack, ls_data data);
void ls_pop(ls_stack *stack);
ls_data *ls_top(ls_stack *stack);
size_t ls_size(ls_stack *stack);
bool ls_is_empty(ls_stack *stack);

ls_stack *ls_create(void);
void ls_destroy(ls_stack *stack);
ls_node *ls_node_create(ls_data data);
void ls_node_destroy(ls_node *node);

#endif