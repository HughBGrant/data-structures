#include "linked_list.h"

LinkedList *LL_CreateList(void)
{
    LinkedList *List = malloc(sizeof(LinkedList));

    if (List == NULL)
    {
        return NULL;
    }
    List->Count = 0;
    List->Head = NULL;
    List->Tail = NULL;

    return List;
}
void LL_DestroyList(LinkedList *List)
{
    if (List == NULL)
    {
        return;
    }
    LL_Node *Current = List->Head;

    while (List->Count > 0)
    {
        LL_RemoveNode(List, 0);
    }
    free(List);
}
LL_Node *LL_CreateNode(LL_DataType NewData)
{
    LL_Node *NewNode = malloc(sizeof(LL_Node));

    if (NewNode == NULL)
    {
        return NULL;
    }
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    
    return NewNode;
}
void LL_DestroyNode(LL_Node *Node)
{
    free(Node);
}
void LL_AppendTail(LinkedList *List, LL_DataType NewData)
{
    LL_Node *NewTail = LL_CreateNode(NewData);

    if (NewTail == NULL)
    {
        return;
    }
    if (List->Head == NULL)
    {
        List->Head = NewTail;
    }
    else
    {
        List->Tail->NextNode = NewTail;
    }
    List->Tail = NewTail;
    List->Count++;
}
void LL_AppendHead(LinkedList *List, LL_DataType NewData)
{
    LL_Node *NewHead = LL_CreateNode(NewData);

    if (NewHead == NULL)
    {
        return;
    }
    NewHead->NextNode = List->Head;
    List->Head = NewHead;

    if (List->Tail == NULL)
    {
        List->Tail = NewHead;
    }
    List->Count++;
}
size_t LL_GetSize(LinkedList *List)
{
    if (List == NULL)
    {
        return 0;
    }
    return List->Count;
}
LL_Node *LL_GetNodeAt(LinkedList *List, size_t Location)
{
    if (Location >= LL_GetSize(List))
    {
        return NULL;
    }
    if (Location == LL_GetSize(List) - 1)
    {
        return List->Tail;
    }
    LL_Node *Current = List->Head;

    while (Current != NULL && Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void LL_RemoveNode(LinkedList *List, size_t Location)
{
    if (List == NULL || Location >= List->Count)
    {
        return;
    }
    LL_Node *Previous = NULL;
    LL_Node *Current = List->Head;

    for (size_t i = 0; i < Location; i++)
    {
        Previous = Current;
        Current = Current->NextNode;
    }
    if (Current == List->Head)
    {
        List->Head = Current->NextNode;
    }
    else
    {
        Previous->NextNode = Current->NextNode;
    }
    if (Current == List->Tail)
    {
        List->Tail = NULL;
    }
    printf("Destroying Node : %d\n", Current->Data);
    LL_DestroyNode(Current);
    List->Count--;
}
void LL_InsertAfter(LinkedList *List, size_t Location, LL_DataType NewData)
{
    LL_Node *Current = LL_GetNodeAt(List, Location);

    if (Current == NULL)
    {
        return;
    }
    LL_Node *NewNode = LL_CreateNode(NewData);

    if (NewNode == NULL)
    {
        return;
    }
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;

    if (Current == List->Tail)
    {
        List->Tail = NewNode;
    }
    List->Count++;
}
void LL_InsertBefore(LinkedList *List, size_t Location, LL_DataType NewData)
{
    LL_Node *Current = LL_GetNodeAt(List, Location);

    if (Current == NULL)
    {
        return;
    }
    LL_Node *NewNode = LL_CreateNode(NewData);

    if (NewNode == NULL)
    {
        return;
    }
    if (Current == List->Head)
    {
        NewNode->NextNode = Current;
        List->Head = NewNode;
        List->Count++;
        return;
    }
    LL_Node *Previous = List->Head;
    while (Previous != NULL && Previous->NextNode != Current)
    {
        Previous = Previous->NextNode;
    }
    if (Previous != NULL)
    {
        NewNode->NextNode = Current;
        Previous->NextNode = NewNode;
        List->Count++;
    }
}