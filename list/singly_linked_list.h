#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int SLL_DataType;

typedef struct tagSLL_Node {
    SLL_DataType Data;
    struct tagSLL_Node *NextNode;
} SLL_Node;

typedef struct {
    SLL_Node *Head;
    SLL_Node *Tail;
    size_t Count;
} SLL;

SLL *SLL_CreateList(void);
SLL_Node *SLL_CreateNode(SLL_DataType NewData);
void SLL_AppendTail(SLL *List, SLL_DataType NewData);
void SLL_Insert(SLL *List, size_t Location, SLL_DataType NewData);
void SLL_RemoveNode(SLL *List, size_t Location);
SLL_Node *SLL_GetNodeAt(SLL *List, size_t Location);
void SLL_DestroyList(SLL *List);

size_t SLL_GetSize(SLL *List);
#endif
