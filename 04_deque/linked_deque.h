#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagLQ_Node {
    char *Data;
    struct tagLQ_Node *NextNode;
} LQ_Node;

typedef struct {
    LQ_Node *Front;
    LQ_Node *Rear;
    size_t Count;
} LQ;

LQ *LQ_CreateQueue(void);
LQ_Node *LQ_CreateNode(char *NewData);
void LQ_Enqueue(LQ *Queue, char *NewData);
void LQ_Dequeue(LQ *Queue);
char *LQ_Peek(LQ *Queue);
void LQ_DestroyQueue(LQ *Queue);

bool LQ_IsEmpty(LQ *Queue);

#endif