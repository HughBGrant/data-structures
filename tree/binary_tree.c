#include "binary_tree.h"

BinaryTree *BT_CreateTree(BT_DataType NewData)
{
	BinaryTree *Tree = malloc(sizeof(BinaryTree));
	if (Tree == NULL)
	{
		return NULL;
	}

	Tree->Root = BT_CreateNode(NewData);
	if (Tree->Root == NULL)
	{
		free(Tree);
		return NULL;
	}
	
	return Tree;
}
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
void BT_PreorderPrintSubTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	printf(" %c", Node->Data);
	BT_PreorderPrintSubTree(Node->Left);
	BT_PreorderPrintSubTree(Node->Right);
}
void BT_InorderPrintSubTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	BT_InorderPrintSubTree(Node->Left);
	printf(" %c", Node->Data);
	BT_InorderPrintSubTree(Node->Right);
}
void BT_PostorderPrintSubTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	BT_PostorderPrintSubTree(Node->Left);
	BT_PostorderPrintSubTree(Node->Right);
	printf(" %c", Node->Data);
}
void BT_DestroyTree(BinaryTree *Tree)
{
	if (Tree == NULL)
	{
		return;
	}
	BT_DestroySubTree(Tree->Root);
	free(Tree);
}
