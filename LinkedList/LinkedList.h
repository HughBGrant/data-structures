#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;
} Node;
Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, ElementType NewData);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_RemoveNode(Node** Head, int Location);
void SLL_InsertBefore(Node** Head, int Location, ElementType NewData);
void SLL_InsertAfter(Node* Head, int Location, ElementType NewData);
void SLL_InsertNewHead(Node** Head, ElementType NewData);
void SLL_DestroyAllNodes(Node** Head);
int SLL_GetNodeCount(Node* Head);


#endif
