#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char BT_DataType;

typedef struct tagBT_Node {
	struct tagBT_Node* Left;
	struct tagBT_Node* Right;
	BT_DataType Data;
} BT_Node;

typedef struct {
	BT_Node* Root;
} BinaryTree;

BinaryTree* BT_CreateTree(BT_DataType NewData);
BT_Node* BT_CreateNode(BT_DataType NewData);
void BT_InsertLeft(BT_Node* Parent, BT_Node* Child);
void BT_InsertRight(BT_Node* Parent, BT_Node* Child);
void BT_DestroySubTree(BT_Node* Node);
void BT_RemoveLeftSubTree(BT_Node* Parent);
void BT_RemoveRightSubTree(BT_Node* Parent);

void BT_PreorderPrintSubTree(BT_Node* Node);
void BT_InorderPrintSubTree(BT_Node* Node);
void BT_PostorderPrintSubTree(BT_Node* Node);
void BT_DestroyTree(BinaryTree* Tree);

#endif
