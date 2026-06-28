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
CDLL_Node* CDLL_CreateNode(CDLL_DataType NewData)
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
void CDLL_DestroyNode(CDLL_Node *Node)
{
    free(Node);
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
    CDLL_DestroyNode(Remove);
    List->Count--;
}
void CDLL_InsertAfter(CircularDoublyLinkedList *List, size_t Location, CDLL_DataType NewData)
{
    CDLL_Node *Previous = CDLL_GetNodeAt(List, Location);

    if (Previous == NULL)
    {
        return;
    }
    CDLL_Node *NewNode = CDLL_CreateNode(NewData);

    if (NewNode == NULL)
    {
        return;
    }
    Previous->NextNode->PrevNode = NewNode;
    NewNode->NextNode = Previous->NextNode;
    NewNode->PrevNode = Previous;
    Previous->NextNode = NewNode;

    if (Previous == List->Tail)
    {
        List->Tail = NewNode;
    }
    List->Count++;
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