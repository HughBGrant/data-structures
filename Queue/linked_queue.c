#include "linked_queue.h"

LinkedQueue *LQ_CreateQueue(void)
{
	LinkedQueue *Queue = malloc(sizeof(LinkedQueue));

	if (Queue == NULL)
	{
		return NULL;
	}
	Queue->Front = NULL;
	Queue->Rear = NULL;
	Queue->Count = 0;

	return Queue;
}
void LQ_DestroyQueue(LinkedQueue *Queue)
{
	while (LQ_IsEmpty(Queue) == false)
	{
		LQ_Dequeue(Queue);
	}
	free(Queue);
}
LQ_Node *LQ_CreateNode(char *NewData)
{
	LQ_Node *NewNode = malloc(sizeof(LQ_Node));

	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Data = malloc(strlen(NewData) + 1);

	if (NewNode->Data == NULL)
	{
		free(NewNode);
		return NULL;
	}
	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL;

	return NewNode;
}
void LQ_DestroyNode(LQ_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	free(Node->Data);
	free(Node);
}
void LQ_Enqueue(LinkedQueue *Queue, char *NewData)
{
	if (Queue == NULL)
	{
		return;
	}
	LQ_Node *NewNode = LQ_CreateNode(NewData);

	if (NewNode == NULL)
	{
		return;
	}
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
	}
	Queue->Rear = NewNode;
	Queue->Count++;
}
void LQ_Dequeue(LinkedQueue *Queue)
{
	if (Queue == NULL || Queue->Front == NULL)
	{
		return;
	}
	LQ_Node *Front = Queue->Front;

	Queue->Front = Front->NextNode;

	if (Queue->Front == NULL)
	{
		Queue->Rear = NULL;
	}
	LQ_DestroyNode(Front);
	Queue->Count--;
}
char *LQ_Peek(LinkedQueue *Queue)
{
	if (Queue == NULL || Queue->Front == NULL)
	{
		return NULL;
	}
	return Queue->Front->Data;
}
bool LQ_IsEmpty(LinkedQueue *Queue)
{
	if (Queue == NULL)
	{
		return true;
	}
	return Queue->Count == 0;
}

