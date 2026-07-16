#include "array_stack.h"

array_stack *as_create(size_t max_size)
{
    if (max_size == 0) {
        return NULL;
    }
    array_stack *stack = malloc(sizeof(array_stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->items = malloc(sizeof(as_data) * max_size);
    if (stack->items == NULL) {
        free(stack);
        return NULL;
    }
    stack->max_size = max_size;
    stack->top = -1;

    return stack;
}
void as_push(array_stack *stack, as_data data)
{
    if (stack == NULL || as_is_full(stack)) {
        return;
    }
    stack->top++;
    stack->items[stack->top] = data;
}
void as_pop(array_stack *stack)
{
    if (stack == NULL || as_is_empty(stack)) {
        return;
    }
    stack->top--;
}
as_data as_top(array_stack *stack)
{
    return stack->items[stack->top];
}
size_t as_size(array_stack *stack)
{
    if (stack == NULL) {
        return 0;
    }
    return (size_t)(stack->top + 1);
}
bool as_is_empty(array_stack *stack)
{
    if (stack == NULL) {
        return true;
    }
    return stack->top == -1;
}
bool as_is_full(array_stack *stack)
{
    if (stack == NULL) {
        return false;
    }
    return (size_t)(stack->top + 1) == stack->max_size;
}
void as_destroy(array_stack *stack)
{
    if (stack == NULL) {
        return;
    }
    free(stack->items);
    free(stack);
}