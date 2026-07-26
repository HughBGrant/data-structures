#include "circular_deque.h"
#include "linked_deque.h"

void cd_test(void)
{
    circular_deque *deque = cd_create(2);

    for (cd_data i = 0; i < 8; i++) {
        cd_push_front(deque, i);
    }
    printf("Count: %zu, Front: %d\n",
           cd_size(deque), *cd_front(deque));

    for (cd_data i = 8; i < 16; i++) {
        cd_push_back(deque, i);
    }
    printf("Count: %zu, back: %d\n",
           cd_size(deque), *cd_back(deque));
    for (size_t i = 0; i < 8; i++) {
        printf("popped front: %d\n", *cd_front(deque));
        cd_pop_front(deque);
    }
    printf("Count: %zu, back: %d\n",
           cd_size(deque), *cd_back(deque));
    for (size_t i = 0; i < 8; i++) {
        printf("popped back: %d\n", *cd_back(deque));
        cd_pop_back(deque);
    }
    cd_destroy(deque);
}
void ld_test(void)
{
    linked_deque *deque = ld_create();

    for (ld_data i = 0; i < 8; i++) {
        ld_push_front(deque, i);
    }
    printf("Count: %zu, Front: %d\n",
           ld_size(deque), *ld_front(deque));

    for (ld_data i = 8; i < 16; i++) {
        ld_push_back(deque, i);
    }
    printf("Count: %zu, back: %d\n",
           ld_size(deque), *ld_back(deque));
    for (size_t i = 0; i < 8; i++) {
        printf("popped front: %d\n", *ld_front(deque));
        ld_pop_front(deque);
    }
    printf("Count: %zu, back: %d\n",
           ld_size(deque), *ld_back(deque));
    for (size_t i = 0; i < 8; i++) {
        printf("popped back: %d\n", *ld_back(deque));
        ld_pop_back(deque);
    }
    ld_destroy(deque);
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