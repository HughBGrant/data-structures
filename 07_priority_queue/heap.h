#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

struct h_node {
    int priority;
};

typedef struct h_node h_item;

struct heap {
    h_item *items;
    size_t capacity;
    size_t count;
};
typedef struct heap h_priority_queue;

void h_insert(h_priority_queue *pq, h_item data);
h_item h_remove(h_priority_queue *pq);

h_priority_queue *h_create(void);

#endif