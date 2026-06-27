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

    if (NewNode != NULL)
    {
        NewNode->Data = NewData;
        NewNode->NextNode = NULL;
    }
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

    if (LL_GetSize(List) == 0)
    {
        List->Head = NewTail;
        List->Tail = NewTail;
    }
    else
    {
        List->Tail->NextNode = NewTail;
        List->Tail = NewTail;
    }
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
    if (LL_GetSize(List) == 0)
    {
        return;
    }
    LL_Node *Remove = LL_GetNodeAt(List, Location);

    if (Remove == NULL)
    {
        return;
    }
    printf("Destroying Node : %d\n", Remove->Data);

    if (Remove == List->Head)
    {
        List->Head = Remove->NextNode;

        if (Remove == List->Tail)
        {
            List->Tail = NULL;
        }
        LL_DestroyNode(Remove);
        List->Count--;
        
        return;
    }
    LL_Node *Current = List->Head;

    while (Current != NULL && Current->NextNode != Remove)
    {
        Current = Current->NextNode;
    }
    if (Current != NULL)
    {
        Current->NextNode = Remove->NextNode;

        if (Remove == List->Tail)
        {
            List->Tail = Current;
        }
    }
    LL_DestroyNode(Remove);
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
    LL_Node *Before = List->Head;
    while (Before != NULL && Before->NextNode != Current)
    {
        Before = Before->NextNode;
    }
    if (Before != NULL)
    {
        NewNode->NextNode = Current;
        Before->NextNode = NewNode;
        List->Count++;
    }
}