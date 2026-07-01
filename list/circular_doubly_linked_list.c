#include "circular_doubly_linked_list.h"

CircularDoublyLinkedList *CDLL_CreateList(void)
{
    CircularDoublyLinkedList *List = malloc(sizeof(CircularDoublyLinkedList));

    if (List == NULL)
    {
        return NULL;
    }
    List->Count = 0;
    List->Head = NULL;
    List->Tail = NULL;

    return List;
}
void CDLL_DestroyList(CircularDoublyLinkedList *List)
{
    if (List == NULL)
    {
        return;
    }
    while (List->Count > 0)
    {
        CDLL_RemoveNode(List, 0);
    }
    free(List);
}
CDLL_Node *CDLL_CreateNode(CDLL_DataType NewData)
{
    CDLL_Node *NewNode = malloc(sizeof(CDLL_Node));

    if (NewNode == NULL)
    {
        return NULL;
    }
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}
void CDLL_AppendTail(CircularDoublyLinkedList *List, CDLL_DataType NewData)
{
    CDLL_Node *NewNode = CDLL_CreateNode(NewData);
    if (NewNode == NULL)
    {
        return;
    }
    if (List->Head == NULL)
    {
        List->Head = NewNode;
    }
    else
    {
        NewNode->PrevNode = List->Tail;
        List->Tail->NextNode = NewNode;
    }
    NewNode->NextNode = List->Head;
    List->Head->PrevNode = NewNode;
    List->Tail = NewNode;

    List->Count++;
}
size_t CDLL_GetSize(CircularDoublyLinkedList *List)
{
    if (List == NULL)
    {
        return 0;
    }
    return List->Count;
}
CDLL_Node *CDLL_GetNodeAt(CircularDoublyLinkedList *List, size_t Location)
{
    if (List == NULL)
    {
        return NULL;
    }
    size_t Count = CDLL_GetSize(List);

    if (Location >= Count)
    {
        return NULL;
    }
    CDLL_Node *Current = NULL;

    if (Location < Count / 2)
    {
        Current = List->Head;

        while (Location > 0)
        {
            Current = Current->NextNode;
            Location--;
        }
    }
    else
    {
        Current = List->Tail;

        while (Location < Count - 1)
        {
            Current = Current->PrevNode;
            Location++;
        }
    }
    return Current;
}
void CDLL_RemoveNode(CircularDoublyLinkedList *List, size_t Location)
{
    if (List == NULL || Location >= List->Count)
    {
        return;
    }
    CDLL_Node *Remove = CDLL_GetNodeAt(List, Location);
    if (Remove == NULL)
    {
        return;
    }

    if (List->Head == List->Tail)
    {
        List->Head = NULL;
        List->Tail = NULL;
    }
    else
    {
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;

        if (Remove == List->Head)
        {
            List->Head = Remove->NextNode;
        }
        if (Remove == List->Tail)
        {
            List->Tail = Remove->PrevNode;
        }
    }
    printf("Destroying Node : %d\n", Remove->Data);
    free(Remove);
    List->Count--;
}
void CDLL_Insert(CircularDoublyLinkedList *List, size_t Location, CDLL_DataType NewData)
{
    CDLL_Node *Current = CDLL_GetNodeAt(List, Location);

    if (Current == NULL)
    {
        return;
    }
    CDLL_Node *NewNode = CDLL_CreateNode(NewData);

    if (NewNode == NULL)
    {
        return;
    }
    Current->PrevNode->NextNode = NewNode;
    NewNode->PrevNode = Current->PrevNode;
    NewNode->NextNode = Current;
    Current->PrevNode = NewNode;

    if (Current == List->Head)
    {
        List->Head = NewNode;
    }
    List->Count++;
}
//void CDLL_InsertHead(Node **Head, ElementType NewData)
//{
//    Node* NewHead = CDLL_CreateNode(NewData);
//    NewHead->NextNode = *Head;
//    *Head = NewHead;
//}
