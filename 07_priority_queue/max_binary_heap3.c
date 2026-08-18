#include "max_binary_heap3.h"

static int heap[CAP];
static int heapSize = 0;

void push(int value)
{
    int i = heapSize++;

    heap[i] = value;

    // Sift up
    while (i > 0) {
        int parent = (i - 1) / 2;

        // 부모가 더 크거나 같으면 조건 만족
        if (heap[parent] >= heap[i])
            break;

        // swap
        int tmp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = tmp;

        i = parent;
    }
}

int pop(void)
{
    int top = heap[0];

    heap[0] = heap[--heapSize];

    // Sift down
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        // 왼쪽 자식이 더 크면
        if (left < heapSize &&
            heap[left] > heap[largest]) {
            largest = left;
        }

        // 오른쪽 자식이 더 크면
        if (right < heapSize &&
            heap[right] > heap[largest]) {
            largest = right;
        }

        // 현재 노드가 가장 크면 종료
        if (largest == i)
            break;

        // swap
        int tmp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = tmp;

        i = largest;
    }

    return top;
}

int peek(void)
{
    return heap[0];
}

int isEmpty(void)
{
    return heapSize == 0;
}