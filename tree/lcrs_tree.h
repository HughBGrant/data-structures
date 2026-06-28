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

void LCRST_DestroyTree(LCRST_Node *Root);
LCRST_Node *LCRST_CreateNode(LCRST_DataType NewData);
void LCRST_DestroyNode(LCRST_Node *Node);
void LCRST_AddChildNode(LCRST_Node *Parent, LCRST_Node *Child);
void LCRST_PrintTree(LCRST_Node *Node, int Depth);

#endif