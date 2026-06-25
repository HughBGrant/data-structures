#include "CircularDoublyLinkedList.h"

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
void CDLL_AppendNode(CDLL_Node **Head, CDLL_DataType NewData)
{
    CDLL_Node *NewNode = CDLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else
    {
        CDLL_Node* Tail = (*Head)->PrevNode;

        NewNode->NextNode = *Head;
        NewNode->PrevNode = Tail;
        (*Head)->PrevNode = NewNode;
        Tail->NextNode = NewNode;
    }
}
size_t CDLL_GetNodeSize(CDLL_Node *Head)
{
    size_t Count = 0;
    CDLL_Node *Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;

        if (Current == Head)
        {
            break;
        }
    }
    return Count;
}
CDLL_Node *CDLL_GetNodeAt(CDLL_Node *Head, size_t Location)
{
    size_t Count = CDLL_GetNodeSize(Head);

    if (Location >= Count)
    {
        return NULL;
    }

    CDLL_Node *Current = Head;

    while (Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void CDLL_InsertAfter(CDLL_Node *Head, size_t Location, CDLL_DataType NewData)
{
    CDLL_Node *Current = CDLL_GetNodeAt(Head, Location);
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
void CDLL_RemoveNode(CDLL_Node **Head, size_t Location)
{
    if (*Head == NULL)
    {
        return;
    }
    CDLL_Node *Remove = CDLL_GetNodeAt(*Head, Location);

    if (Remove == NULL)
    {
        return;
    }
    printf("Destroying Node : %d\n", Remove->Data);

    if (Remove->NextNode == Remove)
    {
        *Head = NULL;
        CDLL_DestroyNode(Remove);
        return;
    }
    Remove->PrevNode->NextNode = Remove->NextNode;
    Remove->NextNode->PrevNode = Remove->PrevNode;

    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
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