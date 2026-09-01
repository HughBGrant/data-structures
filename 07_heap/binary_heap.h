#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stddef.h>

struct BNode {
    int priority;
};
typedef struct BNode BItem;
typedef struct BinaryHeap BPriorityQueue;

BPriorityQueue *bh_create(void);
void bh_destroy(BPriorityQueue *heap);
void bh_insert(BPriorityQueue *heap, int priority);
BItem bh_extract(BPriorityQueue *heap);
size_t bh_size(BPriorityQueue *heap);

void bh_heapify(BItem *arr, size_t size, size_t root);

#endif