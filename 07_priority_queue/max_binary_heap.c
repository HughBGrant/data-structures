#include "max_binary_heap.h"
#include <stdio.h>

void Insert(int heap[], int n)
{
    int i = n;
    int temp = heap[n];

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (temp <= heap[parent])
            break;

        heap[i] = heap[parent];
        i = parent;
    }

    heap[i] = temp;
}

void Print(int heap[], int n)
{
    printf("Max Heap: [");

    for (int i = 0; i < n; i++) {
        printf("%d", heap[i]);

        if (i < n - 1)
            printf(", ");
    }

    printf("]\n");
}