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
        printf("Dequeue: %d\n", cq_peek(queue));
        cq_dequeue(queue);
        printf("Count: %zu\n", cq_size(queue));
    }
    data = 100;

    while (cq_is_full(queue) == false) {
        cq_enqueue(queue, data);
        data++;
    }

    while (cq_is_empty(queue) == false) {
        printf("Dequeue: %d\n", cq_peek(queue));
        cq_dequeue(queue);
        printf("Count: %zu\n", cq_size(queue));
    }
    cq_destroy(queue);
}
void TestLQ(void)
{
    linked_queue *Queue = lq_create();

    lq_enqueue(Queue, "abc");
    lq_enqueue(Queue, "def");
    lq_enqueue(Queue, "efg");
    lq_enqueue(Queue, "hij");

    printf("Queue Size : %zu\n", Queue->count);

    while (lq_is_empty(Queue) == 0) {
        printf("Dequeue: %s \n", lq_peek(Queue));

        lq_dequeue(Queue);
    }
    lq_destroy(Queue);
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