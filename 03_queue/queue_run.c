#include "circular_queue.h"
#include "linked_queue.h"

void cq_test(void)
{
    size_t max_size = 10;
    circular_queue *queue = cq_create(max_size);

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
void lq_test(void)
{
    linked_queue *queue = lq_create();

    lq_enqueue(queue, "abc");
    lq_enqueue(queue, "def");
    lq_enqueue(queue, "efg");
    lq_enqueue(queue, "hij");

    while (lq_is_empty(queue) == false) {
        printf("Dequeue: %s \n", lq_peek(queue));
        lq_dequeue(queue);
    }
    lq_destroy(queue);
}
int main(void)
{
    int QueueNumber = 1;

    switch (QueueNumber) {
    case 0:
        cq_test();
        break;

    case 1:
        lq_test();
        break;
    }
    return 0;
}