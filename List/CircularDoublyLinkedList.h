#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int CDLL_DataType;

typedef struct tagCDLL_Node
{
    CDLL_DataType Data;
    struct tagCDLL_Node *PrevNode;
    struct tagCDLL_Node *NextNode;
} CDLL_Node;

CDLL_Node *CDLL_CreateNode(CDLL_DataType NewData);
void CDLL_DestroyNode(CDLL_Node *Node);
void CDLL_AppendNode(CDLL_Node **Head, CDLL_DataType NewData);
size_t CDLL_GetNodeSize(CDLL_Node *Head);
CDLL_Node *CDLL_GetNodeAt(CDLL_Node *Head, size_t Location);
void CDLL_InsertAfter(CDLL_Node *Head, size_t Location, CDLL_DataType NewData);
void CDLL_RemoveNode(CDLL_Node **Head, size_t Location);

#endif
