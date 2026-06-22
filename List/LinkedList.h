#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct tagSLLNode
{
    ElementType Data;
    struct tagSLLNode* NextNode;
} SLLNode;
SLLNode* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(SLLNode* Node);
void SLL_AppendNode(SLLNode** Head, ElementType NewData);
SLLNode* SLL_GetNodeAt(SLLNode* Head, size_t Location);
void SLL_RemoveNode(SLLNode** Head, size_t Location);
void SLL_InsertBefore(SLLNode** Head, size_t Location, ElementType NewData);
void SLL_InsertAfter(SLLNode* Head, size_t Location, ElementType NewData);
void SLL_InsertNewHead(SLLNode** Head, ElementType NewData);
void SLL_DestroyAllNodes(SLLNode** Head);
size_t SLL_GetNodeCount(SLLNode* Head);


#endif
