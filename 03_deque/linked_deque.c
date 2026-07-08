#include "linked_deque.h"

linked_queue *lq_create(void)
{
    linked_queue *Queue = malloc(sizeof(linked_queue));

    if (Queue == NULL) {
        return NULL;
    }
    Queue->front = NULL;
    Queue->rear = NULL;
    Queue->count = 0;

    return Queue;
}
void lq_destroy(linked_queue *Queue)
{
    while (lq_is_empty(Queue) == false) {
        lq_dequeue(Queue);
    }
    free(Queue);
}
lq_node *lq_create_node(char *NewData)
{
    lq_node *NewNode = malloc(sizeof(lq_node));

    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->data = malloc(strlen(NewData) + 1);

    if (NewNode->data == NULL) {
        free(NewNode);
        return NULL;
    }
    strcpy(NewNode->data, NewData);
    NewNode->next = NULL;

    return NewNode;
}
void lq_enqueue(linked_queue *Queue, char *NewData)
{
    if (Queue == NULL) {
        return;
    }
    lq_node *NewNode = lq_create_node(NewData);

    if (NewNode == NULL) {
        return;
    }
    if (Queue->front == NULL) {
        Queue->front = NewNode;
    } else {
        Queue->rear->next = NewNode;
    }
    Queue->rear = NewNode;
    Queue->count++;
}
void lq_dequeue(linked_queue *Queue)
{
    if (Queue == NULL || Queue->front == NULL) {
        return;
    }
    lq_node *front = Queue->front;

    Queue->front = front->next;

    if (Queue->front == NULL) {
        Queue->rear = NULL;
    }

    free(front->data);
    free(front);
    Queue->count--;
}
char *lq_peek(linked_queue *Queue)
{
    if (Queue == NULL || Queue->front == NULL) {
        return NULL;
    }
    return Queue->front->data;
}
bool lq_is_empty(linked_queue *Queue)
{
    if (Queue == NULL) {
        return true;
    }
    return Queue->count == 0;
}
