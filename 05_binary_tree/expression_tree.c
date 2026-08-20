#include "expression_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lbt_node *build(char *expression)
{
    if (expression == NULL || expression[0] == '\0') {
        return NULL;
    }

    size_t len = strlen(expression);
    lbt_node **stack = malloc(sizeof(lbt_node *) * len);

    if (stack == NULL) {
        return NULL;
    }

    int top = -1;

    for (size_t i = 0; i < len; i++) {
        lbt_item token = expression[i];

        if ((token == '+' ||
             token == '-' ||
             token == '*' ||
             token == '/') &&
            top < 1) {

            while (top >= 0) {
                lbt_subtree_destroy(stack[top--]);
            }

            free(stack);
            return NULL;
        }

        lbt_node *new_node = lbt_node_create(token);

        if (new_node == NULL) {
            while (top >= 0) {
                lbt_subtree_destroy(stack[top--]);
            }

            free(stack);
            return NULL;
        }

        switch (token) {
        case '+':
        case '-':
        case '*':
        case '/':
            lbt_set_right(new_node, stack[top--]);
            lbt_set_left(new_node, stack[top--]);
            break;
        }

        stack[++top] = new_node;
    }

    if (top != 0) {
        while (top >= 0) {
            lbt_subtree_destroy(stack[top--]);
        }

        free(stack);
        return NULL;
    }

    lbt_node *root = stack[0];
    free(stack);

    return root;
}
double evaluate(lbt_node *subtree)
{
    if (subtree == NULL) {
        return 0;
    }

    if (lbt_data(subtree) >= '0' && lbt_data(subtree) <= '9') {
        return (double)(lbt_data(subtree) - '0');
    }
    double left = evaluate(lbt_left(subtree));
    double right = evaluate(lbt_right(subtree));
    double result = 0;

    switch (lbt_data(subtree)) {
    case '+':
        return left + right;

    case '-':
        return left - right;

    case '*':
        return left * right;

    case '/':
        if (right == 0.0) {
            return 0;
        }
        return left / right;

    default:
        return 0;
    }
    return result;
}
