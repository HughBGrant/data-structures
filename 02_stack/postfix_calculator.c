#include "postfix_calculator.h"
#include "linked_stack.h"

char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

bool is_operand(char symbol)
{
    unsigned long long array_size = strlen(numbers);

    for (size_t i = 0; i < array_size; i++) {
        if (symbol == numbers[i]) {
            return true;
        }
    }
    return false;
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
size_t get_token_size(char *expression, char *token)
{
    if (expression == NULL || token == NULL) {
        return 0;
    }
    size_t size = 0;

    while (expression[size] != '\0') {
        token[size] = expression[size];

        if (is_operand(expression[size]) == false) {
            break;
        }
        if (is_operand(expression[size + 1]) == false) {
            break;
        }
        size++;
    }
    size++;
    token[size] = '\0';

    return size;
}
void convert(char *infix, char *postfix)
{
    if (infix == NULL) {
        return;
    }
    linked_stack *stack = ls_create();
    if (stack == NULL) {
        return;
    }
    size_t pos = 0;
    char token_out[32];

    while (infix[pos] != '\0') // 중위 표기식을 다 읽을 때까지 반복
    {
        size_t token_size = get_token_size(&infix[pos], token_out);

        if (is_operand(token_out[0])) // 토큰이 피연산자라면
        {
            strcat(postfix, token_out);
            strcat(postfix, " ");
            pos += token_size;
            continue;
        }
        if (ls_is_empty(stack)) {
            ls_push(stack, token_out);
            pos += token_size;
            continue;
        }
        ls_data operator_in = *ls_top(stack);

        int input_priority = prioritize(token_out[0], false);
        int stack_priority = prioritize(operator_in[0], true);

        if (input_priority > stack_priority) {
            ls_push(stack, token_out);
            pos += token_size;
        } else if (input_priority == stack_priority) {
            ls_pop(stack);
            pos += token_size;
        } else {
            strcat(postfix, operator_in);
            strcat(postfix, " ");
            ls_pop(stack);
        }
    }
    while (ls_is_empty(stack) == false) {
        ls_data operator_in = *ls_top(stack);

        strcat(postfix, operator_in);
        strcat(postfix, " ");

        ls_pop(stack);
    }
    ls_destroy(stack);
}
double evaluate(char *postfix)
{
    if (postfix == NULL) {
        return 0.0;
    }
    linked_stack *stack = ls_create();
    if (stack == NULL) {
        return 0.0;
    }

    size_t pos = 0;
    char token[32];

    while (pos < strlen(postfix)) {
        size_t token_size = get_token_size(&postfix[pos], token);

        if (postfix[pos] == ' ') {
            pos += token_size;
            continue;
        }

        if (is_operand(token[0])) {
            ls_push(stack, token);
        } else {

            double operand2 = atof(*ls_top(stack));
            ls_pop(stack);

            double operand1 = atof(*ls_top(stack));
            ls_pop(stack);

            double temp = 0;
            switch (postfix[pos]) {
            case '+':
                temp = operand1 + operand2;
                break;
            case '-':
                temp = operand1 - operand2;
                break;
            case '*':
                temp = operand1 * operand2;
                break;
            case '/':
                temp = operand1 / operand2;
                break;
            }
            char temp_str[32];
            _gcvt(temp, 16, temp_str);
            ls_push(stack, temp_str);
        }
        pos += token_size;
    }
    double result = atof(*ls_top(stack));

    ls_destroy(stack);

    return result;
}
