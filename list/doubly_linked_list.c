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
    while (List->Count > 0) {
        DLL_RemoveNode(List, 0);
    }
    free(List);
}
DLL_Node *DLL_CreateNode(DLL_DataType NewData)
{
    DLL_Node *NewNode = malloc(sizeof(DLL_Node));

    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}
void DLL_AppendTail(DLL *List, DLL_DataType NewData)
{
    DLL_Node *NewNode = DLL_CreateNode(NewData);
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
void DLL_RemoveNode(DLL *List, size_t Location)
{
    if (List == NULL || Location >= List->Count) {
        return;
    }
    DLL_Node *Remove = DLL_GetNodeAt(List, Location);
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
void DLL_Insert(DLL *List, size_t Location,
                DLL_DataType NewData)
{
    DLL_Node *Current = DLL_GetNodeAt(List, Location);

    if (Current == NULL) {
        return;
    }
    DLL_Node *NewNode = DLL_CreateNode(NewData);

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
// void DLL_InsertHead(Node **Head, ElementType NewData)
//{
//     Node* NewHead = DLL_CreateNode(NewData);
//     NewHead->NextNode = *Head;
//     *Head = NewHead;
// }
