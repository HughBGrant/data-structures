#include <stdio.h>
#include <stdlib.h>
#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode != NULL)
    {
        NewNode->Data = NewData;
        NewNode->PrevNode = NULL;
        NewNode->NextNode = NULL;
    }
    return NewNode;
}
void CDLL_DestroyNode(Node* Node)
{
    free(Node);
}
void CDLL_AppendNode(Node** Head, ElementType NewData)
{
    Node* NewNode = CDLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else
    {
        Node* Tail = (*Head)->PrevNode;

        NewNode->NextNode = *Head;
        NewNode->PrevNode = Tail;
        (*Head)->PrevNode = NewNode;
        Tail->NextNode = NewNode;
    }
}
unsigned int CDLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;

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
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
    int Count = CDLL_GetNodeCount(Head);

    if (Location < 0 || Location >= Count)
    {
        return NULL;
    }

    Node* Current = Head;

    while (Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void CDLL_InsertAfter(Node* Head, int Location, ElementType NewData)
{
    Node* Current = CDLL_GetNodeAt(Head, Location);
    if (Current == NULL)
    {
        return;
    }
    Node* NewNode = CDLL_CreateNode(NewData);

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    Current->NextNode->PrevNode = NewNode;
    
    Current->NextNode = NewNode;
}
void CDLL_RemoveNode(Node** Head, int Location)
{
    if (*Head == NULL)
    {
        return;
    }
    Node* Remove = CDLL_GetNodeAt(*Head, Location);

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
//void CDLL_InsertBefore(Node** Head, int Location, ElementType NewData)
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
//void CDLL_InsertNewHead(Node** Head, ElementType NewData)
//{
//    Node* NewHead = CDLL_CreateNode(NewData);
//    NewHead->NextNode = *Head;
//    *Head = NewHead;
//}
//void CDLL_DestroyAllNodes(Node** Head)
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
int main(void)
{
    int i = 0;

    Node* List = NULL;
    Node* Current = NULL;

    for (i = 0; i < 5; i++)
    {
        CDLL_AppendNode(&List, i);
    }
    for (i = 0; i < CDLL_GetNodeCount(List); i++)
    {
        printf("List[%d] : %d\n", i, CDLL_GetNodeAt(List, i)->Data);
    }

    printf("\nInserting 3000 After [2]...\n\n");
    CDLL_InsertAfter(List, 2, 3000);

    printf("\nRemoving Node at [2]...\n\n");
    CDLL_RemoveNode(&List, 2);

    for (i = 0; i < CDLL_GetNodeCount(List) * 2; i++)
    {
        if (i == 0)
        {
            Current = List;
        }
        else
        {
            Current = Current->NextNode;
        }
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    while (List != NULL)
    {
        CDLL_RemoveNode(&List, 0);
    }
    return 0;
}
