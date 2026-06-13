#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    return NewNode;
}
void SLL_DestroyNode(Node* Node)
{
    free(Node);
}
void SLL_AppendNode(Node** Head, ElementType NewData)
{
    Node* Tail = SLL_CreateNode(NewData);

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
    }
}
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }
    return Current;
}
void SLL_InsertBefore(Node** Head, int Location, ElementType NewData)
{
    Node* Current = SLL_GetNodeAt(*Head, Location);
    if (Current == NULL)
    {
        return;
    }
    Node* NewNode = SLL_CreateNode(NewData);

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
void SLL_InsertAfter(Node* Head, int Location, ElementType NewData)
{
    Node* Current = SLL_GetNodeAt(Head, Location);
    if (Current == NULL)
    {
        return;
    }
    Node* NewNode = SLL_CreateNode(NewData);
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}
void SLL_InsertNewHead(Node** Head, ElementType NewData)
{
    Node* NewHead = SLL_CreateNode(NewData);
    NewHead->NextNode = *Head;
    *Head = NewHead;
}
void SLL_RemoveNode(Node** Head, int Location)
{
    if (*Head == NULL)
    {
        return;
    }
    Node* Remove = SLL_GetNodeAt(*Head, Location);

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
    SLL_DestroyNode(Remove);
}
void SLL_DestroyAllNodes(Node** Head)
{
    Node* Current = *Head;

    while (Current != NULL)
    {
        Node* Next = Current->NextNode;
        SLL_DestroyNode(Current);
        Current = Next;
    }
    *Head = NULL;
}
int SLL_GetNodeCount(Node* Head)
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

    Node* Head = NULL;

    for (i = 0; i < 5; i++)
    {
        SLL_AppendNode(&Head, i);
    }

    SLL_AppendNode(&Head, -1);
    SLL_AppendNode(&Head, -2);

    for (i = 0; i < SLL_GetNodeCount(Head); i++)
    {
        printf("Head[%d] : %d\n", i, SLL_GetNodeAt(Head, i)->Data);
    }
    printf("\nInserting 3000 Before [2]...\n\n");

    SLL_InsertBefore(&Head, 2, 3000);


    for (i = 0; i < SLL_GetNodeCount(Head); i++)
    {
        printf("Head[%d] : %d\n", i, SLL_GetNodeAt(Head, i)->Data);
    }
    printf("\nInserting 2000 After [2]...\n\n");
    SLL_InsertAfter(Head, 2, 2000);


    for (i = 0; i < SLL_GetNodeCount(Head); i++)
    {
        printf("Head[%d] : %d\n", i, SLL_GetNodeAt(Head, i)->Data);
    }

    printf("\nDestroying Head...\n");
    int Count = SLL_GetNodeCount(Head);

    while (Head != NULL)
    {
        SLL_RemoveNode(&Head, 0);
    }
    return 0;
}
