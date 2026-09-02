#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stddef.h>

struct BNode {
    int priority;
};
typedef struct BNode BItem;
typedef struct BinaryHeap BPriorityQueue;

BPriorityQueue *b_create(void);
void b_destroy(BPriorityQueue *heap);
void b_insert(BPriorityQueue *heap, int priority);
BItem b_extract(BPriorityQueue *heap);
size_t b_size(BPriorityQueue *heap);

void b_heapify(BItem *arr, size_t size, size_t root);

#endif