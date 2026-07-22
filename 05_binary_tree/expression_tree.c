#include "expression_tree.h"

bt_node *build_expression_tree(char *expression)
{
    size_t len = strlen(expression);
    if (len == 0) {
        return NULL;
    }

    bt_data token = expression[len - 1];
    bt_node *new_node = bt_create_node(token);
    if (new_node == NULL) {
        return NULL;
    }

    expression[len - 1] = '\0';

    switch (token) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        new_node->right = build_expression_tree(expression);
        new_node->left = build_expression_tree(expression);

        if (new_node->right == NULL || new_node->left == NULL) {
            bt_destroy_subtree(new_node);
            return NULL;
        }
        break;
    }
    return new_node;
}
double evaluate_tree(bt_node *subtree)
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
        left = evaluate_tree(subtree->left);
        right = evaluate_tree(subtree->right);

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
