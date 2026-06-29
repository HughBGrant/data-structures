#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char LCRST_DataType;

typedef struct tagLCRST_Node
{
	struct tagLCRST_Node *Child;
	struct tagLCRST_Node *Sibling;
	LCRST_DataType Data;
} LCRST_Node;

typedef struct
{
	LCRST_Node *Root;
	size_t Count;
} LCRSTree;

LCRSTree *LCRST_CreateTree(LCRST_DataType NewData);
void LCRST_DestroyTree(LCRSTree *Tree);
LCRST_Node *LCRST_CreateNode(LCRST_DataType NewData);
void LCRST_DestroySubTree(LCRST_Node *Root);
void LCRST_AddChild(LCRSTree *Tree, LCRST_Node *Parent, LCRST_Node *Child);
void LCRST_RemoveSubTree(LCRSTree *Tree, LCRST_Node *Parent, LCRST_Node *Target);
size_t LCRST_GetSubTreeSize(LCRST_Node *Node);
void LCRST_PrintSubTree(LCRST_Node *Node, size_t Depth);

#endif