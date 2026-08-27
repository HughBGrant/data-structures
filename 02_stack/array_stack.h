#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef int as_item;
typedef struct array_stack as_stack;

void as_push(as_stack *stack, as_item value);
as_item as_pop(as_stack *stack);
as_item as_top(as_stack *stack);
bool as_is_empty(as_stack *stack);
size_t as_size(as_stack *stack);

as_stack *as_create(void);
void as_destroy(as_stack *stack);

#endif
