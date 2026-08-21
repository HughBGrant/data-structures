#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

struct h_node {
    int priority;
};
typedef struct h_node h_item;
typedef struct heap h_priority_queue;

h_priority_queue *h_create(void);
void h_destroy(h_priority_queue *pq);
void h_insert(h_priority_queue *pq, int priority);
h_item h_extract(h_priority_queue *pq);
size_t h_size(h_priority_queue *pq);

void h_heapify(h_item arr[], int count, int root);

#endif