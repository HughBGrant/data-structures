#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 32

struct heap {
    h_item *items;
    size_t capacity;
    size_t count;
};

static void h_sift_down(h_priority_queue *pq, size_t pos);
static void h_sift_down(h_priority_queue *pq, size_t pos)
{
    h_item data = pq->items[pos];

    while (1) {
        size_t left = 2 * pos + 1;

        if (left >= pq->count) {
            break;
        }
        size_t right = left + 1;
        size_t child = left;

        if (right < pq->count &&
            (pq->items[right].priority > pq->items[left].priority)) {
            child = right;
        }
        if (data.priority >= pq->items[child].priority) {
            break;
        }
        pq->items[pos] = pq->items[child];
        pos = child;
    }
    pq->items[pos] = data;
}
void h_heapify(h_priority_queue *pq)
{
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
    h_item new_item = {priority};
    size_t pos = pq->count;

    while (pos > 0) {
        size_t parent = (pos - 1) / 2;

        if (pq->items[parent].priority >= priority) {
            break;
        }
        pq->items[pos] = pq->items[parent];
        pos = parent;
    }
    pq->items[pos] = new_item;
    pq->count++;
}
h_item h_extract(h_priority_queue *pq)
{
    h_item top = pq->items[0];
    pq->count--;
    h_item data = pq->items[pq->count];
    size_t pos = 0;

    if (pq->count > 0) {
        pq->items[0] = data;
        h_sift_down(pq, 0);
    }

    return top;
}
size_t h_size(h_priority_queue *pq)
{
    return pq ? pq->count : 0;
}