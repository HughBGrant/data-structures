#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

void bh_test(void)
{
    bh_priority_queue *pq = bh_create();

    bh_insert(pq, 30);
    bh_insert(pq, 10);
    bh_insert(pq, 50);
    bh_insert(pq, 20);
    bh_insert(pq, 40);

    printf("deleting:\n");

    while (bh_size(pq) > 0) {
        bh_item item = bh_extract(pq);
        printf("%d\n", item.priority);
    }

    bh_destroy(pq);
}
int main(void)
{
    int pq_number = 0;

    switch (pq_number) {
    case 0:
        bh_test();
        break;
    }
    return 0;
}
