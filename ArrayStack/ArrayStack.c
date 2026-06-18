#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack));

	if (*Stack != NULL)
	{
		(*Stack)->Array = (Node*)malloc(sizeof(Node) * Capacity);
		(*Stack)->Capacity = Capacity;
		(*Stack)->Top = -1;
	}
}

void AS_DestroyStack(ArrayStack* Stack)
{
	free(Stack->Array);

	free(Stack);
}
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Array[Stack->Top].Data = Data;
}
ElementType AS_Pop(ArrayStack* Stack)
{
	if (Stack->Top == -1)
	{
		return;
	}
	ElementType Data = Stack->Array[Stack->Top].Data;
	Stack->Top--;

	return Data;
}
ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Array[Stack->Top].Data;
}
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}
int AS_IsFull(ArrayStack* Stack)
{
	return (Stack->Top + 1 == Stack->Capacity);
}

int main(void)
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);

	printf("Capacity: %d, Size: %d, Top: %d\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	while (AS_GetSize(Stack) >= 1)
	{
		if (AS_IsEmpty(Stack))
			break;

		printf("Popped: %d, ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("Current Top: %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}

	return 0;
}
