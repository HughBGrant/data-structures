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
    DLL_Node *new_tail = DLL_CreateNode(NewData);
    if (new_tail == NULL) {
        return;
    }

    if (List->Head == NULL) {
        List->Head = new_tail;
    } else {
        new_tail->PrevNode = List->Tail;
        List->Tail->NextNode = new_tail;
    }
    new_tail->NextNode = List->Head;
    List->Head->PrevNode = new_tail;
    List->Tail = new_tail;

    List->Count++;
}
void DLL_Insert(DLL *List, size_t Location, DLL_DataType NewData)
{
    DLL_Node *Current = DLL_GetNodeAt(List, Location);
    if (Current == NULL) {
        return;
    }

    DLL_Node *new_node = DLL_CreateNode(NewData);
    if (new_node == NULL) {
        return;
    }

    Current->PrevNode->NextNode = new_node;
    new_node->PrevNode = Current->PrevNode;
    new_node->NextNode = Current;
    Current->PrevNode = new_node;

    if (Current == List->Head) {
        List->Head = new_node;
    }
    List->Count++;
}

void DLL_RemoveNode(DLL *List, size_t Location)
{
    if (List == NULL || Location >= List->Count) {
        return;
    }
    DLL_Node *Current = DLL_GetNodeAt(List, Location);
    if (Current == NULL) {
        return;
    }

    if (List->Head == List->Tail) {
        List->Head = NULL;
        List->Tail = NULL;
    } else {
        Current->PrevNode->NextNode = Current->NextNode;
        Current->NextNode->PrevNode = Current->PrevNode;

        if (Current == List->Head) {
            List->Head = Current->NextNode;
        }
        if (Current == List->Tail) {
            List->Tail = Current->PrevNode;
        }
    }
    printf("Destroying Node : %d\n", Current->Data);
    free(Current);
    List->Count--;
}
DLL_Node *DLL_GetNodeAt(DLL *List, size_t Location)
{
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
size_t DLL_GetSize(DLL *List)
{
    if (List == NULL) {
        return 0;
    }
    return List->Count;
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