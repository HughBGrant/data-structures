#include "circular_deque.h"
#include "linked_deque.h"

void cd_test(void)
{
    circular_deque *deque = cd_create(10);

    int data = 0;

    cd_push_front(deque, 10);
    cd_push_front(deque, 20);
    cd_push_front(deque, 30);
    cd_push_front(deque, 40);

    for (int i = 0; i < 3; i++) {
        printf("popped front: %d\n", cd_front(deque));
        cd_pop_front(deque);
        printf("Count: %zu\n", cd_size(deque));
    }

    data = 100;
    while (cd_is_full(deque) == false) {
        cd_push_back(deque, data);
        data++;
    }

    while (cd_is_empty(deque) == false) {
        printf("popped back: %d\n", cd_back(deque));
        cd_pop_back(deque);
        printf("count: %zu\n", cd_size(deque));
    }
    cd_destroy(deque);
}
void ld_test(void)
{
    linked_deque *deque = ld_create();

    ld_push_back(deque, "abc");
    ld_push_back(deque, "def");
    ld_push_back(deque, "efg");
    ld_push_back(deque, "hij");

    printf("deque Size : %zu\n", deque->count);

    while (ld_is_empty(deque) == 0) {
        printf("Dequeue: %s \n", ld_front(deque));
        ld_pop_front(deque);
    }
    ld_destroy(deque);
}
int main(void)
{
    int deque_number = 0;

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