#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int LItem;
typedef struct LinkedStack LStack;

void ls_push(LStack *stack, LItem value);
LItem ls_pop(LStack *stack);
LItem ls_top(LStack *stack);
size_t ls_size(LStack *stack);
bool ls_is_empty(LStack *stack);

LStack *ls_create(void);
void ls_destroy(LStack *stack);

#endif