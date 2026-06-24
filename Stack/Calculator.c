#include "Calculator.h"
#include "LinkedListStack.h"

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
size_t GetTokenSize(char* Expression, char* Token, int* TYPE)
{
    size_t i = 0;

    for (i = 0; 0 != Expression[i]; i++)
    {
        Token[i] = Expression[i];

        if (IsNumber(Expression[i]) == false)
        {
            *TYPE = Expression[i];
            break;
        }
        if (IsNumber(Expression[i + 1]) == false)
        {
            *TYPE = OPERAND;
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
    case LEFT_PARENTHESIS:
        if (InStack)
            return 0;
        else
            return 3;

    case PLUS:
    case MINUS:
        return 1;

    case MULTIPLY:
    case DIVIDE:
        return 2;
    }
    return -1;
}
void GetPostfix(char* Infix, char* Postfix)
{
    LinkedListStack* Stack = NULL;
    LLS_CreateStack(&Stack);

    size_t i = 0;
    char* Top = NULL;
    char Token[32];
    int Type;

    while (i < strlen(Infix))
    {
        i += GetTokenSize(&Infix[i], Token, &Type);

        if (Type == OPERAND)
        {
            strcat(Postfix, Token);
            strcat(Postfix, " ");
        }
        else if (Type == RIGHT_PARENTHESIS)
        {
            while (!LLS_IsEmpty(Stack))
            {
                Top = LLS_Top(Stack);

                if (Top[0] == LEFT_PARENTHESIS)
                {
                    LLS_Pop(Stack);
                    break;
                }
                strcat(Postfix, Top);
                strcat(Postfix, " ");
                LLS_Pop(Stack);
            }
        }
        else
        {
            while (!LLS_IsEmpty(Stack) &&
                (GetPriority(LLS_Top(Stack)[0], true) >= GetPriority(Token[0], false)))
            {
                Top = LLS_Top(Stack);

                if (Top[0] != LEFT_PARENTHESIS)
                {
                    strcat(Postfix, Top);
                    strcat(Postfix, " ");//
                }
                LLS_Pop(Stack);
            }
            LLS_Push(Stack, Token);
        }
    }
    while (!LLS_IsEmpty(Stack))
    {
        Top = LLS_Top(Stack);

        if (Top[0] != LEFT_PARENTHESIS)
        {
            strcat(Postfix, Top);
            strcat(Postfix, " ");//
        }
        LLS_Pop(Stack);
    }
    LLS_DestroyStack(Stack);
}
double Calculate(char* Postfix)
{
    LinkedListStack* Stack;
    double Result;

    char Token[32];
    int  Type = -1;
    size_t Position = 0;
    size_t Length = strlen(Postfix);

    LLS_CreateStack(&Stack);

    while (Position < Length)
    {
        Position += GetTokenSize(&Postfix[Position], Token, &Type);

        if (Type == SPACE)
            continue;

        if (Type == OPERAND)
        {
            LLS_Push(Stack, Token);
        }
        else
        {
            double Operand1, Operand2, TempResult = 0;
            char TempResultStr[32];

            Operand2 = atof(LLS_Top(Stack));
            LLS_Pop(Stack);

            Operand1 = atof(LLS_Top(Stack));
            LLS_Pop(Stack);

            switch (Type)
            {
            case PLUS:
                TempResult = Operand1 + Operand2;
                break;
            case MINUS:
                TempResult = Operand1 - Operand2;
                break;
            case MULTIPLY:
                TempResult = Operand1 * Operand2;
                break;
            case DIVIDE:
                TempResult = Operand1 / Operand2;
                break;
            }
            _gcvt(TempResult, 10, TempResultStr);
            LLS_Push(Stack, TempResultStr);
        }
    }
    Result = atof(LLS_Top(Stack));
    LLS_Pop(Stack);

    LLS_DestroyStack(Stack);

    return Result;
}
