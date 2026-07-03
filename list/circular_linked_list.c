#include "circular_linked_list.h"

CircularLinkedList *CLL_CreateList(void)
{
    CircularLinkedList *List = malloc(sizeof(CircularLinkedList));

    if (List == NULL) {
        return NULL;
    }
    List->Count = 0;
    List->Head = NULL;
    List->Tail = NULL;

    return List;
}
void CLL_DestroyList(CircularLinkedList *List)
{
    if (List == NULL) {
        return;
    }
    while (List->Count > 0) {
        CLL_RemoveNode(List, 0);
    }
    free(List);
}
CLL_Node *CLL_CreateNode(CLL_DataType NewData)
{
    CLL_Node *NewNode = malloc(sizeof(CLL_Node));

    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}
void CLL_AppendTail(CircularLinkedList *List, CLL_DataType NewData)
{
    CLL_Node *NewNode = CLL_CreateNode(NewData);
    if (NewNode == NULL) {
        return;
    }
    if (List->Head == NULL) {
        List->Head = NewNode;
    } else {
        NewNode->PrevNode = List->Tail;
        List->Tail->NextNode = NewNode;
    }
    NewNode->NextNode = List->Head;
    List->Head->PrevNode = NewNode;
    List->Tail = NewNode;

    List->Count++;
}
size_t CLL_GetSize(CircularLinkedList *List)
{
    if (List == NULL) {
        return 0;
    }
    return List->Count;
}
CLL_Node *CLL_GetNodeAt(CircularLinkedList *List, size_t Location)
{
    if (List == NULL) {
        return NULL;
    }
    size_t Count = CLL_GetSize(List);

    if (Location >= Count) {
        return NULL;
    }
    CLL_Node *Current = NULL;

    if (Location < Count / 2) {
        Current = List->Head;

        while (Location > 0) {
            Current = Current->NextNode;
            Location--;
        }
    } else {
        Current = List->Tail;

        while (Location < Count - 1) {
            Current = Current->PrevNode;
            Location++;
        }
    }
    return Current;
}
void CLL_RemoveNode(CircularLinkedList *List, size_t Location)
{
    if (List == NULL || Location >= List->Count) {
        return;
    }
    CLL_Node *Remove = CLL_GetNodeAt(List, Location);
    if (Remove == NULL) {
        return;
    }

    if (List->Head == List->Tail) {
        List->Head = NULL;
        List->Tail = NULL;
    } else {
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;

        if (Remove == List->Head) {
            List->Head = Remove->NextNode;
        }
        if (Remove == List->Tail) {
            List->Tail = Remove->PrevNode;
        }
    }
    printf("Destroying Node : %d\n", Remove->Data);
    free(Remove);
    List->Count--;
}
void CLL_Insert(CircularLinkedList *List, size_t Location,
                CLL_DataType NewData)
{
    CLL_Node *Current = CLL_GetNodeAt(List, Location);

    if (Current == NULL) {
        return;
    }
    CLL_Node *NewNode = CLL_CreateNode(NewData);

    if (NewNode == NULL) {
        return;
    }
    Current->PrevNode->NextNode = NewNode;
    NewNode->PrevNode = Current->PrevNode;
    NewNode->NextNode = Current;
    Current->PrevNode = NewNode;

    if (Current == List->Head) {
        List->Head = NewNode;
    }
    List->Count++;
}
// void CLL_InsertHead(Node **Head, ElementType NewData)
//{
//     Node* NewHead = CLL_CreateNode(NewData);
//     NewHead->NextNode = *Head;
//     *Head = NewHead;
// }
