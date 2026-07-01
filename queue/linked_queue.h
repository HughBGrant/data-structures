#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagLQ_Node {
	char* Data;
	struct tagLQ_Node* NextNode;
} LQ_Node;

typedef struct {
	LQ_Node* Front;
	LQ_Node* Rear;
	size_t Count;
} LinkedQueue;

LinkedQueue* LQ_CreateQueue(void);
LQ_Node* LQ_CreateNode(char* NewData);
void LQ_Enqueue(LinkedQueue* Queue, char* NewData);
void LQ_Dequeue(LinkedQueue* Queue);
char* LQ_Peek(LinkedQueue* Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);

bool LQ_IsEmpty(LinkedQueue* Queue);

#endif
