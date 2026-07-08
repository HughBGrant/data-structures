#include "linked_stack.h"

linked_stack *ls_create(void)
{
    linked_stack *stack = malloc(sizeof(linked_stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    stack->count = 0;

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

    if (stack->top != NULL) {
        new_top->next = stack->top;
    }
    stack->top = new_top;
    stack->count++;
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
    stack->count--;
}
ls_data ls_top(linked_stack *stack)
{
    if (stack == NULL || ls_is_empty(stack)) {
        return NULL;
    }
    return stack->top->data;
}
size_t ls_size(linked_stack *stack)
{
    if (stack == NULL) {
        return 0;
    }
    return stack->count;
}
bool ls_is_empty(linked_stack *stack)
{
    if (stack == NULL)
        return true;
    return stack->count == 0;
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