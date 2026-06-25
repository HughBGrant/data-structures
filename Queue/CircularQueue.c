#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue **Queue, size_t Capacity)
{
	*Queue = malloc(sizeof(CircularQueue));

	if (*Queue == NULL)
	{
		return;
	}
	(*Queue)->Array = malloc(sizeof(CQ_DataType) * (Capacity + 1));

	if ((*Queue)->Array == NULL)
	{
		free(*Queue);
		*Queue = NULL;
		return;
	}
	(*Queue)->Size = Capacity + 1;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}
void CQ_DestroyQueue(CircularQueue* Queue)
{
	free(Queue->Array);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, CQ_DataType Data)
{
	Queue->Array[Queue->Rear] = Data;
	Queue->Rear = (Queue->Rear + 1) % (Queue->Size);
}
CQ_DataType CQ_Dequeue(CircularQueue* Queue)
{
	CQ_DataType Data = Queue->Array[Queue->Front];
	Queue->Front = (Queue->Front + 1) % (Queue->Size);

	return Data;
}
bool CQ_IsEmpty(CircularQueue* Queue)
{
	return Queue->Front == Queue->Rear;
}
bool CQ_IsFull(CircularQueue* Queue)
{
	return (Queue->Rear + 1) % (Queue->Size) == Queue->Front;
}
size_t CQ_GetSize(CircularQueue* Queue)
{
	return (Queue->Size + Queue->Rear - Queue->Front) % (Queue->Size);
}