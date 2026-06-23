#include "LinkedList.h"
SLLNode* SLL_CreateNode(ElementType NewData)
{
    SLLNode* NewNode = malloc(sizeof(SLLNode));
    if (NewNode != NULL)
    {
        NewNode->Data = NewData;
        NewNode->NextNode = NULL;
    }
    return NewNode;
}
void SLL_DestroyNode(SLLNode* Node)
{
    free(Node);
}
void SLL_AppendNode(SLLNode** Head, ElementType NewData)
{
    SLLNode* NewNode = SLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = NewNode;
        return;
    }
    SLLNode* Tail = *Head;
    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
}
SLLNode* SLL_GetNodeAt(SLLNode* Head, size_t Location)
{
    size_t Count = SLL_GetNodeCount(Head);

    if (Location >= Count)
    {
        return NULL;
    }

    SLLNode* Current = Head;

    while (Current != NULL && Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void SLL_RemoveNode(SLLNode** Head, size_t Location)
{
    if (*Head == NULL)
    {
        return;
    }
    SLLNode* Remove = SLL_GetNodeAt(*Head, Location);

    if (Remove == NULL)
    {
        return;
    }
    printf("Destroying Node : %d\n", Remove->Data);

    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        SLL_DestroyNode(Remove);
        return;
    }
    SLLNode* Current = *Head;
    while (Current != NULL && Current->NextNode != Remove)
    {
        Current = Current->NextNode;
    }
    if (Current != NULL)
    {
        Current->NextNode = Remove->NextNode;
    }
    SLL_DestroyNode(Remove);
}
void SLL_InsertBefore(SLLNode** Head, size_t Location, ElementType NewData)
{
    SLLNode* Current = SLL_GetNodeAt(*Head, Location);
    if (Current == NULL)
    {
        return;
    }
    SLLNode* NewNode = SLL_CreateNode(NewData);

    if (*Head == Current)
    {
        NewNode->NextNode = Current;
        *Head = NewNode;
        return;
    }
    SLLNode* Before = *Head;
    while (Before != NULL && Before->NextNode != Current)
    {
        Before = Before->NextNode;
    }
    if (Before != NULL)
    {
        NewNode->NextNode = Current;
        Before->NextNode = NewNode;
    }
}
void SLL_InsertAfter(SLLNode* Head, size_t Location, ElementType NewData)
{
    SLLNode* Current = SLL_GetNodeAt(Head, Location);
    if (Current == NULL)
    {
        return;
    }
    SLLNode* NewNode = SLL_CreateNode(NewData);
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}
void SLL_InsertNewHead(SLLNode** Head, ElementType NewData)
{
    SLLNode* NewHead = SLL_CreateNode(NewData);
    NewHead->NextNode = *Head;
    *Head = NewHead;
}
void SLL_DestroyAllNodes(SLLNode** Head)
{
    SLLNode* Current = *Head;

    while (Current != NULL)
    {
        SLLNode* Next = Current->NextNode;
        SLL_DestroyNode(Current);
        Current = Next;
    }
    *Head = NULL;
}
size_t SLL_GetNodeCount(SLLNode* Head)
{
    size_t Count = 0;
    SLLNode* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}