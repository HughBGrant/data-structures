#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int AL_DataType;

typedef struct {
    size_t Capacity;
    size_t Count;
    AL_DataType *Array;
} ArrayList;

ArrayList *AL_CreateList(void);
void AL_AppendTail(ArrayList *List, AL_DataType NewData);
void AL_AppendHead(ArrayList *List, AL_DataType NewData);
void AL_Insert(ArrayList *List, size_t Location, AL_DataType NewData);
void AL_RemoveNode(ArrayList *List, size_t Location);
void AL_DestroyList(ArrayList *List);

size_t AL_GetSize(ArrayList *List);
#endif