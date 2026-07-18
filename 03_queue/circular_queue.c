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

    queue->items = malloc(sizeof(cq_data) * (capacity + 1));
    if (queue->items == NULL) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity + 1;
    queue->front = 0;
    queue->rear = 0;

    return queue;
}
void cq_enqueue(circular_queue *queue, cq_data data)
{
    if (queue == NULL || cq_is_full(queue)) {
        return;
    }
    queue->items[queue->rear] = data;
    queue->rear = (queue->rear + 1) % queue->capacity;
}
void cq_dequeue(circular_queue *queue)
{
    if (queue == NULL || cq_is_empty(queue)) {
        return;
    }
    queue->front = (queue->front + 1) % queue->capacity;
}
cq_data *cq_peek(circular_queue *queue)
{
    if (queue == NULL || cq_is_empty(queue)) {
        return;
    }
    return &queue->items[queue->front];
}

bool cq_is_empty(circular_queue *queue)
{
    if (queue == NULL) {
        return true;
    }
    return queue->front == queue->rear;
}
bool cq_is_full(circular_queue *queue)
{
    if (queue == NULL) {
        return false;
    }
    return (queue->rear + 1) % queue->capacity == queue->front;
}
size_t cq_size(circular_queue *queue)
{
    if (queue == NULL) {
        return 0;
    }

    return (queue->capacity + queue->rear - queue->front) % queue->capacity;
}
void cq_destroy(circular_queue *queue)
{
    if (queue == NULL) {
        return;
    }
    free(queue->items);
    free(queue);
}