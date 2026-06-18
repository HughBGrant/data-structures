#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, ElementType NewData);
unsigned int CDLL_GetNodeCount(Node* Head);
Node* CDLL_GetNodeAt(Node* Head, int Location);
void CDLL_InsertAfter(Node* Head, int Location, ElementType NewData);
void CDLL_RemoveNode(Node** Head, int Location);

#endif
