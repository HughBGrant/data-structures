#ifndef HEAP_H
#define HEAP_H

#define MAX_ELEMENT 200
#include <stddef.h>

typedef struct {
    int value;
} h_node;

typedef h_node h_item;

struct heap {
    h_item data[MAX_ELEMENT];
    size_t count;
};
typedef struct heap h_priority_queue;

void h_insert(h_priority_queue *queue, h_item data);
h_item h_remove(h_priority_queue *queue);

h_priority_queue *h_create(void);

#endif