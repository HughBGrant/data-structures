#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
typedef int LL_DataType;

typedef struct tagLL_Node
{
    LL_DataType Data;
    struct tagLL_Node *NextNode;
} LL_Node;

typedef struct
{
    LL_Node *Head;
    LL_Node *Tail;
    size_t Count;
} LinkedList;

LinkedList *LL_CreateList(void);
LL_Node *LL_CreateNode(LL_DataType NewData);
void LL_AppendTail(LinkedList *List, LL_DataType NewData);
void LL_AppendHead(LinkedList *List, LL_DataType NewData);
void LL_InsertAt(LinkedList *List, size_t Location, LL_DataType NewData);
void LL_RemoveNode(LinkedList *List, size_t Location);
LL_Node *LL_GetNodeAt(LinkedList *List, size_t Location);
void LL_DestroyList(LinkedList *List);

size_t LL_GetSize(LinkedList *List);
#endif
