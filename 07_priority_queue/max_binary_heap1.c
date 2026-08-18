#include "max_binary_heap1.h"
#include <stdio.h>
#include <stdlib.h>

// 생성 함수
HeapType *create(void)
{
    return (HeapType *)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType *h)
{
    h->heap_size = 0;
}

// 최대 힙에 원소 삽입
void insert_max_heap(HeapType *h, element item)
{
    int i;

    i = ++(h->heap_size);

    // 부모 노드와 비교하면서 위로 이동
    while ((i != 1) &&
           (item.key > h->heap[i / 2].key)) {

        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

// 최대 힙에서 최댓값 삭제
element delete_max_heap(HeapType *h)
{
    int parent, child;
    element item, temp;

    // 루트 = 최댓값
    item = h->heap[1];

    // 마지막 원소를 임시 저장
    temp = h->heap[(h->heap_size)--];

    parent = 1;
    child = 2;

    while (child <= h->heap_size) {

        // 두 자식 중 더 큰 자식 선택
        if ((child < h->heap_size) &&
            (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        }

        // temp가 자식보다 크거나 같으면 종료
        if (temp.key >= h->heap[child].key)
            break;

        // 더 큰 자식을 부모 자리로 이동
        h->heap[parent] = h->heap[child];

        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return item;
}