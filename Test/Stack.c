#define _CRT_SECURE_NO_WARNINGS
//#include "ArrayStack.h"
#include "LinkedListStack.h"
#include "Calculator.h"
void TestLLS(void)
{
	LinkedListStack* Stack = NULL;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, "abc");
	LLS_Push(Stack, "def");
	LLS_Push(Stack, "efg");
	LLS_Push(Stack, "hij");

	printf("Size: %d, Top: %s\n\n",
		LLS_GetSize(Stack), LLS_Top(Stack));

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

	return 0;
}
void TestCalculator(void)
{
	char InfixExpression[100];
	char PostfixExpression[100];

	double Result = 0.0;

	memset(InfixExpression, 0, sizeof(InfixExpression));
	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	printf("Enter Infix Expression: ");
	scanf("%s", InfixExpression);

	GetPostfix(InfixExpression, PostfixExpression);

	printf("Infix: %s\nPostfix: %s\n",
		InfixExpression,
		PostfixExpression);

	Result = Calculate(PostfixExpression);

	printf("Calculation Result : %f\n", Result);

	return 0;

}
int main(void)
{
	int StackNumber = 2;

	switch (StackNumber)
	{
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
}