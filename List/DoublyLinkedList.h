#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagDLLNode
{
    ElementType Data;
    struct tagDLLNode* PrevNode;
    struct tagDLLNode* NextNode;
} DLLNode;
DLLNode* DLL_CreateNode(ElementType NewData);
void DLL_DestroyNode(DLLNode* Node);
void DLL_AppendNode(DLLNode** Head, ElementType NewData);
unsigned int DLL_GetNodeCount(DLLNode* Head);
DLLNode* DLL_GetNodeAt(DLLNode* Head, int Location);
void DLL_RemoveNode(DLLNode** Head, int Location);
void DLL_InsertAfter(DLLNode* Head, int Location, ElementType NewData);
#endif
