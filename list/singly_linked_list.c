#include "singly_linked_list.h"

SinglyLinkedList *SLL_CreateList(void)
{
    SinglyLinkedList *List = malloc(sizeof(SinglyLinkedList));

    if (List == NULL) {
        return NULL;
    }
    List->Count = 0;
    List->Head = NULL;
    List->Tail = NULL;

    return List;
}

void SLL_DestroyList(SinglyLinkedList *List)
{
    if (List == NULL) {
        return;
    }
    SLL_Node *Current = List->Head;

    while (List->Count > 0) {
        SLL_RemoveNode(List, 0);
    }
    free(List);
}
SLL_Node *SLL_CreateNode(SLL_DataType NewData)
{
    SLL_Node *NewNode = malloc(sizeof(SLL_Node));

    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}
void SLL_AppendTail(SinglyLinkedList *List, SLL_DataType NewData)
{
    SLL_Node *NewTail = SLL_CreateNode(NewData);

    if (NewTail == NULL) {
        return;
    }
    if (List->Head == NULL) {
        List->Head = NewTail;
    } else {
        List->Tail->NextNode = NewTail;
    }
    List->Tail = NewTail;
    List->Count++;
}
SLL_Node *SLL_GetNodeAt(SinglyLinkedList *List, size_t Location)
{
    if (Location >= SLL_GetSize(List)) {
        return NULL;
    }
    if (Location == SLL_GetSize(List) - 1) {
        return List->Tail;
    }
    SLL_Node *Current = List->Head;

    while (Current != NULL && Location > 0) {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void SLL_RemoveNode(SinglyLinkedList *List, size_t Location)
{
    if (List == NULL || Location >= List->Count) {
        return;
    }

    SLL_Node *Previous = NULL;
    SLL_Node *Current = List->Head;
    for (size_t i = 0; i < Location; i++) {
        Previous = Current;
        Current = Current->NextNode;
    }
    if (Current == List->Head) {
        List->Head = Current->NextNode;
    } else {
        Previous->NextNode = Current->NextNode;
    }
    if (Current == List->Tail) {
        List->Tail = NULL;
    }
    printf("Destroying Node : %d\n", Current->Data);
    free(Current);
    List->Count--;
}
void SLL_Insert(SinglyLinkedList *List, size_t Location, SLL_DataType NewData)
{
    SLL_Node *NewNode = SLL_CreateNode(NewData);
    if (NewNode == NULL) {
        return;
    }

    SLL_Node *Previous = NULL;
    SLL_Node *Current = List->Head;
    for (size_t i = 0; i < Location; i++) {
        Previous = Current;
        Current = Current->NextNode;
    }
    if (Current == List->Head) {
        List->Head = NewNode;
    } else {
        Previous->NextNode = NewNode;
    }
    NewNode->NextNode = Current;
    List->Count++;
}
size_t SLL_GetSize(SinglyLinkedList *List)
{
    if (List == NULL) {
        return 0;
    }
    return List->Count;
}
