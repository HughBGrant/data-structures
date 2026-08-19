#include "heap.h"
#include "max_binary_heap3.h"
#include <stdio.h>
#include <stdlib.h>

void h_test(void)
{
    h_node e1 = {10};
    h_node e2 = {5};
    h_node e3 = {30};

    h_node e4, e5, e6;

    h_priority_queue *pq;

    pq = h_create();

    // 삽입
    h_insert(pq, e1);
    h_insert(pq, e2);
    h_insert(pq, e3);

    // 삭제
    e4 = h_delete(pq);
    printf("< %d > ", e4.value);

    e5 = h_delete(pq);
    printf("< %d > ", e5.value);

    e6 = h_delete(pq);
    printf("< %d >\n", e6.value);

    free(pq);
}
void h1_test(void)
{
    int pq[CAP];
    int count = 0;

    int datas[] = {5, 3, 8, 1, 9, 2};

    // Insert
    for (size_t i = 0; i < 6; i++) {
        push(pq, &count, datas[i]);
    }

    printf("Min: %d\n", pq[0]);

    // Pop
    printf("Popped in order: ");

    while (count > 0) {
        printf("%d ", pop(pq, &count));
    }

    printf("\n");
}
int main(void)
{
    int pq_number = 0;

    switch (pq_number) {
    case 0:
        h_test();
        break;
    case 3:
        h1_test();
        break;
    }
    return 0;
}
