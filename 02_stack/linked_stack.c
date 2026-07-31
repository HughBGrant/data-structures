#include "linked_stack.h"

linked_stack *ls_create(void)
{
    linked_stack *stack = malloc(sizeof(linked_stack));

    if (stack == NULL) {
        return NULL;
    }

    stack->top = NULL;

    return stack;
}

ls_node *ls_node_create(ls_data data)
{
    ls_node *new_node = malloc(sizeof(ls_node));

    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
void ls_node_destroy(ls_node *node)
{
    free(node);
}
void ls_push(linked_stack *stack, ls_data data)
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

void ls_pop(linked_stack *stack)
{
    if (stack == NULL || ls_is_empty(stack)) {
        return;
    }

    ls_node *target_node = stack->top;
    stack->top = target_node->next;

    ls_node_destroy(target_node);
}

ls_data *ls_top(linked_stack *stack)
{
    if (stack == NULL || ls_is_empty(stack)) {
        return NULL;
    }

    return &stack->top->data;
}

size_t ls_size(linked_stack *stack)
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

bool ls_is_empty(linked_stack *stack)
{
    return stack == NULL || stack->top == NULL;
}

void ls_destroy(linked_stack *stack)
{
    if (stack == NULL) {
        return;
    }

    while (!ls_is_empty(stack)) {
        ls_pop(stack);
    }

    free(stack);
}