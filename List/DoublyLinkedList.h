#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int DLL_DataType;

typedef struct tagDLL_Node
{
    DLL_DataType Data;
    struct tagDLL_Node *PrevNode;
    struct tagDLL_Node *NextNode;
} DLL_Node;
DLL_Node *DLL_CreateNode(DLL_DataType NewData);
void DLL_DestroyNode(DLL_Node *Node);
void DLL_AppendNode(DLL_Node **Head, DLL_DataType NewData);
size_t DLL_GetNodeSize(DLL_Node *Head);
DLL_Node *DLL_GetNodeAt(DLL_Node *Head, size_t Location);
void DLL_RemoveNode(DLL_Node **Head, size_t Location);
void DLL_InsertAfter(DLL_Node *Head, size_t Location, DLL_DataType NewData);
#endif
