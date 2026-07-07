#include "circular_queue.h"
#include "linked_queue.h"

void cq_test(void)
{
    size_t capacity = 10;
    circular_queue *queue = cq_create(capacity);

    int data = 0;

    cq_enqueue(queue, 10);
    cq_enqueue(queue, 20);
    cq_enqueue(queue, 30);
    cq_enqueue(queue, 40);

    for (size_t i = 0; i < 3; i++) {
        printf("Dequeue: %d, ", cq_front(queue));
        cq_dequeue(queue);
        printf("Front: %d, Count: %zu\n",
               cq_front(queue), cq_size(queue));
    }
    data = 100;

    while (cq_is_full(queue) == false) {
        cq_enqueue(queue, data);
        data++;
    }

    while (cq_is_empty(queue) == false) {
        printf("Dequeue: %d. ", cq_front(queue));
        cq_dequeue(queue);
        printf("Front: %d, Count: %zu\n",
               cq_front(queue), cq_size(queue));
    }
    cq_destroy(queue);
}
void TestLQ(void)
{
    LQ *Queue = LQ_CreateQueue();

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
int main(void)
{
    int QueueNumber = 0;

    switch (QueueNumber) {
    case 0:
        cq_test();
        break;

    case 1:
        TestLQ();
        break;
    }
    return 0;
}