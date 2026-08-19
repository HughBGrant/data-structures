#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>

struct array_stack {
    as_item *data;
    size_t capacity;
    size_t count;
};

as_stack *as_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    as_stack *stack = malloc(sizeof(as_stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->data = malloc(sizeof(as_item) * capacity);
    if (stack->data == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->count = 0;

    return stack;
}
void as_destroy(as_stack *stack)
{
    if (stack == NULL) {
        return;
    }
    free(stack->data);
    free(stack);
}
void as_push(as_stack *stack, as_item data)
{
    if (stack == NULL) {
        return;
    }

    if (stack->count == stack->capacity) {
        size_t new_capacity = stack->capacity * 2;

        as_item *new_items = realloc(stack->data, sizeof(as_item) * new_capacity);
        if (new_items == NULL) {
            return; // 메모리 부족
        }

        stack->data = new_items;
        stack->capacity = new_capacity;
    }
    stack->data[stack->count] = data;
    stack->count++;
}
void as_pop(as_stack *stack)
{
    if (as_is_empty(stack)) {
        return;
    }
    stack->count--;
}
as_item *as_top(as_stack *stack)
{
    if (as_is_empty(stack)) {
        return NULL;
    }
    return &stack->data[stack->count - 1];
}
size_t as_size(as_stack *stack)
{
    return stack ? stack->count : 0;
}
bool as_is_empty(as_stack *stack)
{
    return stack == NULL || stack->count == 0;
}