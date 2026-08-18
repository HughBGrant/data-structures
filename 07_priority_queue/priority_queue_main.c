#include "heap.h"
#include "max_binary_heap3.h"
#include <stdio.h>
#include <stdlib.h>

void h_test(void)
{
    item e1 = {10};
    item e2 = {5};
    item e3 = {30};

    item e4, e5, e6;

    HeapType *heap;

    heap = create();

    // 삽입
    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    // 삭제
    e4 = delete_max_heap(heap);
    printf("< %d > ", e4.key);

    e5 = delete_max_heap(heap);
    printf("< %d > ", e5.key);

    e6 = delete_max_heap(heap);
    printf("< %d >\n", e6.key);

    free(heap);
}
void h1_test(void)
{
    int heap[CAP];
    int heapSize = 0;

    int values[] = {5, 3, 8, 1, 9, 2};

    // Insert
    for (int i = 0; i < 6; i++) {
        push(heap, &heapSize, values[i]);
    }

    printf("Min: %d\n", heap[0]);

    // Pop
    printf("Popped in order: ");

    while (heapSize > 0) {
        printf("%d ", pop(heap, &heapSize));
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
