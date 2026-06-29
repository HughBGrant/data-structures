#include "doubly_linked_list.h"

DoublyLinkedList *DLL_CreateList(void)
{
    DoublyLinkedList *List = malloc(sizeof(DoublyLinkedList));

    if (List == NULL)
    {
        return NULL;
    }
    List->Count = 0;
    List->Head = NULL;
    List->Tail = NULL;

    return List;
}
void DLL_DestroyList(DoublyLinkedList *List)
{
    if (List == NULL)
    {
        return;
    }
    DLL_Node *Current = List->Head;

    while (Current != NULL)
    {
        DLL_Node *Next = Current->NextNode;
        free(Current);
        Current = Next;
    }
    free(List);
}
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
void DLL_AppendTail(DoublyLinkedList *List, DLL_DataType NewData)
{
    DLL_Node *NewTail = DLL_CreateNode(NewData);

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
        NewTail->PrevNode = List->Tail;
    }
    List->Tail = NewTail;
    List->Count++;
}
size_t DLL_GetSize(DoublyLinkedList *List)
{
    if (List == NULL)
    {
        return 0;
    }
    return List->Count;
}
DLL_Node *DLL_GetNodeAt(DoublyLinkedList *List, size_t Location)
{
    if (List == NULL)
    {
        return NULL;
    }
    size_t Count = DLL_GetSize(List);

    if (Location >= Count)
    {
        return NULL;
    }
    DLL_Node *Current = NULL;

    if (Location < Count / 2)
    {
        Current = List->Head;

        while (Current != NULL && Location > 0)
        {
            Current = Current->NextNode;
            Location--;
        }
    }
    else
    {
        Current = List->Tail;

        while (Current != NULL && Location < Count - 1)
        {
            Current = Current->PrevNode;
            Location++;
        }
    }
    return Current;
}
void DLL_RemoveNode(DoublyLinkedList *List, size_t Location)
{
    if (List == NULL || Location >= List->Count)
    {
        return;
    }
    DLL_Node *Remove = DLL_GetNodeAt(List, Location);

    if (Remove == NULL)
    {
        return;
    }
    if (Remove == List->Head)
    {
        List->Head = Remove->NextNode;
    }
    else
    {
        Remove->PrevNode->NextNode = Remove->NextNode;
    }
    if (Remove == List->Tail)
    {
        List->Tail = Remove->PrevNode;
    }
    else
    {
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }
    printf("Destroying Node : %d\n", Remove->Data);
    free(Remove);

    List->Count--;
}
void DLL_InsertAfter(DoublyLinkedList *List, size_t Location, DLL_DataType NewData)
{
    DLL_Node *Previous = DLL_GetNodeAt(List, Location);

    if (Previous == NULL)
    {
        return;
    }
    DLL_Node *NewNode = DLL_CreateNode(NewData);

    if (NewNode == NULL)
    {
        return;
    }
    if (Previous == List->Tail)
    {
        List->Tail = NewNode;
    }
    else
    {
        NewNode->NextNode = Previous->NextNode;
        NewNode->NextNode->PrevNode = NewNode;
    }
    NewNode->PrevNode = Previous;
    Previous->NextNode = NewNode;

    List->Count++;
}
void DLL_PrintReverse(DoublyLinkedList *List)
{
    size_t i = List->Count - 1;

    DLL_Node *Current = List->Tail;

    while (Current != NULL)
    {
        printf("List[%zu] : %d\n", i, Current->Data);
        Current = Current->PrevNode;
        i--;
    }
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