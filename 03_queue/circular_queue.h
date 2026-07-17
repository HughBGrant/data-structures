#define _CRT_SECURE_NO_WARNINGS
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int cq_data;

typedef struct {
    cq_data *items;
    size_t rear;
    size_t front;
    size_t max_size;
} circular_queue;

circular_queue *cq_create(size_t max_size);
void cq_enqueue(circular_queue *queue, cq_data data);
void cq_dequeue(circular_queue *queue);
cq_data *cq_peek(circular_queue *queue);

void cq_destroy(circular_queue *queue);

bool cq_is_empty(circular_queue *queue);
bool cq_is_full(circular_queue *queue);
size_t cq_size(circular_queue *queue);

#endif