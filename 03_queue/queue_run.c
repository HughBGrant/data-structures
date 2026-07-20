#include "circular_queue.h"
#include "linked_queue.h"

void cq_test(void)
{
    circular_queue *queue = cq_create(2);

    for (cq_data i = 0; i < 16; i++) {
        cq_enqueue(queue, i);
    }
    printf("Count: %zu, Front: %d\n", cq_size(queue), *cq_peek(queue));

    while (cq_is_empty(queue) == false) {
        printf("Dequeue: %d\n", *cq_peek(queue));
        cq_dequeue(queue);
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
        printf("Dequeue: %s \n", *lq_peek(queue));
        lq_dequeue(queue);
    }
    lq_destroy(queue);
}
int main(void)
{
    int QueueNumber = 0;

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