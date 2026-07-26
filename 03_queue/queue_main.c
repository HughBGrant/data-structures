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

    for (cq_data i = 0; i < 16; i++) {
        lq_enqueue(queue, i);
    }
    printf("Count: %zu, Front: %d\n", lq_size(queue), *lq_peek(queue));

    while (lq_is_empty(queue) == false) {
        printf("Dequeue: %d \n", *lq_peek(queue));
        lq_dequeue(queue);
    }
    lq_destroy(queue);
}
int main(void)
{
    int queue_number = 0;

    switch (queue_number) {
    case 0:
        cq_test();
        break;

    case 1:
        lq_test();
        break;
    }
    return 0;
}