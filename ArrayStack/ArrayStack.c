#include <stdio.h>

#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	*Stack = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}