#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

h_priority_queue *h_create(void)
{
    h_priority_queue *pq = malloc(sizeof(h_priority_queue));
    if (pq == NULL) {
        return NULL;
    }
    pq->count = 0;

    return pq;
}
void h_insert(h_priority_queue *pq, h_item data)
{
    size_t pos = pq->count;

    while (pos > 0) {
        size_t parent = (pos - 1) / 2;

        if (pq->data[parent].priority >= data.priority) {
            break;
        }
        pq->data[pos] = pq->data[parent];
        pos = parent;
    }
    pq->data[pos] = data;
    pq->count++;
}
h_item h_remove(h_priority_queue *pq)
{
    h_item top = pq->data[0];
    pq->count--;
    h_item data = pq->data[pq->count];
    size_t pos = 0;

    while (1) {
        size_t left = 2 * pos + 1;

        if (left >= pq->count) {
            break;
        }
        size_t right = left + 1;
        size_t child = left;

        if (right < pq->count &&
            (pq->data[right].priority > pq->data[left].priority)) {
            child = right;
        }
        if (data.priority >= pq->data[child].priority) {
            break;
        }
        pq->data[pos] = pq->data[child];
        pos = child;
    }
    pq->data[pos] = data;

    return top;
}