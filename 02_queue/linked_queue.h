#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *lq_data;

typedef struct _lq_node {
    lq_data data;
    struct _lq_node *next;
} lq_node;

typedef struct {
    lq_node *front;
    lq_node *rear;
} linked_queue;

linked_queue *lq_create(void);
lq_node *lq_create_node(lq_data data);
void lq_enqueue(linked_queue *queue, lq_data data);
void lq_dequeue(linked_queue *queue);
lq_data lq_peek(linked_queue *queue);
void lq_destroy(linked_queue *queue);

bool lq_is_empty(linked_queue *queue);
size_t lq_size(linked_queue *queue);

#endif