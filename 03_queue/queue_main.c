#include "circular_queue.h"
#include "linked_queue.h"
#include <stdio.h>

void cq_test(void)
{
    CQueue *queue = cq_create();

    for (int i = 0; i < 16; i++) {
        cq_enqueue(queue, i);
    }
    printf("size: %zu, Front: %d\n", cq_size(queue), cq_peek(queue));

    while (cq_is_empty(queue) == false) {
        printf("Dequeue: %d\n", cq_dequeue(queue));
    }
    cq_destroy(queue);
}
void lq_test(void)
{
    LQueue *queue = lq_create();

    for (int i = 0; i < 16; i++) {
        lq_enqueue(queue, i);
    }
    printf("size: %zu, Front: %d\n", lq_size(queue), lq_peek(queue));

    while (lq_is_empty(queue) == false) {
        printf("Dequeue: %d \n", lq_dequeue(queue));
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