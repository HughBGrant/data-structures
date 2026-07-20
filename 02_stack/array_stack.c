#include "array_stack.h"

array_stack *as_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    array_stack *stack = malloc(sizeof(array_stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->items = malloc(sizeof(as_data) * capacity);
    if (stack->items == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->count = 0;

    return stack;
}
void as_push(array_stack *stack, as_data data)
{
    if (stack == NULL) {
        return;
    }

    if (stack->count == stack->capacity) {
        size_t new_capacity = stack->capacity * 2;

        as_data *new_items = realloc(stack->items, sizeof(as_data) * new_capacity);
        if (new_items == NULL) {
            return; // 메모리 부족
        }

        stack->items = new_items;
        stack->capacity = new_capacity;
    }
    stack->items[stack->count] = data;
    stack->count++;
}
void as_pop(array_stack *stack)
{
    if (stack == NULL || as_is_empty(stack)) {
        return;
    }
    stack->count--;
}
as_data *as_top(array_stack *stack)
{
    if (stack == NULL || as_is_empty(stack)) {
        return NULL;
    }
    return &stack->items[stack->count - 1];
}
size_t as_size(array_stack *stack)
{
    if (stack == NULL) {
        return 0;
    }
    return stack->count;
}
bool as_is_empty(array_stack *stack)
{
    if (stack == NULL) {
        return true;
    }
    return stack->count == 0;
}
bool as_is_full(array_stack *stack)
{
    if (stack == NULL) {
        return false;
    }
    return stack->count == stack->capacity;
}
void as_destroy(array_stack *stack)
{
    if (stack == NULL) {
        return;
    }
    free(stack->items);
    free(stack);
}