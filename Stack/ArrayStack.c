#include "ArrayStack.h"

void AS_CreateStack(ArrayStack **Stack, size_t Capacity)
{
	*Stack = malloc(sizeof(ArrayStack));

	if (*Stack != NULL)
	{
		(*Stack)->Array = malloc(sizeof(int) * Capacity);
		if ((*Stack)->Array != NULL)
		{
			(*Stack)->Capacity = Capacity;
			(*Stack)->Count = 0;
		}
	}
}
void AS_DestroyStack(ArrayStack *Stack)
{
	if (Stack == NULL)
	{
		return;
	}
	free(Stack->Array);
	free(Stack);
}
void AS_Push(ArrayStack *Stack, ASDataType Data)
{
	if (AS_IsFull(Stack))
	{
		return;
	}
	Stack->Count++;
	Stack->Array[Stack->Count - 1] = Data;
}
void AS_Pop(ArrayStack *Stack)
{
	if (AS_IsEmpty(Stack))
	{
		return;
	}
	Stack->Count--;
}
ASDataType AS_Top(ArrayStack *Stack)
{
	return Stack->Array[Stack->Count - 1];
}
size_t AS_GetCount(ArrayStack *Stack)
{
	return Stack->Count;
}
bool AS_IsEmpty(ArrayStack *Stack)
{
	return Stack->Count == 0;
}
bool AS_IsFull(ArrayStack *Stack)
{
	return Stack->Count == Stack->Capacity;
}
