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
            if (top < 1) {
                bt_destroy_subtree(new_node);

                while (top >= 0) {
                    bt_destroy_subtree(stack[top--]);
                }

                free(stack);
                return NULL;
            }

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
    char temp[2];

    double left = 0;
    double right = 0;
    double result = 0;

    if (subtree == NULL) {
        return 0;
    }
    switch (subtree->data) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        left = evaluate(subtree->left);
        right = evaluate(subtree->right);

        if (subtree->data == '+')
            result = left + right;
        else if (subtree->data == '-')
            result = left - right;
        else if (subtree->data == '*')
            result = left * right;
        else if (subtree->data == '/')
            result = left / right;
        break;
    default: // 피연산자인 경우
        memset(temp, 0, sizeof(temp));
        temp[0] = subtree->data;
        result = atof(temp);
        break;
    }
    return result;
}
