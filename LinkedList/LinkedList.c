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
    Node* NewNode = SLL_CreateNode(NewData);
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
    printf("%p\n", Current);

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
        printf("%p\n", Current);
    }
    return Current;

}
void SLL_RemoveNode(Node** Head, int Location)
{
    if (*Head == NULL)
    {
        return;
    }
    Node* Remove = SLL_GetNodeAt(*Head, Location);
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
void SLL_InsertAfter(Node* Current, ElementType NewData)
{
    Node* NewNode = SLL_CreateNode(NewData);
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}
void SLL_InsertBefore(Node** Head, int Location, ElementType NewData)
{
    Node* Current = SLL_GetNodeAt(*Head, Location);
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
        SLL_AppendNode(&List, i);
    }

    SLL_AppendNode(&List, -1);
    SLL_AppendNode(&List, -2);
    Count = SLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        printf("List[%d] : %d\n", i, SLL_GetNodeAt(List, i)->Data);
    }
    printf("\nInserting 3000 After [2]...\n\n");

    SLL_InsertBefore(&List, 2, 3000);

    Count = SLL_GetNodeCount(List);

    for (i = 0; i < Count; i++)
    {
        printf("List[%d] : %d\n", i, SLL_GetNodeAt(List, i)->Data);
    }

    printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {

        SLL_RemoveNode(&List, 0);
        
    }
    return 0;
}
