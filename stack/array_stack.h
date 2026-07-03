#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int AS_DataType;

typedef struct {
    size_t Capacity;
    size_t Count;
    AS_DataType *Array;
} AS;

AS *AS_CreateStack(size_t Capacity);
void AS_Push(AS *Stack, AS_DataType Data);
void AS_Pop(AS *Stack);
AS_DataType AS_Top(AS *Stack);
void AS_DestroyStack(AS *Stack);

bool AS_IsEmpty(AS *Stack);
bool AS_IsFull(AS *Stack);
size_t AS_GetSize(AS *Stack);

#endif
