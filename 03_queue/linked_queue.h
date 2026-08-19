#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int lq_item;
typedef struct linked_queue lq_queue;

void lq_enqueue(lq_queue *queue, lq_item data);
void lq_dequeue(lq_queue *queue);
lq_item *lq_peek(lq_queue *queue);
bool lq_is_empty(lq_queue *queue);
size_t lq_size(lq_queue *queue);

lq_queue *lq_create(void);
void lq_destroy(lq_queue *queue);

#endif