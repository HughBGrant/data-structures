#include "binary_heap.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 32

struct heap {
    bh_item *items;
    size_t capacity;
    size_t size;
};

void bh_heapify(bh_item *items, int size, int parent)
{
    int left = 2 * parent + 1;

    if (left >= size) {
        return;
    }

    int right = left + 1;
    int child = left;

    if (right < size &&
        items[right].priority > items[left].priority) {
        child = right;
    }

    if (items[parent].priority >= items[child].priority) {
        return;
    }

    bh_item temp = items[parent];
    items[parent] = items[child];
    items[child] = temp;

    bh_heapify(items, size, child);
}
bh_priority_queue *bh_create(void)
{
    bh_priority_queue *pq = malloc(sizeof(bh_priority_queue));
    if (pq == NULL) {
        return NULL;
    }
    size_t capacity = INITIAL_CAPACITY;

    pq->items = malloc(sizeof(bh_item) * capacity);
    if (pq->items == NULL) {
        free(pq);
        return NULL;
    }
    pq->capacity = capacity;
    pq->size = 0;

    return pq;
}
void bh_destroy(bh_priority_queue *pq)
{
    if (pq == NULL) {
        return;
    }
    free(pq->items);
    free(pq);
}
void bh_insert(bh_priority_queue *pq, int priority)
{
    if (pq == NULL) {
        return;
    }

    size_t index = pq->size;

    while (index > 0) {
        size_t parent = (index - 1) / 2;

        if (priority <= pq->items[parent].priority) {
            break;
        }
        pq->items[index] = pq->items[parent];
        index = parent;
    }
    pq->items[index] = (bh_item){priority};
    pq->size++;
}
bh_item bh_extract(bh_priority_queue *pq)
{
    bh_item top = (bh_item){0};

    if (pq == NULL || pq->size == 0) {
        return top;
    }
    top = pq->items[0];
    pq->size--;

    if (pq->size > 0) {
        pq->items[0] = pq->items[pq->size];
        bh_heapify(pq->items, pq->size, 0);
    }

    return top;
}
size_t bh_size(bh_priority_queue *pq)
{
    return pq ? pq->size : 0;
}