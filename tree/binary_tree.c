#include "binary_tree.h"

BT_Node *BT_CreateNode(BT_DataType NewData)
{
	BT_Node *NewNode = malloc(sizeof(BT_Node));

	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Data = NewData;
	NewNode->Left = NULL;
	NewNode->Right = NULL;

	return NewNode;
}
void BT_InsertLeft(BT_Node *Parent, BT_Node *Child)
{
	if (Parent == NULL || Child == NULL || Parent->Left != NULL)
	{
		return;
	}
	Parent->Left = Child;
}
void BT_InsertRight(BT_Node *Parent, BT_Node *Child)
{
	if (Parent == NULL || Child == NULL || Parent->Right != NULL)
	{
		return;
	}
	Parent->Right = Child;
}
void BT_DestroySubTree(BT_Node *SubTree)
{
	if (SubTree == NULL)
	{
		return;
	}
	BT_DestroySubTree(SubTree->Left);
	BT_DestroySubTree(SubTree->Right);
	free(SubTree);
}
void BT_RemoveLeftSubTree(BT_Node *Parent)
{
	if (Parent == NULL)
	{
		return;
	}
	BT_DestroySubTree(Parent->Left);
}
void BT_RemoveRightSubTree(BT_Node *Parent)
{
	if (Parent == NULL)
	{
		return;
	}
	BT_DestroySubTree(Parent->Right);
}
void BT_PreorderPrintTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	printf(" %c", Node->Data);
	BT_PreorderPrintTree(Node->Left);
	BT_PreorderPrintTree(Node->Right);
}
void BT_InorderPrintTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	BT_InorderPrintTree(Node->Left);
	printf(" %c", Node->Data);
	BT_InorderPrintTree(Node->Right);
}
void BT_PostorderPrintTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	BT_PostorderPrintTree(Node->Left);
	BT_PostorderPrintTree(Node->Right);
	printf(" %c", Node->Data);
}
