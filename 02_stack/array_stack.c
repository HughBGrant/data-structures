#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8

struct ArrayStack {
    AItem *items;
    size_t capacity;
    size_t size;
};

AStack *as_create(void)
{
    AStack *stack = malloc(sizeof(AStack));
    if (stack == NULL) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    stack->items = malloc(sizeof(AItem) * capacity);
    if (stack->items == NULL) {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}
void as_destroy(AStack *stack)
{
    if (stack == NULL) {
        return;
    }
    free(stack->items);
    free(stack);
}
void as_push(AStack *stack, AItem data)
{
    if (stack == NULL) {
        return;
    }

    if (stack->size == stack->capacity) {
        size_t new_capacity = stack->capacity * 2;

        AItem *new_items = realloc(stack->items, sizeof(AItem) * new_capacity);
        if (new_items == NULL) {
            return; // 메모리 부족
        }

        stack->items = new_items;
        stack->capacity = new_capacity;
    }
    stack->items[stack->size] = data;
    stack->size++;
}
AItem as_pop(AStack *stack)
{
    if (as_is_empty(stack)) {
        return 0;
    }
    stack->size--;
    return stack->items[stack->size];
}
AItem as_top(AStack *stack)
{
    if (as_is_empty(stack)) {
        return 0;
    }
    return stack->items[stack->size - 1];
}
size_t as_size(AStack *stack)
{
    return stack ? stack->size : 0;
}
bool as_is_empty(AStack *stack)
{
    return stack == NULL || stack->size == 0;
}