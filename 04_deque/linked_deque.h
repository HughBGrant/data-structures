#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagLQ_Node {
    char *data;
    struct tagLQ_Node *next;
} lq_node;

typedef struct {
    lq_node *front;
    lq_node *rear;
    size_t count;
} linked_queue;

linked_queue *lq_create(void);
lq_node *lq_create_node(char *NewData);
void lq_enqueue(linked_queue *Queue, char *NewData);
void lq_dequeue(linked_queue *Queue);
char *lq_peek(linked_queue *Queue);
void lq_destroy(linked_queue *Queue);

bool lq_is_empty(linked_queue *Queue);

#endif