#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _ls_node {
    ls_item data;
    struct _ls_node *next;
} ls_node;

struct linked_stack {
    ls_node *top;
};

static ls_node *ls_node_create(ls_item data)
{
    ls_node *new_node = malloc(sizeof(ls_node));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
static void ls_node_destroy(ls_node *node)
{
    free(node);
}
ls_stack *ls_create(void)
{
    ls_stack *stack = malloc(sizeof(ls_stack));

    if (stack == NULL) {
        return NULL;
    }

    stack->top = NULL;

    return stack;
}
void ls_destroy(ls_stack *stack)
{
    if (stack == NULL) {
        return;
    }

    while (!ls_is_empty(stack)) {
        ls_pop(stack);
    }

    free(stack);
}
void ls_push(ls_stack *stack, ls_item data)
{
    if (stack == NULL) {
        return;
    }

    ls_node *new_top = ls_node_create(data);

    if (new_top == NULL) {
        return;
    }

    new_top->next = stack->top;
    stack->top = new_top;
}

void ls_pop(ls_stack *stack)
{
    if (ls_is_empty(stack)) {
        return;
    }

    ls_node *target_node = stack->top;
    stack->top = target_node->next;

    ls_node_destroy(target_node);
}

ls_item *ls_top(ls_stack *stack)
{
    if (ls_is_empty(stack)) {
        return NULL;
    }

    return &stack->top->data;
}
size_t ls_size(ls_stack *stack)
{
    if (stack == NULL) {
        return 0;
    }

    size_t size = 0;
    ls_node *current_node = stack->top;

    while (current_node != NULL) {
        size++;
        current_node = current_node->next;
    }

    return size;
}
bool ls_is_empty(ls_stack *stack)
{
    return stack == NULL || stack->top == NULL;
}
