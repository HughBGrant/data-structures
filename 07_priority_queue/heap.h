#ifndef HEAP_H
#define HEAP_H
#define MAX_ELEMENT 200
#include <stddef.h>

typedef int h_data;

typedef struct {
    h_data data;
} h_item;

typedef struct {
    h_item items[MAX_ELEMENT];
    size_t count;
} h_priority_queue;

void h_insert(h_priority_queue *queue, h_item item);
h_item h_delete(h_priority_queue *queue);

h_priority_queue *h_create(void);

#endif