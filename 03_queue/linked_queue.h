#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct LinkedQueue LQueue;

void l_enqueue(LQueue *queue, int data);
int l_dequeue(LQueue *queue);
int l_peek(LQueue *queue);
bool l_is_empty(LQueue *queue);
size_t l_size(LQueue *queue);

LQueue *l_create(void);
void l_destroy(LQueue *queue);

#endif