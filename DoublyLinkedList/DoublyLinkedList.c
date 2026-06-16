#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* DLL_CreateNode(ElementType NewData)
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
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}
void DLL_AppendNode(Node** Head, ElementType NewData)
{
    Node* NewNode = DLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        Node* Tail = *Head;
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    int Count = CDLL_GetNodeCount(Head);

    if (Location < 0 || Location >= Count)
    {
        return;
    }

    Node* Current = Head;

    while (Current != NULL && Location > 0)
    {
        Current = Current->NextNode;
        Location--;
    }
    return Current;
}
void DLL_RemoveNode(Node** Head, int Location)
{
    if (*Head == NULL)
    {
        return;
    }
    Node* Remove = DLL_GetNodeAt(*Head, Location);

    if (Remove == NULL)
    {
        return;
    }
    printf("Destroying Node : %d\n", Remove->Data);

    if (*Head == Remove)
    {
        *Head = Remove->NextNode;

        if (*Head != NULL)
        {
            (*Head)->PrevNode = NULL;
        }
    }
    else
    {
        if (Remove->PrevNode != NULL)
        {
            Remove->PrevNode->NextNode = Remove->NextNode;
        }
        if (Remove->NextNode != NULL)
        {
            Remove->NextNode->PrevNode = Remove->PrevNode;
        }
    }
    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
    DLL_DestroyNode(Remove);
}
int DLL_GetNodeCount(Node* Head)
{
    unsigned int Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}
void DLL_InsertAfter(Node* Head, int Location, ElementType NewData)
{
    Node* Current = DLL_GetNodeAt(Head, Location);
    if (Current == NULL)
    {
        return;
    }
    Node* NewNode = DLL_CreateNode(NewData);

    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;
    if (Current->NextNode != NULL)
    {
        NewNode->NextNode->PrevNode = NewNode;
    }

    Current->NextNode = NewNode;
}
//void DLL_InsertBefore(Node** Head, int Location, ElementType NewData)
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
//void DLL_InsertNewHead(Node** Head, ElementType NewData)
//{
//    Node* NewNode = DLL_CreateNode(NewData);
//    NewNode->NextNode = *Head;
//    *Head = NewNode;
//}
//void DLL_DestroyAllNodes(Node** Head)
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
void PrintReverse(Node* Head)
{
    int i = 0;

    Node* Current = Head;

    while (Current != NULL && Current->NextNode != NULL)
    {
        Current = Current->NextNode;
        i++;
    }
    while (Current != NULL)
    {
        printf("List[%d] : %d\n", i, Current->Data);
        Current = Current->PrevNode;
        i--;
    }
}
int main(void)
{
    int i = 0;

    Node* List = NULL;

    for (i = 0; i < 5; i++)
    {
        DLL_AppendNode(&List, i);
    }

    for (i = 0; i < DLL_GetNodeCount(List); i++)
    {
        printf("List[%d] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }

    printf("\nInserting 3000 After [2]...\n\n");
    DLL_InsertAfter(List, 2, 3000);

    for (i = 0; i < DLL_GetNodeCount(List); i++)
    {
        printf("List[%d] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }

    printf("\nDestroying List...\n");

    while (List != NULL)
    {
        DLL_RemoveNode(&List, 0);
    }
    return 0;
}
