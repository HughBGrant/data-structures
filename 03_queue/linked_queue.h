#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

typedef int lq_item;

typedef struct _lq_node {
    lq_item data;
    struct _lq_node *next;
} lq_node;

typedef struct {
    lq_node *rear;
    lq_node *front;
} linked_queue;
typedef linked_queue lq_queue;

void lq_enqueue(lq_queue *queue, lq_item data);
void lq_dequeue(lq_queue *queue);
lq_item *lq_peek(lq_queue *queue);
bool lq_is_empty(lq_queue *queue);
size_t lq_size(lq_queue *queue);

lq_queue *lq_create(void);
void lq_destroy(lq_queue *queue);
lq_node *lq_node_create(lq_item data);
void lq_node_destroy(lq_node *node);

#endif