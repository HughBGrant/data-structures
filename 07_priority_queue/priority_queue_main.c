#include "max_binary_heap.h"
#include "max_binary_heap1.h"
#include "max_binary_heap3.h"

void max_bh_test(void)
{
    int heap[] = {
        45, 35, 15, 30, 10,
        12, 6, 5, 20, 50};

    // 50을 Heap에 삽입
    Insert(heap, 9);

    Print(heap, 10);
}
void max_bh1_test(void)
{
    element e1 = {10};
    element e2 = {5};
    element e3 = {30};

    element e4, e5, e6;

    HeapType *heap;

    // 힙 생성
    heap = create();

    // 힙 초기화
    init(heap);

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
void max_bh3_test(void)
{
    int values[] = {5, 3, 8, 1, 9, 2};

    for (int i = 0; i < 6; i++) {
        push(values[i]);
    }

    printf("Max: %d\n", peek());

    printf("Popped in order: ");

    while (!isEmpty()) {
        printf("%d ", pop());
    }

    printf("\n");
}
int main(void)
{
    int pq_number = 0;

    switch (pq_number) {
    case 0:
        max_bh_test();
        break;
    case 1:
        max_bh1_test();
        break;
    case 3:
        max_bh3_test();
        break;
    }
    return 0;
}
