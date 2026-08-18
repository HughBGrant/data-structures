#include "heap.h"

void push(int heap[], int *heapSize, int value)
{
    int i = (*heapSize)++;
    heap[i] = value;

    // Sift up
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i]) {
            break;
        }

        int tmp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = tmp;

        i = parent;
    }
}

int pop(int heap[], int *heapSize)
{
    int top = heap[0];

    heap[0] = heap[--(*heapSize)];

    // Sift down
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *heapSize && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < *heapSize && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        int tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;

        i = smallest;
    }

    return top;
}