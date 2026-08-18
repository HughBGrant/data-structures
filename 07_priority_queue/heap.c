#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

// 생성 함수
HeapType *create(void)
{
    HeapType *heap = malloc(sizeof(HeapType));
    if (heap == NULL) {
        return NULL;
    }
    heap->count = 0;

    return heap;
}

// 최대 힙에 원소 삽입
void insert_max_heap(HeapType *h, item item)
{
    int i;

    i = ++(h->count);

    // 부모 노드와 비교하면서 위로 이동
    while ((i != 1) &&
           (item.key > h->items[i / 2].key)) {

        h->items[i] = h->items[i / 2];
        i /= 2;
    }

    h->items[i] = item;
}

// 최대 힙에서 최댓값 삭제
item delete_max_heap(HeapType *h)
{
    int parent, child;
    item item, temp;

    // 루트 = 최댓값
    item = h->items[1];

    // 마지막 원소를 임시 저장
    temp = h->items[(h->count)--];

    parent = 1;
    child = 2;

    while (child <= h->count) {

        // 두 자식 중 더 큰 자식 선택
        if ((child < h->count) &&
            (h->items[child].key < h->items[child + 1].key)) {
            child++;
        }

        // temp가 자식보다 크거나 같으면 종료
        if (temp.key >= h->items[child].key)
            break;

        // 더 큰 자식을 부모 자리로 이동
        h->items[parent] = h->items[child];

        parent = child;
        child *= 2;
    }

    h->items[parent] = temp;

    return item;
}