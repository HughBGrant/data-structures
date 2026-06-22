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
			(*Stack)->Count = -1;
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
	Stack->Count++;
	Stack->Array[Stack->Count] = Data;
}
ElementType AS_Pop(ArrayStack* Stack)
{
	if (Stack->Count == -1)
	{
		return;
	}
	ElementType Data = Stack->Array[Stack->Count];
	Stack->Count--;

	return Data;
}
ElementType AS_Top(ArrayStack* Stack)
{
	if (Stack->Count == -1)
	{
		return;
	}
	return Stack->Array[Stack->Count];
}
int AS_GetCount(ArrayStack* Stack)
{
	return Stack->Count + 1;
}
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Count == -1);
}
int AS_IsFull(ArrayStack* Stack)
{
	return (Stack->Count + 1 == Stack->Capacity);
}
