#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

// 생성 함수
h_priority_queue *h_create(void)
{
    h_priority_queue *queue = malloc(sizeof(h_priority_queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->count = 0;

    return queue;
}

// 최대 힙에 원소 삽입
void h_insert(h_priority_queue *queue, h_item data)
{
    int i;

    i = ++(queue->count);

    // 부모 노드와 비교하면서 위로 이동
    while ((i != 1) &&
           (data.value > queue->data[i / 2].value)) {

        queue->data[i] = queue->data[i / 2];
        i /= 2;
    }

    queue->data[i] = data;
}

// 최대 힙에서 최댓값 삭제
h_item h_remove(h_priority_queue *queue)
{
    int parent, child;
    h_item item, temp;

    // 루트 = 최댓값
    item = queue->data[1];

    // 마지막 원소를 임시 저장
    temp = queue->data[(queue->count)--];

    parent = 1;
    child = 2;

    while (child <= queue->count) {

        // 두 자식 중 더 큰 자식 선택
        if ((child < queue->count) &&
            (queue->data[child].value < queue->data[child + 1].value)) {
            child++;
        }

        // temp가 자식보다 크거나 같으면 종료
        if (temp.value >= queue->data[child].value)
            break;

        // 더 큰 자식을 부모 자리로 이동
        queue->data[parent] = queue->data[child];

        parent = child;
        child *= 2;
    }

    queue->data[parent] = temp;

    return item;
}