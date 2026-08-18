#include "heap.h"
#include <stdio.h>

/* Insert key at the end */
void Insert(int vec[], int *size, int key)
{
    int i = *size;
    vec[i] = key;
    (*size)++;

    while (i > 0) {
        int parent = (i % 2 == 0)
                         ? (i / 2) - 1
                         : i / 2;

        if (key <= vec[parent]) {
            break;
        }

        vec[i] = vec[parent];
        i = parent;
    }

    vec[i] = key;
}

/* In-place insertion */
void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];

    while (i > 0) {
        int parent = (i % 2 == 0)
                         ? (i / 2) - 1
                         : i / 2;

        if (temp <= A[parent]) {
            break;
        }

        A[i] = A[parent];
        i = parent;
    }

    A[i] = temp;
}

/* Create Heap using another array */
void CreateHeap(int vec[], int *size, int A[], int n)
{
    /* O(n log n) */
    for (int i = 0; i < n; i++) {
        Insert(vec, size, A[i]);
    }
}

/* Create Heap in-place */
void createHeap(int A[], int n)
{
    for (int i = 0; i < n; i++) {
        InsertInplace(A, i);
    }
}

/* Print array */
void Print(int A[], int n, char c)
{
    printf("%c: [", c);

    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);

        if (i < n - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}