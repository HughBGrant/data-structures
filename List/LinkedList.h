#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef int SLL_DataType;

typedef struct tagSLL_Node
{
    SLL_DataType Data;
    struct tagSLL_Node *NextNode;
} SLL_Node;
SLL_Node *SLL_CreateNode(SLL_DataType NewData);
void SLL_DestroyNode(SLL_Node *Node);
void SLL_AppendNode(SLL_Node **Head, SLL_DataType NewData);
SLL_Node *SLL_GetNodeAt(SLL_Node *Head, size_t Location);
void SLL_RemoveNode(SLL_Node **Head, size_t Location);
void SLL_InsertBefore(SLL_Node **Head, size_t Location, SLL_DataType NewData);
void SLL_InsertAfter(SLL_Node *Head, size_t Location, SLL_DataType NewData);
void SLL_InsertNewHead(SLL_Node **Head, SLL_DataType NewData);
void SLL_DestroyAllNodes(SLL_Node **Head);
size_t SLL_GetNodeSize(SLL_Node *Head);

#endif
