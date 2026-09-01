#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int AItem;
typedef struct ArrayStack AStack;

void as_push(AStack *stack, AItem value);
AItem as_pop(AStack *stack);
AItem as_top(AStack *stack);
bool as_is_empty(AStack *stack);
size_t as_size(AStack *stack);

AStack *as_create(void);
void as_destroy(AStack *stack);

#endif
