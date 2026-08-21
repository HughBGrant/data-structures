#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void h_test(void)
{
    h_priority_queue *pq = h_create();

    h_insert(pq, 30);
    h_insert(pq, 10);
    h_insert(pq, 50);
    h_insert(pq, 20);
    h_insert(pq, 40);

    printf("deleting:\n");

    while (h_size(pq) > 0) {
        h_item item = h_extract(pq);
        printf("%d\n", item.priority);
    }

    h_destroy(pq);
}
int main(void)
{
    int pq_number = 0;

    switch (pq_number) {
    case 0:
        h_test();
        break;
    }
    return 0;
}
