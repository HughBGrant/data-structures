#include "array_stack.h"

array_stack *as_create(size_t capacity)
{
    if (capacity == 0) {
        return NULL;
    }
    array_stack *stack = malloc(sizeof(array_stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->array = malloc(sizeof(as_data) * capacity);
    if (stack->array == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->count = 0;

    return stack;
}
void as_push(array_stack *stack, as_data data)
{
    if (stack == NULL || as_is_full(stack)) {
        return;
    }
    stack->array[stack->count] = data;
    stack->count++;
}
void as_pop(array_stack *stack)
{
    if (stack == NULL || as_is_empty(stack)) {
        return;
    }
    stack->count--;
}
as_data as_top(array_stack *stack)
{
    return stack->array[stack->count - 1];
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
    free(stack->array);
    free(stack);
}