#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char LCRST_DataType;

typedef struct tagLCRST_Node
{
	struct tagLCRST_Node *LeftChild;
	struct tagLCRST_Node *RightSibling;
	LCRST_DataType Data;
} LCRST_Node;

typedef struct
{
	LCRST_Node *Root;
	size_t Count;
} LCRSTree;

LCRSTree *LCRST_CreateTree(LCRST_Node *Root);
void LCRST_DestroyTree(LCRSTree *Tree);
void LCRST_RemoveNode(LCRST_Node *Root);
LCRST_Node *LCRST_CreateNode(LCRST_DataType NewData);
void LCRST_AddChildNode(LCRST_Node *Parent, LCRST_Node *Child);
void LCRST_PrintTree(LCRST_Node *Node, size_t Depth);

#endif