#include "linked_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _lq_node {
    lq_item data;
    struct _lq_node *next;
} lq_node;

struct linked_queue {
    lq_node *rear;
    lq_node *front;
};

static lq_node *lq_node_create(lq_item data)
{
    lq_node *new_node = malloc(sizeof(lq_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
static void lq_node_destroy(lq_node *node)
{
    free(node);
}
lq_queue *lq_create(void)
{
    lq_queue *queue = malloc(sizeof(lq_queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}
void lq_destroy(lq_queue *queue)
{
    if (queue == NULL) {
        return;
    }
    while (queue->front) {
        lq_dequeue(queue);
    }
    free(queue);
}
void lq_enqueue(lq_queue *queue, lq_item data)
{
    if (queue == NULL) {
        return;
    }
    lq_node *new_rear = lq_node_create(data);
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
void lq_dequeue(lq_queue *queue)
{
    if (lq_is_empty(queue)) {
        return;
    }
    lq_node *target_node = queue->front;
    queue->front = target_node->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    lq_node_destroy(target_node);
}
lq_item *lq_peek(lq_queue *queue)
{
    if (lq_is_empty(queue)) {
        return NULL;
    }
    return &queue->front->data;
}
size_t lq_size(lq_queue *queue)
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
bool lq_is_empty(lq_queue *queue)
{
    return queue == NULL || queue->front == NULL;
}