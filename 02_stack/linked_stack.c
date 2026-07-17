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
ls_node *ls_create_node(ls_data data)
{
    if (data == NULL) {
        return NULL;
    }
    ls_node *new_node = malloc(sizeof(ls_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        free(new_node);
        return NULL;
    }

    strcpy(new_node->data, data);
    new_node->next = NULL;

    return new_node;
}
void ls_push(linked_stack *stack, ls_data data)
{
    if (stack == NULL) {
        return;
    }
    ls_node *new_top = ls_create_node(data);
    if (new_top == NULL) {
        return;
    }

    if (stack->top) {
        new_top->next = stack->top;
    }
    stack->top = new_top;
}
void ls_pop(linked_stack *stack)
{
    if (stack == NULL || ls_is_empty(stack)) {
        return;
    }
    ls_node *free_node = stack->top;

    stack->top = free_node->next;

    free(free_node->data);
    free(free_node);
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

    while (current_node) {
        size++;
        current_node = current_node->next;
    }

    return size;
}
bool ls_is_empty(linked_stack *stack)
{
    if (stack == NULL)
        return true;
    return stack->top == NULL;
}

void ls_destroy(linked_stack *stack)
{
    if (stack == NULL) {
        return;
    }
    while (stack->top) {
        ls_pop(stack);
    }
    free(stack);
}