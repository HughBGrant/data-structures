#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int ls_item;
typedef struct linked_stack ls_stack;

void ls_push(ls_stack *stack, ls_item data);
void ls_pop(ls_stack *stack);
ls_item *ls_top(ls_stack *stack);
size_t ls_size(ls_stack *stack);
bool ls_is_empty(ls_stack *stack);

ls_stack *ls_create(void);
void ls_destroy(ls_stack *stack);

#endif