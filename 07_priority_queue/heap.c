#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 32

struct heap {
    h_item *items;
    size_t capacity;
    size_t count;
};

void h_heapify(h_item *items, int count, int parent)
{
    int left = 2 * parent + 1;

    if (left >= count) {
        return;
    }

    int right = left + 1;
    int child = left;

    if (right < count &&
        items[right].priority > items[left].priority) {
        child = right;
    }

    if (items[parent].priority >= items[child].priority) {
        return;
    }

    h_item temp = items[parent];
    items[parent] = items[child];
    items[child] = temp;

    h_heapify(items, count, child);
}
h_priority_queue *h_create(void)
{
    h_priority_queue *pq = malloc(sizeof(h_priority_queue));
    if (pq == NULL) {
        return NULL;
    }
    size_t capacity = INITIAL_CAPACITY;

    pq->items = malloc(sizeof(h_item) * capacity);
    if (pq->items == NULL) {
        free(pq);
        return NULL;
    }
    pq->capacity = capacity;
    pq->count = 0;

    return pq;
}
void h_destroy(h_priority_queue *pq)
{
    if (pq == NULL) {
        return;
    }
    free(pq->items);
    free(pq);
}
void h_insert(h_priority_queue *pq, int priority)
{
    if (pq == NULL) {
        return;
    }

    size_t index = pq->count;

    while (index > 0) {
        size_t parent = (index - 1) / 2;

        if (priority <= pq->items[parent].priority) {
            break;
        }
        pq->items[index] = pq->items[parent];
        index = parent;
    }
    pq->items[index] = (h_item){priority};
    pq->count++;
}
h_item h_extract(h_priority_queue *pq)
{
    h_item top = (h_item){0};

    if (pq == NULL || pq->count == 0) {
        return top;
    }
    top = pq->items[0];
    pq->count--;

    if (pq->count > 0) {
        pq->items[0] = pq->items[pq->count];
        h_heapify(pq->items, pq->count, 0);
    }

    return top;
}
size_t h_size(h_priority_queue *pq)
{
    return pq ? pq->count : 0;
}