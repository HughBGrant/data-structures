#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void h_test(void)
{
    h_priority_queue *pq = h_create();

    h_insert(pq, (h_item){30});
    h_insert(pq, (h_item){10});
    h_insert(pq, (h_item){50});
    h_insert(pq, (h_item){20});
    h_insert(pq, (h_item){40});

    printf("우선순위 큐에서 삭제:\n");

    while (pq->count > 0) {
        h_item item = h_remove(pq);
        printf("%d\n", item.priority);
    }

    free(pq);
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
