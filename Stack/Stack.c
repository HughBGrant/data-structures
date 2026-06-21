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

	printf("Capacity: %d, Size: %d, Top: %d\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	while (!AS_IsEmpty(Stack))
	{
		printf("Popped: %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("Current Top: %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}
	AS_DestroyStack(Stack);

	return 0;
}
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
	int StackNumber = 1;

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
}