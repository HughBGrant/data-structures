#include "postfix_calculator.h"
#include "linked_stack.h"

bool is_operand(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int prioritize(char operator, bool in_stack)
{
    switch (operator) {
    case ')':
        return 0;

    case '(':
        return in_stack ? 0 : 5;

    case '+':
    case '-':
        return in_stack ? 2 : 1;

    case '*':
    case '/':
        return in_stack ? 4 : 3;

    default:
        return -1;
    }
}

void convert(char *infix, char *postfix)
{
    if (infix == NULL || postfix == NULL)
        return;

    linked_stack *stack = ls_create();
    if (stack == NULL) {
        return;
    }

    size_t input_pos = 0;
    size_t output_pos = 0;

    while (infix[input_pos] != '\0') {
        char symbol = infix[input_pos];

        if (is_operand(symbol)) {
            postfix[output_pos++] = symbol;
            input_pos++;
            continue;
        }

        if (ls_is_empty(stack)) {
            ls_push(stack, symbol);
            input_pos++;
            continue;
        }

        char operator_in_stack = (char)*ls_top(stack);

        int input_priority = prioritize(symbol, false);
        int stack_priority = prioritize(operator_in_stack, true);

        if (input_priority > stack_priority) {
            ls_push(stack, symbol);
            input_pos++;
        } else if (input_priority == stack_priority) {
            ls_pop(stack);
            input_pos++;
        } else {
            postfix[output_pos++] = operator_in_stack;
            ls_pop(stack);
        }
    }

    while (!ls_is_empty(stack)) {
        postfix[output_pos++] = (char)*ls_top(stack);
        ls_pop(stack);
    }

    postfix[output_pos] = '\0';

    ls_destroy(stack);
}

int evaluate(const char *postfix)
{
    linked_stack *stack = ls_create();

    if (postfix == NULL || stack == NULL) {
        ls_destroy(stack);
        return 0;
    }

    for (size_t i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        if (is_operand(symbol)) {
            ls_push(stack, symbol - '0');
        } else {
            int *top = ls_top(stack);

            if (top == NULL) {
                ls_destroy(stack);
                return 0;
            }

            int operand2 = *top;
            ls_pop(stack);

            top = ls_top(stack);

            if (top == NULL) {
                ls_destroy(stack);
                return 0;
            }

            int operand1 = *top;
            ls_pop(stack);

            int result = 0;

            switch (symbol) {
            case '+':
                result = operand1 + operand2;
                break;

            case '-':
                result = operand1 - operand2;
                break;

            case '*':
                result = operand1 * operand2;
                break;

            case '/':
                if (operand2 == 0) {
                    ls_destroy(stack);
                    return 0;
                }

                result = operand1 / operand2;
                break;

            default:
                ls_destroy(stack);
                return 0;
            }

            ls_push(stack, result);
        }
    }

    int *top = ls_top(stack);
    int result = top == NULL ? 0 : *top;

    ls_destroy(stack);

    return result;
}