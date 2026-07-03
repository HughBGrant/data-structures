#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int DLL_DataType;

typedef struct tagDLL_Node {
    DLL_DataType Data;
    struct tagDLL_Node *PrevNode;
    struct tagDLL_Node *NextNode;
} DLL_Node;

typedef struct {
    DLL_Node *Head;
    DLL_Node *Tail;
    size_t Count;
} DLL;

DLL *DLL_CreateList(void);
DLL_Node *DLL_CreateNode(DLL_DataType NewData);
void DLL_AppendTail(DLL *List, DLL_DataType NewData);
void DLL_Insert(DLL *List, size_t Location, DLL_DataType NewData);
void DLL_RemoveNode(DLL *List, size_t Location);
DLL_Node *DLL_GetNodeAt(DLL *List, size_t Location);

void DLL_DestroyList(DLL *List);

size_t DLL_GetSize(DLL *List);

#endif
