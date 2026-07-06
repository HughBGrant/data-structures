#include "linked_queue.h"

LQ *LQ_CreateQueue(void)
{
    LQ *Queue = malloc(sizeof(LQ));

    if (Queue == NULL) {
        return NULL;
    }
    Queue->Front = NULL;
    Queue->Rear = NULL;
    Queue->Count = 0;

    return Queue;
}
void LQ_DestroyQueue(LQ *Queue)
{
    while (LQ_IsEmpty(Queue) == false) {
        LQ_Dequeue(Queue);
    }
    free(Queue);
}
LQ_Node *LQ_CreateNode(char *NewData)
{
    LQ_Node *NewNode = malloc(sizeof(LQ_Node));

    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Data = malloc(strlen(NewData) + 1);

    if (NewNode->Data == NULL) {
        free(NewNode);
        return NULL;
    }
    strcpy(NewNode->Data, NewData);
    NewNode->NextNode = NULL;

    return NewNode;
}
void LQ_Enqueue(LQ *Queue, char *NewData)
{
    if (Queue == NULL) {
        return;
    }
    LQ_Node *NewNode = LQ_CreateNode(NewData);

    if (NewNode == NULL) {
        return;
    }
    if (Queue->Front == NULL) {
        Queue->Front = NewNode;
    } else {
        Queue->Rear->NextNode = NewNode;
    }
    Queue->Rear = NewNode;
    Queue->Count++;
}
void LQ_Dequeue(LQ *Queue)
{
    if (Queue == NULL || Queue->Front == NULL) {
        return;
    }
    LQ_Node *Front = Queue->Front;

    Queue->Front = Front->NextNode;

    if (Queue->Front == NULL) {
        Queue->Rear = NULL;
    }

    free(Front->Data);
    free(Front);
    Queue->Count--;
}
char *LQ_Peek(LQ *Queue)
{
    if (Queue == NULL || Queue->Front == NULL) {
        return NULL;
    }
    return Queue->Front->Data;
}
bool LQ_IsEmpty(LQ *Queue)
{
    if (Queue == NULL) {
        return true;
    }
    return Queue->Count == 0;
}
