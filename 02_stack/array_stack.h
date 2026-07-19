#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int as_data;

typedef struct {
    as_data *items;
    size_t count;
    size_t capacity;
} array_stack;

array_stack *as_create(size_t capacity);
void as_push(array_stack *stack, as_data data);
void as_pop(array_stack *stack);
as_data *as_top(array_stack *stack);
void as_destroy(array_stack *stack);

bool as_is_empty(array_stack *stack);
bool as_is_full(array_stack *stack);
size_t as_size(array_stack *stack);

#endif
