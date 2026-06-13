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
    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    return NewNode;
}
void DLL_DestroyNode(Node* Node)
{
    free(Node);
}
void DLL_AppendNode(Node** Head, ElementType NewData)
{
    Node* Tail = DLL_CreateNode(NewData);

    if (*Head == NULL)
    {
        *Head = Tail;
    }
    else
    {
        Node* Current = *Head;
        while (Current->NextNode != NULL)
        {
            Current = Current->NextNode;
        }
        Current->NextNode = Tail;
        Tail->PrevNode = Current;
    }
}
Node* DLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }
    return Current;
}
void DLL_InsertBefore(Node** Head, int Location, ElementType NewData)
{
    Node* Current = DLL_GetNodeAt(*Head, Location);
    if (Current == NULL)
    {
        return;
    }
    Node* NewNode = DLL_CreateNode(NewData);

    if (*Head == Current)
    {
        NewNode->NextNode = Current;
        *Head = NewNode;
    }
    else
    {
        Node* Before = *Head;
        while (Before != NULL && Before->NextNode != Current)
        {
            Before = Before->NextNode;
        }
        if (Before != NULL)
        {
            NewNode->NextNode = Current;
            Before->NextNode = NewNode;
        }
    }
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
    Current->NextNode = NewNode;
}
void DLL_InsertNewHead(Node** Head, ElementType NewData)
{
    Node* NewHead = DLL_CreateNode(NewData);
    NewHead->NextNode = *Head;
    *Head = NewHead;
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
    }
    else
    {
        Node* Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }
        if (Current != NULL)
        {
            Current->NextNode = Remove->NextNode;
        }
    }
    DLL_DestroyNode(Remove);
}
void DLL_DestroyAllNodes(Node** Head)
{
    Node* Current = *Head;

    while (Current != NULL)
    {
        Node* Next = Current->NextNode;
        DLL_DestroyNode(Current);
        Current = Next;
    }
    *Head = NULL;
}
int DLL_GetNodeCount(Node* Head)
{
    int Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}
int main(void)
{
    int i = 0;

    Node* List = NULL;

    for (i = 0; i < 5; i++)
    {
        DLL_AppendNode(&List, i);
    }

    DLL_AppendNode(&List, -1);
    DLL_AppendNode(&List, -2);

    for (i = 0; i < DLL_GetNodeCount(List); i++)
    {
        printf("List[%d] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 Before [2]...\n\n");

    DLL_InsertBefore(&List, 2, 3000);


    for (i = 0; i < DLL_GetNodeCount(List); i++)
    {
        printf("List[%d] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 2000 After [2]...\n\n");
    DLL_InsertAfter(List, 2, 2000);


    for (i = 0; i < DLL_GetNodeCount(List); i++)
    {
        printf("List[%d] : %d\n", i, DLL_GetNodeAt(List, i)->Data);
    }

    printf("\nDestroying List...\n");
    int Count = DLL_GetNodeCount(List);

    while (List != NULL)
    {
        DLL_RemoveNode(&List, 0);
    }
    return 0;
}
