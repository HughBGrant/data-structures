#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int CQ_DataType;

typedef struct {
    size_t Capacity;
    size_t Front;
    size_t Rear;
    CQ_DataType *Array;
    size_t Count;
} CQ;

CQ *CQ_CreateQueue(size_t Capacity);
void CQ_Enqueue(CQ *Queue, CQ_DataType Data);
CQ_DataType CQ_Dequeue(CQ *Queue);

void CQ_DestroyQueue(CQ *Queue);

bool CQ_IsEmpty(CQ *Queue);
bool CQ_IsFull(CQ *Queue);
size_t CQ_GetSize(CQ *Queue);

#endif