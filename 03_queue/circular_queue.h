#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int CItem;
typedef struct CircularQueue CQueue;

void cq_enqueue(CQueue *queue, CItem value);
CItem cq_dequeue(CQueue *queue);
CItem cq_peek(CQueue *queue);
bool cq_is_empty(CQueue *queue);
size_t cq_size(CQueue *queue);

CQueue *cq_create(void);
void cq_destroy(CQueue *queue);

#endif