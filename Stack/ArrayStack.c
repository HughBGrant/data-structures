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
			(*Stack)->Size = -1;
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
	Stack->Size++;
	Stack->Array[Stack->Size] = Data;
}
ElementType AS_Pop(ArrayStack* Stack)
{
	if (Stack->Size == -1)
	{
		return;
	}
	ElementType Data = Stack->Array[Stack->Size];
	Stack->Size--;

	return Data;
}
ElementType AS_Top(ArrayStack* Stack)
{
	if (Stack->Size == -1)
	{
		return;
	}
	return Stack->Array[Stack->Size];
}
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Size + 1;
}
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Size == -1);
}
int AS_IsFull(ArrayStack* Stack)
{
	return (Stack->Size + 1 == Stack->Capacity);
}
