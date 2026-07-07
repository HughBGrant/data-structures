#include "circular_deque.h"
#include "linked_deque.h"

void cd_test(void)
{
    circular_deque *deque = cd_create(10);

    int data = 0;

    cd_push_back(deque, 10);
    cd_push_back(deque, 20);
    cd_push_back(deque, 30);
    cd_push_back(deque, 40);

    for (int i = 0; i < 3; i++) {
        printf("Dequeue: %d. ", cd_pop_front(deque));
        printf("Front: %zu, Rear: %zu, Count: %zu\n", deque->front, deque->rear,
               cd_size(deque));
    }
    data = 100;

    while (cd_is_full(deque) == false) {
        cd_push_back(deque, data);
        data++;
    }
    printf("Capacity: %zu, Size: %zu\n", deque->capacity, cd_size(deque));

    while (cd_is_empty(deque) == false) {
        printf("Dequeue: %d. ", cd_pop_front(deque));
        printf("Front: %zu, Rear: %zu\n", deque->front, deque->rear);
    }
    cd_destroy(deque);
}
void ld_test(void)
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
    int deque_number = 1;

    switch (deque_number) {
    case 0:
        cd_test();
        break;

    case 1:
        ld_test();
        break;
    }
    return 0;
}