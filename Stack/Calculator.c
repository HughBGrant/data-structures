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
    size_t size = 0;

    for (size = 0; 0 != Expression[size]; size++)
    {
        Token[size] = Expression[size];

        /*if (IsNumber(Expression[size]) == false)
        {
            *TYPE = Expression[size];
            break;
        }
        *TYPE = OPERAND;

        if (IsNumber(Expression[size + 1]) == false)
        {
            break;
        }*/
        if (IsNumber(Expression[size]))
        {
            *TYPE = OPERAND;

            if (IsNumber(Expression[size + 1]) == false)
            {
                break;
            }
        }
        else
        {
            *TYPE = Expression[size];
            break;
        }
    }
    size++;
    Token[size] = '\0';

    return size;
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

    char Token[100];
    int Type;
    size_t Position = 0;
    size_t Length = strlen(Infix);

    while (Position < Length)
    {
        Position += GetTokenSize(&Infix[Position], Token, &Type);

        if (Type == OPERAND)
        {
            strcat(Postfix, Token);
            strcat(Postfix, " ");
        }
        else if (Type == RIGHT_PARENTHESIS)
        {
            while (!LLS_IsEmpty(Stack))
            {
                char* Top = LLS_Top(Stack);

                if (Top[0] != LEFT_PARENTHESIS)
                {
                    strcat(Postfix, Top);
                    strcat(Postfix, " ");//
                }
                LLS_Pop(Stack);
            }
        }
        else
        {
            while (!LLS_IsEmpty(Stack) &&
                (GetPriority(LLS_Top(Stack)[0], 1) >= GetPriority(Token[0], 0)))
            {
                char* Top = LLS_Top(Stack);

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
        char* Top = LLS_Top(Stack);

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
    char* ResultData;

    double Result;
    char Token[32];
    int  Type = -1;
    size_t Read = 0;
    size_t Length = strlen(Postfix);

    LLS_CreateStack(&Stack);

    while (Read < Length)
    {
        Read += GetTokenSize(&Postfix[Read], Token, &Type);

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
