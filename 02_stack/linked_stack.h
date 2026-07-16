#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *ls_data;

typedef struct _ls_node {
    ls_data data;
    struct _ls_node *next;
} ls_node;

typedef struct {
    ls_node *top;
} linked_stack;

linked_stack *ls_create(void);
ls_node *ls_create_node(ls_data data);
void ls_push(linked_stack *stack, ls_data data);
void ls_pop(linked_stack *stack);
ls_data ls_top(linked_stack *stack);
void ls_destroy(linked_stack *stack);

size_t ls_size(linked_stack *stack);
bool ls_is_empty(linked_stack *stack);

#endif