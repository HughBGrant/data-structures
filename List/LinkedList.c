#include "LinkedList.h"
SLL_Node *SLL_CreateNode(SLL_DataType NewData)
{
    SLL_Node *NewNode = malloc(sizeof(SLL_Node));
    if (NewNode != NULL)
    {
        NewNode->Data = NewData;
        NewNode->NextNode = NULL;
    }
    return NewNode;
}
void SLL_DestroyNode(SLL_Node *Node)
{
    free(Node);
}
void SLL_AppendNode(SLL_Node **Head, SLL_DataType NewData)
{
    SLL_Node *NewNode = SLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = NewNode;
        return;
    }
    SLL_Node *Tail = *Head;
    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
}
SLL_Node *SLL_GetNodeAt(SLL_Node *Head, size_t Location)
{
    size_t Count = SLL_GetNodeSize(Head);

    if (Location >= Count)
    {
        return NULL;
    }

    SLL_Node *Current = Head;

    while (Current != NULL && Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void SLL_RemoveNode(SLL_Node **Head, size_t Location)
{
    if (*Head == NULL)
    {
        return;
    }
    SLL_Node *Remove = SLL_GetNodeAt(*Head, Location);

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
    SLL_Node *Current = *Head;
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
void SLL_InsertBefore(SLL_Node **Head, size_t Location, SLL_DataType NewData)
{
    SLL_Node *Current = SLL_GetNodeAt(*Head, Location);
    if (Current == NULL)
    {
        return;
    }
    SLL_Node *NewNode = SLL_CreateNode(NewData);

    if (*Head == Current)
    {
        NewNode->NextNode = Current;
        *Head = NewNode;
        return;
    }
    SLL_Node *Before = *Head;
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
void SLL_InsertAfter(SLL_Node *Head, size_t Location, SLL_DataType NewData)
{
    SLL_Node *Current = SLL_GetNodeAt(Head, Location);
    if (Current == NULL)
    {
        return;
    }
    SLL_Node *NewNode = SLL_CreateNode(NewData);
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}
void SLL_InsertNewHead(SLL_Node **Head, SLL_DataType NewData)
{
    SLL_Node *NewHead = SLL_CreateNode(NewData);
    NewHead->NextNode = *Head;
    *Head = NewHead;
}
void SLL_DestroyAllNodes(SLL_Node **Head)
{
    SLL_Node *Current = *Head;

    while (Current != NULL)
    {
        SLL_Node *Next = Current->NextNode;
        SLL_DestroyNode(Current);
        Current = Next;
    }
    *Head = NULL;
}
size_t SLL_GetNodeSize(SLL_Node *Head)
{
    size_t Count = 0;
    SLL_Node *Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}