#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int cq_data;

typedef struct {
    cq_data *items;
    size_t capacity;
    size_t front;
    size_t count;
} cq_queue;

void cq_enqueue(cq_queue *queue, cq_data data);
void cq_dequeue(cq_queue *queue);
cq_data *cq_peek(cq_queue *queue);
bool cq_is_empty(cq_queue *queue);
size_t cq_size(cq_queue *queue);

cq_queue *cq_create(size_t capacity);
void cq_destroy(cq_queue *queue);

#endif