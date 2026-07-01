#include "circular_queue.h"
#include "linked_queue.h"

void TestCQ(void) {
	CircularQueue* Queue = CQ_CreateQueue(10);

	int Data = 0;

	CQ_Enqueue(Queue, 10);
	CQ_Enqueue(Queue, 20);
	CQ_Enqueue(Queue, 30);
	CQ_Enqueue(Queue, 40);

	for (int i = 0; i < 3; i++) {
		printf("Dequeue: %d. ", CQ_Dequeue(Queue));
		printf("Front: %zu, Rear: %zu, Count: %zu\n",
			Queue->Front, Queue->Rear, CQ_GetSize(Queue));
	}
	Data = 100;

	while (CQ_IsFull(Queue) == false) {
		CQ_Enqueue(Queue, Data);
		Data++;
	}
	printf("Capacity: %zu, Size: %zu\n",
		Queue->Capacity, CQ_GetSize(Queue));

	while (CQ_IsEmpty(Queue) == false) {
		printf("Dequeue: %d. ", CQ_Dequeue(Queue));
		printf("Front: %zu, Rear: %zu\n", Queue->Front, Queue->Rear);
	}
	CQ_DestroyQueue(Queue);
}
void TestLQ(void) {
	LinkedQueue* Queue = LQ_CreateQueue();

	LQ_Enqueue(Queue, "abc");
	LQ_Enqueue(Queue, "def");
	LQ_Enqueue(Queue, "efg");
	LQ_Enqueue(Queue, "hij");

	printf("Queue Size : %zu\n", Queue->Count);

	while (LQ_IsEmpty(Queue) == 0) {
		printf("Dequeue: %s \n", LQ_Peek(Queue));

		LQ_Dequeue(Queue);
	}
	LQ_DestroyQueue(Queue);
}
int main(void) {
	int QueueNumber = 1;

	switch (QueueNumber) {
	case 0:
		TestCQ();
		break;

	case 1:
		TestLQ();
		break;
	}
	return 0;
}
