#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack));

	if (*Stack != NULL)
	{
		(*Stack)->Array = malloc(sizeof(int) * Capacity);
		if ((*Stack)->Array != NULL)
		{
			(*Stack)->Capacity = Capacity;
			(*Stack)->Top = -1;
		}
	}
}
void AS_DestroyStack(ArrayStack* Stack)
{
	if (Stack == NULL)
	{
		return;
	}
	free(Stack->Array);
	free(Stack);
	return;
}
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Array[Stack->Top] = Data;
}
ElementType AS_Pop(ArrayStack* Stack)
{
	if (Stack->Top == -1)
	{
		return;
	}
	ElementType Data = Stack->Array[Stack->Top];
	Stack->Top--;

	return Data;
}
ElementType AS_Top(ArrayStack* Stack)
{
	if (Stack->Top == -1)
	{
		return;
	}
	return Stack->Array[Stack->Top];
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
