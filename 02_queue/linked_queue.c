#include "linked_queue.h"

linked_queue *lq_create(void)
{
    linked_queue *queue = malloc(sizeof(linked_queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}
lq_node *lq_create_node(lq_data data)
{
    if (data == NULL) {
        return NULL;
    }
    lq_node *new_node = malloc(sizeof(lq_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = malloc(strlen(data) + 1);
    if (new_node->data == NULL) {
        free(new_node);
        return NULL;
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;

    return new_node;
}
void lq_enqueue(linked_queue *queue, lq_data data)
{
    if (queue == NULL) {
        return;
    }
    lq_node *new_rear = lq_create_node(data);
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
void lq_dequeue(linked_queue *queue)
{
    if (queue == NULL || lq_is_empty(queue)) {
        return;
    }
    lq_node *free_node = queue->front;
    queue->front = free_node->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(free_node->data);
    free(free_node);
}
lq_data lq_peek(linked_queue *queue)
{
    if (queue == NULL || lq_is_empty(queue)) {
        return NULL;
    }
    return queue->front->data;
}
size_t lq_size(linked_queue *queue)
{
    if (queue == NULL) {
        return 0;
    }
    size_t size = 0;
    lq_node *now_node = queue->front;

    while (now_node) {
        size++;
        now_node = now_node->next;
    }

    return size;
}
bool lq_is_empty(linked_queue *queue)
{
    if (queue == NULL) {
        return true;
    }
    return queue->front == NULL;
}
void lq_destroy(linked_queue *queue)
{
    if (queue == NULL) {
        return;
    }
    while (queue->front) {
        lq_dequeue(queue);
    }
    free(queue);
}