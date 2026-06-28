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

typedef struct
{
    CDLL_Node *Head;
    CDLL_Node *Tail;
    size_t Count;
} CircularDoublyLinkedList;

CircularDoublyLinkedList *CDLL_CreateList(void);
void CDLL_DestroyList(CircularDoublyLinkedList *List);
CDLL_Node *CDLL_CreateNode(CDLL_DataType NewData);
void CDLL_DestroyNode(CDLL_Node *Node);
void CDLL_AppendTail(CircularDoublyLinkedList *List, CDLL_DataType NewData);
size_t CDLL_GetSize(CircularDoublyLinkedList *List);
CDLL_Node *CDLL_GetNodeAt(CircularDoublyLinkedList *List, size_t Location);
void CDLL_InsertAfter(CircularDoublyLinkedList *List, size_t Location, CDLL_DataType NewData);
void CDLL_RemoveNode(CircularDoublyLinkedList *List, size_t Location);

#endif
