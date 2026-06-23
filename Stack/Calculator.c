#include "Calculator.h"
#include "LinkedListStack.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };

bool IsNumber(char Cipher)
{
	int ArrayLength = sizeof(NUMBER);

	for (int i = 0; i < ArrayLength; i++)
	{
		if (Cipher == NUMBER[i])
		{
			return true;
		}
	}
	return false;
}
size_t GetNextToken(char* Expression, char* Token, int* TYPE)
{
    size_t i = 0;

    for (i = 0; 0 != Expression[i]; i++)
    {
        Token[i] = Expression[i];

        if (IsNumber(Expression[i]) == true)
        {
            *TYPE = OPERAND;

            if (IsNumber(Expression[i + 1]) != true)
                break;
        }
        else
        {
            *TYPE = Expression[i];
            break;
        }
    }
    i++;
    Token[i] = '\0';
    return i;
}
int GetPriority(char Operator, int InStack)
{
    int Priority = -1;

    switch (Operator)
    {
    case LEFT_PARENTHESIS:
        if (InStack)
            Priority = 0;
        else
            Priority = 3;
        break;

    case MULTIPLY:
    case DIVIDE:
        Priority = 2;
        break;

    case PLUS:
    case MINUS:
        Priority = 1;
        break;
    }
    return Priority;
}
void GetPostfix(char* InfixExpression, char* PostfixExpression)
{
    LinkedListStack* Stack;

    char Token[32];
    int  Type = -1;
    size_t Position = 0;
    size_t Length = strlen(InfixExpression);

    LLS_CreateStack(&Stack);

    while (Position < Length)
    {
        Position += GetNextToken(&InfixExpression[Position], Token, &Type);

        if (Type == OPERAND)
        {
            strcat(PostfixExpression, Token);
            strcat(PostfixExpression, " ");
        }
        else if (Type == RIGHT_PARENTHESIS)
        {
            while (!LLS_IsEmpty(Stack))
            {
                char* Top = LLS_Top(Stack);

                if (Top[0] == LEFT_PARENTHESIS)
                {
                    LLS_Pop(Stack);
                    break;
                }
                else
                {
                    strcat(PostfixExpression, Top);
                    LLS_Pop(Stack);
                }
            }
        }
        else
        {
            while (!LLS_IsEmpty(Stack) &&
                (GetPriority(LLS_Top(Stack)[0], 1) >= GetPriority(Token[0], 0)))
            {
                char* Top = LLS_Top(Stack);

                if (Top[0] != LEFT_PARENTHESIS)
                    strcat(PostfixExpression, Top);
                LLS_Pop(Stack);
            }
            LLS_Push(Stack, Token);
        }
    }
    while (!LLS_IsEmpty(Stack))
    {
        char* Top = LLS_Top(Stack);

        if (Top[0] != LEFT_PARENTHESIS)
            strcat(PostfixExpression, Top);

        LLS_Pop(Stack);
    }
    LLS_DestroyStack(Stack);
}
double Calculate(char* PostfixExpression)
{
    LinkedListStack* Stack;
    char* ResultData;

    double Result;
    char Token[32];
    int  Type = -1;
    size_t Read = 0;
    size_t Length = strlen(PostfixExpression);

    LLS_CreateStack(&Stack);

    while (Read < Length)
    {
        Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

        if (Type == SPACE)
            continue;

        if (Type == OPERAND)
        {
            LLS_Push(Stack, Token);
        }
        else
        {
            char   ResultString[32];
            double Operator1, Operator2, TempResult;
            char* OperatorData;

            OperatorData = LLS_Top(Stack);
            Operator2 = atof(OperatorData);
            LLS_Pop(Stack);

            OperatorData = LLS_Top(Stack);
            Operator1 = atof(OperatorData);
            LLS_Pop(Stack);

            switch (Type)
            {
            case PLUS:     TempResult = Operator1 + Operator2; break;
            case MINUS:    TempResult = Operator1 - Operator2; break;
            case MULTIPLY: TempResult = Operator1 * Operator2; break;
            case DIVIDE:   TempResult = Operator1 / Operator2; break;
            }
            _gcvt(TempResult, 10, ResultString);
            LLS_Push(Stack, ResultString);
        }
    }
    ResultData = LLS_Top(Stack);
    Result = atof(ResultData);
    LLS_Pop(Stack);

    LLS_DestroyStack(Stack);

    return Result;
}
