#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stddef.h>

struct bh_node {
    int priority;
};
typedef struct bh_node bh_item;
typedef struct heap bh_priority_queue;

bh_priority_queue *bh_create(void);
void bh_destroy(bh_priority_queue *pq);
void bh_insert(bh_priority_queue *pq, int priority);
bh_item bh_extract(bh_priority_queue *pq);
size_t bh_size(bh_priority_queue *pq);

void bh_heapify(bh_item *arr, int size, int root);

#endif