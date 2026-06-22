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
size_t DLL_GetNodeCount(DLLNode* Head);
DLLNode* DLL_GetNodeAt(DLLNode* Head, size_t Location);
void DLL_RemoveNode(DLLNode** Head, size_t Location);
void DLL_InsertAfter(DLLNode* Head, size_t Location, ElementType NewData);
#endif
