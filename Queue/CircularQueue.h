#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_QUEUE_H
#define	CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int CQ_DataType;
typedef struct
{
	CQ_DataType Data;
} CQ_Node;

typedef struct
{
	size_t Size;
	size_t Front;
	size_t Rear;
	CQ_Node *Array;
} CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, size_t Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, CQ_DataType Data);
CQ_DataType CQ_Dequeue(CircularQueue* Queue);
bool CQ_IsEmpty(CircularQueue* Queue);
bool CQ_IsFull(CircularQueue* Queue);
size_t CQ_GetSize(CircularQueue* Queue);

#endif