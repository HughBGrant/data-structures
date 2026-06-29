#include "calculator.h"
#include "linked_stack.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

bool IsNumber(char Cipher)
{
	int ArrayLength = sizeof(NUMBER) / sizeof(char);

	for (int i = 0; i < ArrayLength; i++)
	{
		if (Cipher == NUMBER[i])
		{
			return true;
		}
	}
	return false;
}

size_t GetTokenLength(char* Expression, char* Token)
{
    size_t i = 0;

    for (i = 0; Expression[i] != '\0'; i++)
    {
        Token[i] = Expression[i];

        if (IsNumber(Expression[i]) == false)
        {
            break;
        }
        if (IsNumber(Expression[i + 1]) == false)
        {
            break;
        }
    }
    i++;
    Token[i] = '\0';

    return i;
}
int GetPriority(char Operator, bool InStack)
{
    switch (Operator)
    {
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
void GetPostfix(char* Infix, char* Postfix)
{
    LinkedStack* Stack = LS_CreateStack();

    size_t i = 0;
    size_t size = 0;
    char* Top = NULL;
    char Token[32];

    while (i < strlen(Infix)) // 중위 표기식을 다 읽을 때까지 반복
    {
        size = GetTokenLength(&Infix[i], Token);

        if (isdigit(Infix[i])) // 토큰이 피연산자라면
        {
            strcat(Postfix, Token);
            strcat(Postfix, " ");
        }
        else if (Infix[i] == '(') // 토큰이 왼쪽 괄호라면
        {
            LS_Push(Stack, Token);
        }
        else if (Infix[i] == ')') // 토큰이 오른쪽 괄호라면
        {
            while (!LS_IsEmpty(Stack))
            {
                Top = LS_Top(Stack);

                if (Top[0] == '(')
                {
                    LS_Pop(Stack);
                    break;
                }
                strcat(Postfix, Top);
                strcat(Postfix, " ");
                LS_Pop(Stack);
            }
        }
        else // 토큰이 연산자라면
        {
            while (!LS_IsEmpty(Stack) &&
                (GetPriority(LS_Top(Stack)[0], true) >= GetPriority(Token[0], false)))
            {
                Top = LS_Top(Stack);

                if (Top[0] != '(')
                {
                    strcat(Postfix, Top);
                    strcat(Postfix, " ");//
                }
                LS_Pop(Stack);
            }
            LS_Push(Stack, Token);
        }
        i += size;
    }
    while (!LS_IsEmpty(Stack)) // 스택에 남아있는 연산자를 츨력
    {
        Top = LS_Top(Stack);

        if (Top[0] != '(')
        {
            strcat(Postfix, Top);
            strcat(Postfix, " ");//
        }
        LS_Pop(Stack);
    }
    LS_DestroyStack(Stack);
}
double Calculate(char* Postfix)
{
    LinkedStack* Stack = LS_CreateStack();
    double Result;

    char Token[32];
    size_t size = 0;
    size_t Position = 0;


    while (Position < strlen(Postfix))
    {
        size = GetTokenLength(&Postfix[Position], Token);

        if (Postfix[Position] == ' ')
        {
            Position += size;
            continue;
        }

        if (isdigit(Postfix[Position]))
        {
            LS_Push(Stack, Token);
        }
        else
        {
            double Operand1, Operand2, TempResult = 0;
            char TempResultStr[32];

            Operand2 = atof(LS_Top(Stack));
            LS_Pop(Stack);

            Operand1 = atof(LS_Top(Stack));
            LS_Pop(Stack);

            switch (Postfix[Position])
            {
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
            LS_Push(Stack, TempResultStr);
        }
        Position += size;
    }
    Result = atof(LS_Top(Stack));
    LS_Pop(Stack);

    LS_DestroyStack(Stack);

    return Result;
}
