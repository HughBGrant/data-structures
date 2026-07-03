#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char LCRST_DataType;

typedef struct tagLCRST_Node {
    struct tagLCRST_Node *Child;
    struct tagLCRST_Node *Sibling;
    LCRST_DataType Data;
} LCRST_Node;

typedef struct {
    LCRST_Node *Root;
} LCRST;

LCRST *LCRST_CreateTree(LCRST_DataType NewData);
LCRST_Node *LCRST_CreateNode(LCRST_DataType NewData);
void LCRST_AddChild(LCRST_Node *Parent, LCRST_Node *Child);
void LCRST_RemoveSubTree(LCRST *Tree, LCRST_Node *Parent, LCRST_Node *SubTree);

void LCRST_PrintSubTree(LCRST_Node *SubTree, size_t Depth);
void LCRST_DestroyTree(LCRST *Tree);

void LCRST_DestroySubTree(LCRST_Node *SubTree);
size_t LCRST_GetSubTreeSize(LCRST_Node *SubTree);

#endif