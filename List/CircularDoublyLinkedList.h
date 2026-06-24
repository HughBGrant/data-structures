#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct tagCDLLNode
{
    ElementType Data;
    struct tagCDLLNode *PrevNode;
    struct tagCDLLNode *NextNode;
} CDLLNode;

CDLLNode *CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(CDLLNode *Node);
void CDLL_AppendNode(CDLLNode **Head, ElementType NewData);
size_t CDLL_GetNodeCount(CDLLNode *Head);
CDLLNode *CDLL_GetNodeAt(CDLLNode *Head, size_t Location);
void CDLL_InsertAfter(CDLLNode *Head, size_t Location, ElementType NewData);
void CDLL_RemoveNode(CDLLNode **Head, size_t Location);

#endif
