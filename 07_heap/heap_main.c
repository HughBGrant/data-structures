#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

void b_test(void)
{
    BPriorityQueue *pq = b_create();

    b_insert(pq, 30);
    b_insert(pq, 10);
    b_insert(pq, 50);
    b_insert(pq, 20);
    b_insert(pq, 40);

    printf("deleting:\n");

    while (b_size(pq) > 0) {
        BItem item = b_extract(pq);
        printf("%d\n", item.priority);
    }

    b_destroy(pq);
}
int main(void)
{
    int pq_number = 0;

    switch (pq_number) {
    case 0:
        b_test();
        break;
    }
    return 0;
}
