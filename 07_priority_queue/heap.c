#include <stdio.h>

#define CAP 64

int heap[CAP];
int heapSize = 0;

void push(int value)
{
    // Sift up until the parent is no larger
    int i = heapSize++;
    heap[i] = value;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i])
            break;
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
    // Sift down: swap with the smaller child
    int i = 0;
    while (1) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < heapSize && heap[l] < heap[smallest])
            smallest = l;
        if (r < heapSize && heap[r] < heap[smallest])
            smallest = r;
        if (smallest == i)
            break;
        int tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

int main(void)
{
    int values[] = {5, 3, 8, 1, 9, 2};
    for (int i = 0; i < 6; i++)
        push(values[i]);
    printf("Min: %d\n", heap[0]);
    printf("Popped in order: ");
    while (heapSize > 0)
        printf("%d ", pop());
    printf("\n");
    return 0;
}