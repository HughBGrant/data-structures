#include "expression_tree.h"

bt_node *build(char *expression)
{
    if (expression == NULL || expression[0] == '\0') {
        return NULL;
    }

    size_t len = strlen(expression);
    bt_node **stack = malloc(sizeof(bt_node *) * len);

    if (stack == NULL) {
        return NULL;
    }

    int top = -1;

    for (size_t i = 0; i < len; i++) {
        bt_data token = expression[i];

        if ((token == '+' ||
             token == '-' ||
             token == '*' ||
             token == '/') &&
            top < 1) {

            while (top >= 0) {
                bt_destroy_subtree(stack[top--]);
            }

            free(stack);
            return NULL;
        }

        bt_node *new_node = bt_create_node(token);

        if (new_node == NULL) {
            while (top >= 0) {
                bt_destroy_subtree(stack[top--]);
            }

            free(stack);
            return NULL;
        }

        switch (token) {
        case '+':
        case '-':
        case '*':
        case '/':
            new_node->right = stack[top--];
            new_node->left = stack[top--];
            break;
        }

        stack[++top] = new_node;
    }

    if (top != 0) {
        while (top >= 0) {
            bt_destroy_subtree(stack[top--]);
        }

        free(stack);
        return NULL;
    }

    bt_node *root = stack[0];
    free(stack);

    return root;
}
double evaluate(bt_node *subtree)
{
    if (subtree == NULL) {
        return 0;
    }

    if (subtree->data >= '0' && subtree->data <= '9') {
        return (double)(subtree->data - '0');
    }
    double left = evaluate(subtree->left);
    double right = evaluate(subtree->right);
    double result = 0;

    switch (subtree->data) {
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
