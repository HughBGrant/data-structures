#define _CRT_SECURE_NO_WARNINGS

#include "ArrayStack.h"
#include "LinkedStack.h"
#include "Calculator.h"

void TestAS(void)
{
	ArrayStack *Stack = AS_CreateStack(10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);

	printf("Capacity: %zu, Count: %zu, Top: %d\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

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
void TestLS(void)
{
	LinkedStack *Stack = LS_CreateStack();

	LS_Push(Stack, "abc");
	LS_Push(Stack, "def");
	LS_Push(Stack, "efg");
	LS_Push(Stack, "hij");

	printf("Count: %zu, Top: %s\n\n",
		LS_GetSize(Stack), LS_Top(Stack));

	while (!LS_IsEmpty(Stack))
	{

		printf("Popped: %s, ", LS_Top(Stack));
		LS_Pop(Stack);

		if (!LS_IsEmpty(Stack))
		{
			printf("Current Top: %s\n", LS_Top(Stack));
		}
		else
		{
			printf("Stack Is Empty.\n");
		}
	}
	LS_DestroyStack(Stack);
}
void TestCalculator(void)
{
	//1
	/*char Infix[100];
	char Postfix[100];

	double Result = 0.0;

	memset(Infix, 0, sizeof(Infix));
	memset(Postfix, 0, sizeof(Postfix));

	printf("Enter Infix : ");
	scanf("%s", Infix);*/
	//2	
	char Infix[100] = "1+3.334/(4.28*(110-7729))";
	char Postfix[100];

	double Result = 0.0;

	memset(Postfix, 0, sizeof(Postfix));

	printf("Enter Infix Expression: %s\n", Infix);
	//

	GetPostfix(Infix, Postfix);

	printf("Infix: %s\nPostfix: %s\n", Infix, Postfix);

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
			TestLS();
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