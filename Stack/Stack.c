#define _CRT_SECURE_NO_WARNINGS

#include "ArrayStack.h"
#include "LinkedListStack.h"
#include "Calculator.h"

void TestAS(void)
{
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);

	printf("Capacity: %zu, Count: %zu, Top: %d\n",
		Stack->Capacity, AS_GetCount(Stack), AS_Top(Stack));

	while (!AS_IsEmpty(Stack))
	{
		printf("Popped: %d, ", AS_Top(Stack));
		AS_Pop(Stack);

		if (!AS_IsEmpty(Stack))
			printf("Current Top: %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}
	AS_DestroyStack(Stack);
}
void TestLLS(void)
{
	LinkedListStack* Stack = NULL;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, "abc");
	LLS_Push(Stack, "def");
	LLS_Push(Stack, "efg");
	LLS_Push(Stack, "hij");

	printf("Count: %zu, Top: %s\n\n",
		LLS_GetCount(Stack), LLS_Top(Stack));

	while (!LLS_IsEmpty(Stack))
	{

		printf("Popped: %s, ", LLS_Top(Stack));
		LLS_Pop(Stack);

		if (!LLS_IsEmpty(Stack))
		{
			printf("Current Top: %s\n", LLS_Top(Stack));
		}
		else
		{
			printf("Stack Is Empty.\n");
		}
	}
	LLS_DestroyStack(Stack);
}
void TestCalculator(void)
{
	//1
	/*char InfixExpression[100];
	char PostfixExpression[100];

	double Result = 0.0;

	memset(InfixExpression, 0, sizeof(InfixExpression));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	printf("Enter Infix Expression: ");
	scanf("%s", InfixExpression);*/
	//2	
	char Infix[100] = "1+3.334/(4.28*(110-7729))";
	char Postfix[100];

	double Result = 0.0;

	memset(Postfix, 0, sizeof(Postfix));

	printf("Enter Infix Expression: %s\n", Infix);

	GetPostfix(Infix, Postfix);

	printf("Infix: %s\nPostfix: %s\n",
		Infix,
		Postfix);

	Result = Calculate(Postfix);

	printf("Calculation Result : %f\n", Result);
}

int main(void)
{
	int StackNumber = 2;

	switch (StackNumber)
	{
		case 0:
		{
			TestAS();
			break;
		}
		case 1:
		{
			TestLLS();
			break;
		}
		case 2:
		{
			TestCalculator();
			break;
		}
	}
	return 0;
}