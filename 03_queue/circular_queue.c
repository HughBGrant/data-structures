#include "circular_queue.h"

circular_queue *cq_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    circular_queue *queue = malloc(sizeof(circular_queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->items = malloc(sizeof(cq_data) * capacity);
    if (queue->items == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->front = 0;
    queue->count = 0;

    return queue;
}
void cq_enqueue(circular_queue *queue, cq_data data)
{
    if (queue == NULL || cq_is_full(queue)) {
        return;
    }
    size_t rear = (queue->front + queue->count) % queue->capacity;
    queue->items[rear] = data;
    queue->count++;
}
void cq_dequeue(circular_queue *queue)
{
    if (queue == NULL || cq_is_empty(queue)) {
        return;
    }
    queue->front = (queue->front + 1) % queue->capacity;
    queue->count--;
}
cq_data *cq_peek(circular_queue *queue)
{
    if (queue == NULL || cq_is_empty(queue)) {
        return NULL;
    }
    return &queue->items[queue->front];
}
bool cq_is_empty(circular_queue *queue)
{
    if (queue == NULL) {
        return true;
    }
    return queue->count == 0;
}
bool cq_is_full(circular_queue *queue)
{
    if (queue == NULL) {
        return false;
    }
    return queue->count == queue->capacity;
}
size_t cq_size(circular_queue *queue)
{
    if (queue == NULL) {
        return 0;
    }

    return queue->count;
}
void cq_destroy(circular_queue *queue)
{
    if (queue == NULL) {
        return;
    }
    free(queue->items);
    free(queue);
}