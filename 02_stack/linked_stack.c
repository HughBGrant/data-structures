#include "linked_stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _ls_node {
    LItem data;
    struct _ls_node *next;
} ls_node;

struct LinkedStack {
    ls_node *top;
};

static ls_node *ls_node_create(LItem data);

static void ls_node_destroy(ls_node *node);

static ls_node *ls_node_create(LItem data)
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
LStack *ls_create(void)
{
    LStack *stack = malloc(sizeof(LStack));

    if (stack == NULL) {
        return NULL;
    }

    stack->top = NULL;

    return stack;
}
void ls_destroy(LStack *stack)
{
    if (stack == NULL) {
        return;
    }

    while (!ls_is_empty(stack)) {
        ls_pop(stack);
    }

    free(stack);
}
void ls_push(LStack *stack, LItem data)
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

LItem ls_pop(LStack *stack)
{
    if (ls_is_empty(stack)) {
        return 0;
    }

    ls_node *target_node = stack->top;
    stack->top = target_node->next;

    LItem data = target_node->data;
    ls_node_destroy(target_node);
    return data;
}

LItem ls_top(LStack *stack)
{
    if (ls_is_empty(stack)) {
        return 0;
    }

    return stack->top->data;
}
size_t ls_size(LStack *stack)
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
bool ls_is_empty(LStack *stack)
{
    return stack == NULL || stack->top == NULL;
}
