#include "doubly_linked_list.h"

DLL *DLL_CreateList(void)
{
    DLL *List = malloc(sizeof(DLL));

    if (List == NULL) {
        return NULL;
    }
    List->Count = 0;
    List->Head = NULL;
    List->Tail = NULL;

    return List;
}
void DLL_DestroyList(DLL *List)
{
    if (List == NULL) {
        return;
    }
    DLL_Node *Current = List->Head;

    while (Current != NULL) {
        DLL_Node *Next = Current->NextNode;
        free(Current);
        Current = Next;
    }
    free(List);
}
DLL_Node *DLL_CreateNode(DLL_DataType NewData)
{
    DLL_Node *NewNode = malloc(sizeof(DLL_Node));

    if (NewNode != NULL) {
        NewNode->Data = NewData;
        NewNode->PrevNode = NULL;
        NewNode->NextNode = NULL;
    }
    return NewNode;
}
void DLL_AppendTail(DLL *List, DLL_DataType NewData)
{
    DLL_Node *NewTail = DLL_CreateNode(NewData);

    if (NewTail == NULL) {
        return;
    }
    if (List->Head == NULL) {
        List->Head = NewTail;
    } else {
        List->Tail->NextNode = NewTail;
        NewTail->PrevNode = List->Tail;
    }
    List->Tail = NewTail;
    List->Count++;
}
size_t DLL_GetSize(DLL *List)
{
    if (List == NULL) {
        return 0;
    }
    return List->Count;
}
DLL_Node *DLL_GetNodeAt(DLL *List, size_t Location)
{
    if (List == NULL) {
        return NULL;
    }
    size_t Count = DLL_GetSize(List);

    if (Location >= Count) {
        return NULL;
    }
    DLL_Node *Current = NULL;

    if (Location < Count / 2) {
        Current = List->Head;

        while (Current != NULL && Location > 0) {
            Current = Current->NextNode;
            Location--;
        }
    } else {
        Current = List->Tail;

        while (Current != NULL && Location < Count - 1) {
            Current = Current->PrevNode;
            Location++;
        }
    }
    return Current;
}
void DLL_RemoveNode(DLL *List, size_t Location)
{
    if (List == NULL || Location >= List->Count) {
        return;
    }
    DLL_Node *Remove = DLL_GetNodeAt(List, Location);

    if (Remove == NULL) {
        return;
    }
    if (Remove == List->Head) {
        List->Head = Remove->NextNode;
    } else {
        Remove->PrevNode->NextNode = Remove->NextNode;
    }
    if (Remove == List->Tail) {
        List->Tail = Remove->PrevNode;
    } else {
        Remove->NextNode->PrevNode = Remove->PrevNode;
    }
    printf("Destroying Node : %d\n", Remove->Data);
    free(Remove);

    List->Count--;
}
void DLL_Insert(DLL *List, size_t Location, DLL_DataType NewData)
{
    DLL_Node *Current = DLL_GetNodeAt(List, Location);
    if (Current == NULL) {
        return;
    }
    DLL_Node *NewNode = DLL_CreateNode(NewData);
    if (NewNode == NULL) {
        return;
    }
    if (Current == List->Head) {
        List->Head = NewNode;
    } else {
        NewNode->PrevNode = Current->PrevNode;
        Current->PrevNode->NextNode = NewNode;
    }
    NewNode->NextNode = Current;
    Current->PrevNode = NewNode;
    List->Count++;
}
void DLL_PrintReverse(DLL *List)
{
    size_t i = List->Count - 1;

    DLL_Node *Current = List->Tail;

    while (Current != NULL) {
        printf("List[%zu] : %d\n", i, Current->Data);
        Current = Current->PrevNode;
        i--;
    }
}
// void DLL_InsertNewHead(Node **Head, ElementType NewData)
//{
//     Node* NewNode = DLL_CreateNode(NewData);
//     NewNode->NextNode = *Head;
//     *Head = NewNode;
// }
