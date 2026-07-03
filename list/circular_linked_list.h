#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int CLL_DataType;

typedef struct tagCLL_Node {
    CLL_DataType Data;
    struct tagCLL_Node *PrevNode;
    struct tagCLL_Node *NextNode;
} CLL_Node;

typedef struct {
    CLL_Node *Head;
    CLL_Node *Tail;
    size_t Count;
} CircularLinkedList;

CircularLinkedList *CLL_CreateList(void);
CLL_Node *CLL_CreateNode(CLL_DataType NewData);
void CLL_AppendTail(CircularLinkedList *List, CLL_DataType NewData);
void CLL_Insert(CircularLinkedList *List, size_t Location,
                CLL_DataType NewData);
void CLL_RemoveNode(CircularLinkedList *List, size_t Location);
CLL_Node *CLL_GetNodeAt(CircularLinkedList *List, size_t Location);

void CLL_DestroyList(CircularLinkedList *List);

size_t CLL_GetSize(CircularLinkedList *List);

#endif
