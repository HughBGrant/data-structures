#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char BT_DataType;

typedef struct tagBT_Node
{
	struct tagBT_Node *Left;
	struct tagBT_Node *Right;
	BT_DataType Data;
} BT_Node;

typedef struct
{
	BT_Node *Root;
	size_t Count;
} BinaryTree;

//BinaryTree *BT_CreateTree(BT_DataType NewData);
//void BT_DestroyTree(BinaryTree *Tree);
void BT_DestroyTree(BT_Node *Node);
BT_Node *BT_CreateNode(BT_DataType NewData);
void BT_PreorderPrintTree(BT_Node *Node);
void BT_InorderPrintTree(BT_Node *Node);
void BT_PostorderPrintTree(BT_Node *Node);


#endif