#include "heap.h"
#include "max_binary_heap3.h"
#include <stdio.h>
#include <stdlib.h>

void h_test(void)
{
    h_item e1 = {10};
    h_item e2 = {5};
    h_item e3 = {30};

    h_item e4, e5, e6;

    h_priority_queue *queue;

    queue = h_create();

    // 삽입
    h_insert(queue, e1);
    h_insert(queue, e2);
    h_insert(queue, e3);

    // 삭제
    e4 = h_delete(queue);
    printf("< %d > ", e4.data);

    e5 = h_delete(queue);
    printf("< %d > ", e5.data);

    e6 = h_delete(queue);
    printf("< %d >\n", e6.data);

    free(queue);
}
void h1_test(void)
{
    int queue[CAP];
    int count = 0;

    int datas[] = {5, 3, 8, 1, 9, 2};

    // Insert
    for (size_t i = 0; i < 6; i++) {
        push(queue, &count, datas[i]);
    }

    printf("Min: %d\n", queue[0]);

    // Pop
    printf("Popped in order: ");

    while (count > 0) {
        printf("%d ", pop(queue, &count));
    }

    printf("\n");
}
int main(void)
{
    int queue_number = 0;

    switch (queue_number) {
    case 0:
        h_test();
        break;
    case 3:
        h1_test();
        break;
    }
    return 0;
}
