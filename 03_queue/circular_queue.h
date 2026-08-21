#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int cq_item;
typedef struct circular_queue cq_queue;

void cq_enqueue(cq_queue *queue, cq_item value);
void cq_dequeue(cq_queue *queue);
cq_item *cq_peek(cq_queue *queue);
bool cq_is_empty(cq_queue *queue);
size_t cq_size(cq_queue *queue);

cq_queue *cq_create(void);
void cq_destroy(cq_queue *queue);

#endif