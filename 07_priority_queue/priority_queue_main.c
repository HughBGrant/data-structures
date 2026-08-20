#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

void h_test(void)
{
    h_priority_queue *pq = h_create();

    h_node e1 = {10};
    h_node e2 = {5};
    h_node e3 = {30};

    h_node e4, e5, e6;

    // 삽입
    h_insert(pq, e1);
    h_insert(pq, e2);
    h_insert(pq, e3);

    // 삭제
    e4 = h_remove(pq);
    printf("< %d > ", e4.priority);

    e5 = h_remove(pq);
    printf("< %d > ", e5.priority);

    e6 = h_remove(pq);
    printf("< %d >\n", e6.priority);

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
