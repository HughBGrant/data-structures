#include "CircularQueue.h"

int main(void)
{
    CircularQueue *Queue;
	int Data = 0;

	CQ_CreateQueue(&Queue, 10);
	CQ_Enqueue(Queue, 10);
    CQ_Enqueue(Queue, 20);
    CQ_Enqueue(Queue, 30);
    CQ_Enqueue(Queue, 40);

    for (int i = 0; i < 3; i++)
    {
        printf("Dequeue: %d. ", CQ_Dequeue(Queue));
        printf("Front: %zu, Rear: %zu\n", Queue->Front, Queue->Rear);
    }
    Data = 100;

    while (CQ_IsFull(Queue) == false)
    {
        CQ_Enqueue(Queue, Data);
        Data++;
    }
    printf("Capacity: %zu, Size: %zu\n",
        Queue->Capacity - 1, CQ_GetSize(Queue));

    while (CQ_IsEmpty(Queue) == false)
    {
        printf("Dequeue: %d. ", CQ_Dequeue(Queue));
        printf("Front: %zu, Rear: %zu\n", Queue->Front, Queue->Rear);
    }
    CQ_DestroyQueue(Queue);

    return 0;
}