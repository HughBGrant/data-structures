#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int AL_DataType;

typedef struct {
    size_t Capacity;
    size_t Count;
    AL_DataType *Array;
} AL;

AL *AL_CreateList(size_t Capacity);
void AL_AppendTail(AL *List, AL_DataType NewData);
void AL_Insert(AL *List, size_t Location, AL_DataType NewData);
void AL_Remove(AL *List, size_t Location);
void AL_DestroyList(AL *List);

size_t AL_GetSize(AL *List);
#endif