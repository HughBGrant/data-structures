#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedStack LStack;

void l_push(LStack *stack, int data);
int l_pop(LStack *stack);
int l_top(LStack *stack);
size_t l_size(LStack *stack);
bool l_is_empty(LStack *stack);

LStack *l_create(void);
void l_destroy(LStack *stack);

#endif