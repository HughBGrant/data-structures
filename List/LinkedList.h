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

typedef struct
{
    SLL_Node *Head;
    SLL_Node *Tail;
    size_t Count;
} LinkedList;

LinkedList *SLL_CreateList(void);
void SLL_DestroyList(LinkedList *List);
SLL_Node *SLL_CreateNode(SLL_DataType NewData);
void SLL_DestroyNode(SLL_Node *Node);
void SLL_AppendTail(LinkedList *List, SLL_DataType NewData);
void SLL_AppendHead(LinkedList *List, SLL_DataType NewData);
SLL_Node *SLL_GetNodeAt(LinkedList *List, size_t Location);
void SLL_RemoveNode(LinkedList *List, size_t Location);
void SLL_InsertBefore(LinkedList *List, size_t Location, SLL_DataType NewData);
void SLL_InsertAfter(LinkedList *List, size_t Location, SLL_DataType NewData);
size_t SLL_GetSize(LinkedList *List);

#endif
