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
void SLL_AppendNode(Node** Head, Node* NewNode)
{
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
void SLL_RemoveNode(Node** Head, Node* Remove)
{
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
}
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
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
int main(void)
{
    int i = 0;
    int Count = 0;

    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;
    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_AppendNode(&List, NewNode);
    NewNode = SLL_CreateNode(-2);
    SLL_AppendNode(&List, NewNode);
    Count = SLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertBefore(&List, Current, NewNode);

    Count = SLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");
    for (i = 0; i < Count; i++)
    {
        Current = SLL_GetNodeAt(List, 0);

        printf("Destroying Node : %d\n", Current->Data);

        if (Current != NULL)
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
    return 0;
}
