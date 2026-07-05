#include "heap_array.h"

A *A_CreateArray(size_t Size)
{
    A *Array = malloc(sizeof(A));
    if (Array == NULL) {
        return NULL;
    }

    Array->Array = malloc(sizeof(A_DataType) * Size);
    if (Array->Array == NULL) {
        free(Array);
        return NULL;
    }

    Array->Size = Size;

    return Array;
}
void A_Set(A *Array, size_t Location, A_DataType NewData)
{
    if (Array == NULL || Location >= Array->Size) {
        return;
    }

    Array->Array[Location] = NewData;
}
A_DataType *A_Get(A *Array, size_t Location)
{
    if (Array == NULL || Location >= Array->Size) {
        return NULL;
    }

    return &Array->Array[Location];
}
void A_DestroyArray(A *Array)
{
    if (Array == NULL) {
        return;
    }

    free(Array->Array);
    free(Array);
}
size_t A_GetSize(A *Array)
{
    if (Array == NULL) {
        return 0;
    }

    return Array->Size;
}
