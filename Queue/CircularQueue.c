#include "CircularQueue.h"

CircularQueue *CQ_CreateQueue(size_t Size)
{
	CircularQueue *Queue = malloc(sizeof(CircularQueue));

	if (Queue == NULL)
	{
		return NULL;
	}
	Queue->Capacity = Size + 1;
	Queue->Array = malloc(sizeof(CQ_DataType) * Queue->Capacity);

	if (Queue->Array == NULL)
	{
		free(Queue);
		return NULL;
	}
	Queue->Front = 0;
	Queue->Rear = 0;

	return Queue;
}
void CQ_DestroyQueue(CircularQueue* Queue)
{
	if (Queue == NULL)
	{
		return;
	}
	free(Queue->Array);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, CQ_DataType Data)
{
	if (CQ_IsFull(Queue))
	{
		return;
	}
	Queue->Array[Queue->Rear] = Data;
	Queue->Rear = (Queue->Rear + 1) % (Queue->Capacity);
}
CQ_DataType CQ_Dequeue(CircularQueue* Queue)
{
	if (CQ_IsEmpty(Queue))
	{
		return NULL;
	}
	CQ_DataType Data = Queue->Array[Queue->Front];
	Queue->Front = (Queue->Front + 1) % (Queue->Capacity);

	return Data;
}
bool CQ_IsEmpty(CircularQueue* Queue)
{
	return Queue->Front == Queue->Rear;
}
bool CQ_IsFull(CircularQueue* Queue)
{
	return (Queue->Rear + 1) % (Queue->Capacity) == Queue->Front;
}
size_t CQ_GetSize(CircularQueue* Queue)
{
	return (Queue->Capacity + Queue->Rear - Queue->Front) % (Queue->Capacity);
}