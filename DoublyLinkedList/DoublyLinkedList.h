#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;
Node* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(Node* Node);
void DLL_AppendNode(Node** Head, ElementType NewData);
unsigned int DLL_GetNodeCount(Node* Head);
Node* DLL_GetNodeAt(Node* Head, int Location);
void DLL_RemoveNode(Node** Head, int Location);
void DLL_InsertAfter(Node* Head, int Location, ElementType NewData);
#endif
