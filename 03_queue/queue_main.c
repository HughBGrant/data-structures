#include "circular_queue.h"
#include "linked_queue.h"
#include <stdio.h>

void c_test(void)
{
    CQueue *queue = c_create();

    for (int i = 0; i < 16; i++) {
        c_enqueue(queue, i);
    }
    printf("size: %zu, Front: %d\n", c_size(queue), c_peek(queue));

    while (c_is_empty(queue) == false) {
        printf("Dequeue: %d\n", c_dequeue(queue));
    }
    c_destroy(queue);
}
void l_test(void)
{
    LQueue *queue = l_create();

    for (int i = 0; i < 16; i++) {
        l_enqueue(queue, i);
    }
    printf("size: %zu, Front: %d\n", l_size(queue), l_peek(queue));

    while (l_is_empty(queue) == false) {
        printf("Dequeue: %d \n", l_dequeue(queue));
    }
    l_destroy(queue);
}
int main(void)
{
    int queue_number = 0;

    switch (queue_number) {
    case 0:
        c_test();
        break;

    case 1:
        l_test();
        break;
    }
    return 0;
}