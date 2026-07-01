#include "circular_queue.h"

CircularQueue* CQ_CreateQueue(size_t Size) {
	CircularQueue* Queue = malloc(sizeof(CircularQueue));
	if (Queue == NULL) {
		return NULL;
	}

	Queue->Array = malloc(sizeof(CQ_DataType) * Size);
	if (Queue->Array == NULL) {
		free(Queue);
		return NULL;
	}

	Queue->Capacity = Size;
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count = 0;

	return Queue;
}
void CQ_DestroyQueue(CircularQueue* Queue) {
	if (Queue == NULL) {
		return;
	}
	free(Queue->Array);
	free(Queue);
}
void CQ_Enqueue(CircularQueue* Queue, CQ_DataType Data) {
	if (CQ_IsFull(Queue)) {
		return;
	}
	Queue->Array[Queue->Rear] = Data;
	Queue->Rear = (Queue->Rear + 1) % (Queue->Capacity);
	Queue->Count++;
}
CQ_DataType CQ_Dequeue(CircularQueue* Queue) {
	CQ_DataType Data = Queue->Array[Queue->Front];
	Queue->Front = (Queue->Front + 1) % (Queue->Capacity);
	Queue->Count--;

	return Data;
}
bool CQ_IsEmpty(CircularQueue* Queue) {
	return Queue->Count == 0;
}
bool CQ_IsFull(CircularQueue* Queue) {
	return Queue->Count == Queue->Capacity;
}
size_t CQ_GetSize(CircularQueue* Queue) {
	if (Queue == NULL) {
		return 0;
	}
	return Queue->Count;
}
