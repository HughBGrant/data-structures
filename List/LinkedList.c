#include "LinkedList.h"

LinkedList *SLL_CreateList(void)
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
void SLL_DestroyList(LinkedList *List)
{
    if (List == NULL)
    {
        return;
    }
    SLL_Node *Current = List->Head;

    while (List->Count > 0)
    {
        SLL_RemoveNode(List, 0);
    }
    free(List);
}
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
void SLL_AppendTail(LinkedList *List, SLL_DataType NewData)
{
    SLL_Node *NewTail = SLL_CreateNode(NewData);

    if (NewTail == NULL)
    {
        return;
    }

    if (SLL_GetSize(List) == 0)
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
void SLL_AppendHead(LinkedList *List, SLL_DataType NewData)
{
    SLL_Node *NewHead = SLL_CreateNode(NewData);

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
size_t SLL_GetSize(LinkedList *List)
{
    if (List == NULL)
    {
        return 0;
    }
    return List->Count;
}
SLL_Node *SLL_GetNodeAt(LinkedList *List, size_t Location)
{
    if (Location >= SLL_GetSize(List))
    {
        return NULL;
    }
    if (Location == SLL_GetSize(List) - 1)
    {
        return List->Tail;
    }
    SLL_Node *Current = List->Head;

    while (Current != NULL && Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void SLL_RemoveNode(LinkedList *List, size_t Location)
{
    if (SLL_GetSize(List) == 0)
    {
        return;
    }
    SLL_Node *Remove = SLL_GetNodeAt(List, Location);

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
        SLL_DestroyNode(Remove);
        List->Count--;
        
        return;
    }
    SLL_Node *Current = List->Head;

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
    SLL_DestroyNode(Remove);
    List->Count--;
}
void SLL_InsertAfter(LinkedList *List, size_t Location, SLL_DataType NewData)
{
    SLL_Node *Current = SLL_GetNodeAt(List, Location);

    if (Current == NULL)
    {
        return;
    }
    SLL_Node *NewNode = SLL_CreateNode(NewData);

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
void SLL_InsertBefore(LinkedList *List, size_t Location, SLL_DataType NewData)
{
    SLL_Node *Current = SLL_GetNodeAt(List, Location);

    if (Current == NULL)
    {
        return;
    }
    SLL_Node *NewNode = SLL_CreateNode(NewData);

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
    SLL_Node *Before = List->Head;
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