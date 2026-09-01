#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int LItem;
typedef struct LinkedQueue LQueue;

void lq_enqueue(LQueue *queue, LItem value);
LItem lq_dequeue(LQueue *queue);
LItem lq_peek(LQueue *queue);
bool lq_is_empty(LQueue *queue);
size_t lq_size(LQueue *queue);

LQueue *lq_create(void);
void lq_destroy(LQueue *queue);

#endif