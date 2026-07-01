#ifndef ARRAY_STACK_H
#define	ARRAY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int AS_DataType;

typedef struct
{
	size_t Capacity;
	size_t Count;
	AS_DataType *Array;
} ArrayStack;

ArrayStack *AS_CreateStack(size_t Capacity);
void AS_Push(ArrayStack *Stack, AS_DataType Data);
void AS_Pop(ArrayStack *Stack);
AS_DataType AS_Top(ArrayStack *Stack);
void AS_DestroyStack(ArrayStack *Stack);

bool AS_IsEmpty(ArrayStack *Stack);
bool AS_IsFull(ArrayStack *Stack);
size_t AS_GetSize(ArrayStack *Stack);

#endif
