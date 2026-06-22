#ifndef ARRAY_STACK_H
#define	ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ASDataType;

typedef struct tagArrayStack
{
	size_t Capacity;
	int Count;
	ASDataType* Array;
} ArrayStack;

void AS_CreateStack(ArrayStack** Stack, size_t Capacity);
void AS_DestroyStack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, ASDataType Data);
void AS_Pop(ArrayStack* Stack);
ASDataType AS_Top(ArrayStack* Stack);
size_t AS_GetCount(ArrayStack* Stack);
bool AS_IsEmpty(ArrayStack* Stack);
bool AS_IsFull(ArrayStack* Stack);
#endif // !ARRAY_STACK_H
