#include "circular_doubly_linked_list.h"

CDLL_Node* CDLL_CreateNode(CDLL_DataType NewData)
{
    CDLL_Node *NewNode = malloc(sizeof(CDLL_Node));

    if (NewNode != NULL)
    {
        NewNode->Data = NewData;
        NewNode->PrevNode = NULL;
        NewNode->NextNode = NULL;
    }
    return NewNode;
}
void CDLL_DestroyNode(CDLL_Node *Node)
{
    free(Node);
}
void CDLL_AppendTail(CircularDoublyLinkedList *List, CDLL_DataType NewData)
{
    CDLL_Node *NewNode = CDLL_CreateNode(NewData);

    if (List->Head == NULL)
    {
        List->Head = NewNode;
        List->Head->NextNode = List->Head;
        List->Head->PrevNode = List->Head;
    }
    else
    {
        CDLL_Node *Tail = List->Head->PrevNode;

        NewNode->NextNode = List->Head;
        NewNode->PrevNode = Tail;
        List->Head->PrevNode = NewNode;
        Tail->NextNode = NewNode;
    }
}
size_t CDLL_GetSize(CircularDoublyLinkedList *List)
{
    size_t Count = 0;
    CDLL_Node *Current = List->Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;

        if (Current == List->Head)
        {
            break;
        }
    }
    return Count;
}
CDLL_Node *CDLL_GetNodeAt(CircularDoublyLinkedList *List, size_t Location)
{
    size_t Count = CDLL_GetSize(List);

    if (Location >= Count)
    {
        return NULL;
    }

    CDLL_Node *Current = List->Head;

    while (Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void CDLL_InsertAfter(CircularDoublyLinkedList *List, size_t Location, CDLL_DataType NewData)
{
    CDLL_Node *Current = CDLL_GetNodeAt(List, Location);
    if (Current == NULL)
    {
        return;
    }
    CDLL_Node *NewNode = CDLL_CreateNode(NewData);

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    Current->NextNode->PrevNode = NewNode;

    Current->NextNode = NewNode;
}
void CDLL_RemoveNode(CircularDoublyLinkedList *List, size_t Location)
{
    if (List->Head == NULL)
    {
        return;
    }
    CDLL_Node *Remove = CDLL_GetNodeAt(List, Location);

    if (Remove == NULL)
    {
        return;
    }
    printf("Destroying Node : %d\n", Remove->Data);

    if (Remove->NextNode == Remove)
    {
        List->Head = NULL;
        CDLL_DestroyNode(Remove);
        return;
    }
    Remove->PrevNode->NextNode = Remove->NextNode;
    Remove->NextNode->PrevNode = Remove->PrevNode;

    if (List->Head == Remove)
    {
        List->Head = Remove->NextNode;
    }
    CDLL_DestroyNode(Remove);
}
//void PrintReverse(Node* Head)
//{
//    int i = 0;
//
//    Node* Current = Head;
//
//    while (Current != NULL && Current->NextNode != NULL)
//    {
//        Current = Current->NextNode;
//        i++;
//    }
//    while (Current != NULL)
//    {
//        printf("List[%d] : %d\n", i, Current->Data);
//        Current = Current->PrevNode;
//        i--;
//    }
//}
//void CDLL_InsertBefore(Node **Head, int Location, ElementType NewData)
//{
//    Node* Current = CDLL_GetNodeAt(*Head, Location);
//    if (Current == NULL)
//    {
//        return;
//    }
//    Node* NewNode = CDLL_CreateNode(NewData);
//
//    if (*Head == Current)
//    {
//        NewNode->NextNode = Current;
//        *Head = NewNode;
//    }
//    else
//    {
//        Node* Before = *Head;
//        while (Before != NULL && Before->NextNode != Current)
//        {
//            Before = Before->NextNode;
//        }
//        if (Before != NULL)
//        {
//            NewNode->NextNode = Current;
//            Before->NextNode = NewNode;
//        }
//    }
//}
//void CDLL_InsertNewHead(Node **Head, ElementType NewData)
//{
//    Node* NewHead = CDLL_CreateNode(NewData);
//    NewHead->NextNode = *Head;
//    *Head = NewHead;
//}
//void CDLL_DestroyAllNodes(Node **Head)
//{
//    Node* Current = *Head;
//
//    while (Current != NULL)
//    {
//        Node* Next = Current->NextNode;
//        CDLL_DestroyNode(Current);
//        Current = Next;
//    }
//    *Head = NULL;
//}