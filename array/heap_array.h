#ifndef HEAP_ARRAY_H
#define HEAP_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef int A_DataType;

typedef struct {
    size_t Size;
    A_DataType *Array;
} A;

A *A_CreateArray(size_t Size);
void A_Set(A *Array, size_t Location, A_DataType NewData);
A_DataType *A_Get(A *Array, size_t Location);
void A_DestroyArray(A *Array);

size_t A_GetSize(A *Array);
#endif
