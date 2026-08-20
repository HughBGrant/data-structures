#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

// 생성 함수
h_priority_queue *h_create(void)
{
    h_priority_queue *pq = malloc(sizeof(h_priority_queue));
    if (pq == NULL) {
        return NULL;
    }
    pq->count = 0;

    return pq;
}

// 최대 힙에 원소 삽입
void h_insert(h_priority_queue *pq, h_item data)
{
    int i;

    i = ++(pq->count);

    // 부모 노드와 비교하면서 위로 이동
    while ((i != 1) &&
           (data.value > pq->data[i / 2].value)) {

        pq->data[i] = pq->data[i / 2];
        i /= 2;
    }

    pq->data[i] = data;
}

// 최대 힙에서 최댓값 삭제
h_item h_remove(h_priority_queue *pq)
{
    int parent, child;
    h_item item, temp;

    // 루트 = 최댓값
    item = pq->data[1];

    // 마지막 원소를 임시 저장
    temp = pq->data[(pq->count)--];

    parent = 1;
    child = 2;

    while (child <= pq->count) {

        // 두 자식 중 더 큰 자식 선택
        if ((child < pq->count) &&
            (pq->data[child].value < pq->data[child + 1].value)) {
            child++;
        }

        // temp가 자식보다 크거나 같으면 종료
        if (temp.value >= pq->data[child].value)
            break;

        // 더 큰 자식을 부모 자리로 이동
        pq->data[parent] = pq->data[child];

        parent = child;
        child *= 2;
    }

    pq->data[parent] = temp;

    return item;
}
int Parent(int i)
{
    if (i == 0)
        return -1;

    return (i - 1) / 2;
}

/* 왼쪽 자식의 인덱스 */
int LeftChild(h_priority_queue *pq, int i)
{
    int child = 2 * i + 1;

    if (child >= pq->count)
        return -1;

    return child;
}

/* 오른쪽 자식의 인덱스 */
int RightChild(h_priority_queue *pq, int i)
{
    int child = 2 * i + 2;

    if (child >= pq->count)
        return -1;

    return child;
}