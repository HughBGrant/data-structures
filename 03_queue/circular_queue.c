#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct circular_queue {
    cq_item *data;
    size_t capacity;
    size_t front;
    size_t count;
};

cq_queue *cq_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    cq_queue *queue = malloc(sizeof(cq_queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->data = malloc(sizeof(cq_item) * capacity);
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->front = 0;
    queue->count = 0;

    return queue;
}
void cq_destroy(cq_queue *queue)
{
    if (queue == NULL) {
        return;
    }
    free(queue->data);
    free(queue);
}
void cq_enqueue(cq_queue *queue, cq_item data)
{
    if (queue == NULL) {
        return;
    }
    if (queue->count == queue->capacity) {
        size_t new_capacity = queue->capacity * 2;
        cq_item *new_items = malloc(sizeof(cq_item) * new_capacity);
        if (new_items == NULL) {
            return;
        }

        for (size_t i = 0; i < queue->count; ++i) {
            new_items[i] = queue->data[(queue->front + i) % queue->capacity];
        }
        free(queue->data);
        queue->data = new_items;
        queue->front = 0;
        queue->capacity = new_capacity;
    }
    size_t rear = (queue->front + queue->count) % queue->capacity;
    queue->data[rear] = data;
    queue->count++;
}
void cq_dequeue(cq_queue *queue)
{
    if (cq_is_empty(queue)) {
        return;
    }
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
}
cq_item *cq_peek(cq_queue *queue)
{
    if (cq_is_empty(queue)) {
        return NULL;
    }
    return &queue->data[queue->front];
}
bool cq_is_empty(cq_queue *queue)
{
    return queue == NULL || queue->count == 0;
}
size_t cq_size(cq_queue *queue)
{
    return queue ? queue->count : 0;
}