#include "calculator.h"
#include "linked_stack.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

bool IsNumber(char Cipher)
{
    int ArrayLength = sizeof(NUMBER) / sizeof(char);

    for (int i = 0; i < ArrayLength; i++) {
        if (Cipher == NUMBER[i]) {
            return true;
        }
    }
    return false;
}

size_t GetTokenLength(char *Expression, char *Token)
{
    size_t i = 0;

    for (i = 0; Expression[i] != '\0'; i++) {
        Token[i] = Expression[i];

        if (IsNumber(Expression[i]) == false) {
            break;
        }
        if (IsNumber(Expression[i + 1]) == false) {
            break;
        }
    }
    i++;
    Token[i] = '\0';

    return i;
}
int GetPriority(char Operator, bool InStack)
{
    switch (Operator) {
    case '(':
        if (InStack)
            return 0;
        else
            return 3;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}
void GetPostfix(char *Infix, char *Postfix)
{
    linked_stack *stack = ls_create();

    size_t i = 0;
    size_t size = 0;
    char *top = NULL;
    char token[32];

    while (i < strlen(Infix)) // 중위 표기식을 다 읽을 때까지 반복
    {
        size = GetTokenLength(&Infix[i], token);

        if (isdigit(Infix[i])) // 토큰이 피연산자라면
        {
            strcat(Postfix, token);
            strcat(Postfix, " ");
        } else if (Infix[i] == '(') // 토큰이 왼쪽 괄호라면
        {
            ls_push(stack, token);
        } else if (Infix[i] == ')') // 토큰이 오른쪽 괄호라면
        {
            while (!ls_is_empty(stack)) {
                top = ls_top(stack);

                if (top[0] == '(') {
                    ls_pop(stack);
                    break;
                }
                strcat(Postfix, top);
                strcat(Postfix, " ");
                ls_top(stack);
            }
        } else // 토큰이 연산자라면
        {
            while (!ls_is_empty(stack) && (GetPriority(ls_top(stack)[0], true) >=
                                           GetPriority(token[0], false))) {
                top = ls_top(stack);

                if (top[0] != '(') {
                    strcat(Postfix, top);
                    strcat(Postfix, " "); //
                }
                ls_pop(stack);
            }
            ls_push(stack, token);
        }
        i += size;
    }
    while (!ls_is_empty(stack)) // 스택에 남아있는 연산자를 츨력
    {
        top = ls_top(stack);

        if (top[0] != '(') {
            strcat(Postfix, top);
            strcat(Postfix, " "); //
        }
        ls_top(stack);
    }
    ls_destroy(stack);
}
double Calculate(char *Postfix)
{
    linked_stack *stack = ls_create();
    double Result;

    char Token[32];
    size_t size = 0;
    size_t Position = 0;

    while (Position < strlen(Postfix)) {
        size = GetTokenLength(&Postfix[Position], Token);

        if (Postfix[Position] == ' ') {
            Position += size;
            continue;
        }

        if (isdigit(Postfix[Position])) {
            ls_push(stack, Token);
        } else {
            double Operand1, Operand2, TempResult = 0;
            char TempResultStr[32];

            Operand2 = atof(ls_top(stack));
            ls_top(stack);

            Operand1 = atof(ls_top(stack));
            ls_top(stack);

            switch (Postfix[Position]) {
            case '+':
                TempResult = Operand1 + Operand2;
                break;
            case '-':
                TempResult = Operand1 - Operand2;
                break;
            case '*':
                TempResult = Operand1 * Operand2;
                break;
            case '/':
                TempResult = Operand1 / Operand2;
                break;
            }
            _gcvt(TempResult, 10, TempResultStr);
            ls_push(stack, TempResultStr);
        }
        Position += size;
    }
    Result = atof(ls_top(stack));
    ls_top(stack);

    ls_destroy(stack);

    return Result;
}
