#include "linked_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _lq_node {
    LItem data;
    struct _lq_node *next;
} lq_node;

struct LinkedQueue {
    lq_node *rear;
    lq_node *front;
};

static lq_node *lq_node_create(LItem value);

static void lq_node_destroy(lq_node *node);

static lq_node *lq_node_create(LItem value)
{
    lq_node *new_node = malloc(sizeof(lq_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}
static void lq_node_destroy(lq_node *node)
{
    free(node);
}
LQueue *lq_create(void)
{
    LQueue *queue = malloc(sizeof(LQueue));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}
void lq_destroy(LQueue *queue)
{
    if (queue == NULL) {
        return;
    }
    while (queue->front) {
        lq_dequeue(queue);
    }
    free(queue);
}
void lq_enqueue(LQueue *queue, LItem value)
{
    if (queue == NULL) {
        return;
    }
    lq_node *new_rear = lq_node_create(value);
    if (new_rear == NULL) {
        return;
    }
    if (queue->front == NULL) {
        queue->front = new_rear;
    } else {
        queue->rear->next = new_rear;
    }
    queue->rear = new_rear;
}
LItem lq_dequeue(LQueue *queue)
{
    if (lq_is_empty(queue)) {
        return 0;
    }
    lq_node *target_node = queue->front;
    queue->front = target_node->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    LItem data = target_node->data;
    lq_node_destroy(target_node);
    return data;
}
LItem lq_peek(LQueue *queue)
{
    if (lq_is_empty(queue)) {
        return 0;
    }
    return queue->front->data;
}
size_t lq_size(LQueue *queue)
{
    if (queue == NULL) {
        return 0;
    }
    size_t size = 0;
    lq_node *current_node = queue->front;

    while (current_node) {
        size++;
        current_node = current_node->next;
    }

    return size;
}
bool lq_is_empty(LQueue *queue)
{
    return queue == NULL || queue->front == NULL;
}