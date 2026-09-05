#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CircularQueue CQueue;

void c_enqueue(CQueue *queue, int data);
int c_dequeue(CQueue *queue);
int c_peek(CQueue *queue);
bool c_is_empty(CQueue *queue);
size_t c_size(CQueue *queue);

CQueue *c_create(void);
void c_destroy(CQueue *queue);

#endif