#include "DoublyLinkedList.h"

DLL_Node *DLL_CreateNode(DLL_DataType NewData)
{
    DLL_Node *NewNode = malloc(sizeof(DLL_Node));
    if (NewNode != NULL)
    {
        NewNode->Data = NewData;
        NewNode->PrevNode = NULL;
        NewNode->NextNode = NULL;
    }
    return NewNode;
}
void DLL_DestroyNode(DLL_Node *Node)
{
    free(Node);
}
void DLL_AppendNode(DLL_Node **Head, DLL_DataType NewData)
{
    DLL_Node *NewNode = DLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = NewNode;
        return;
    }
    DLL_Node *Tail = *Head;
    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
    NewNode->PrevNode = Tail;
}
size_t DLL_GetNodeSize(DLL_Node *Head)
{
    size_t Count = 0;
    DLL_Node *Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}
DLL_Node *DLL_GetNodeAt(DLL_Node *Head, size_t Location)
{
    size_t Count = DLL_GetNodeSize(Head);

    if (Location >= Count)
    {
        return NULL;
    }

    DLL_Node *Current = Head;

    while (Current != NULL && Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void DLL_RemoveNode(DLL_Node **Head, size_t Location)
{
    if (*Head == NULL)
    {
        return;
    }
    DLL_Node *Remove = DLL_GetNodeAt(*Head, Location);

    if (Remove == NULL)
    {
        return;
    }
    printf("Destroying Node : %d\n", Remove->Data);

    if (Remove->PrevNode != NULL)
    {
        Remove->PrevNode->NextNode = Remove->NextNode;
    }
    else
    {
        *Head = Remove->NextNode;
    }
    if (Remove->NextNode != NULL)
    {
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }
    DLL_DestroyNode(Remove);
}
void DLL_InsertAfter(DLL_Node *Head, size_t Location, DLL_DataType NewData)
{
    DLL_Node *Current = DLL_GetNodeAt(Head, Location);
    if (Current == NULL)
    {
        return;
    }
    DLL_Node *NewNode = DLL_CreateNode(NewData);

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    if (Current->NextNode != NULL)
    {
        Current->NextNode->PrevNode = NewNode;
    }
    Current->NextNode = NewNode;
}
//void DLL_InsertBefore(Node **Head, int Location, ElementType NewData)
//{
//    Node* Current = DLL_GetNodeAt(*Head, Location);
//    if (Current == NULL)
//    {
//        return;
//    }
//    Node* NewNode = DLL_CreateNode(NewData);
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
//void DLL_InsertNewHead(Node **Head, ElementType NewData)
//{
//    Node* NewNode = DLL_CreateNode(NewData);
//    NewNode->NextNode = *Head;
//    *Head = NewNode;
//}
//void DLL_DestroyAllNodes(Node **Head)
//{
//    Node* Current = *Head;
//
//    while (Current != NULL)
//    {
//        Node* Next = Current->NextNode;
//        DLL_DestroyNode(Current);
//        Current = Next;
//    }
//    *Head = NULL;
//}
void DLL_PrintReverse(DLL_Node *Head)
{
    size_t i = 0;

    DLL_Node *Current = Head;

    while (Current != NULL && Current->NextNode != NULL)
    {
        Current = Current->NextNode;
        i++;
    }
    while (Current != NULL)
    {
        printf("List[%zu] : %d\n", i, Current->Data);
        Current = Current->PrevNode;
        i--;
    }
}