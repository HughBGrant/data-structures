#include "lcrs_tree.h"

LCRSTree *LCRST_CreateTree(LCRST_Node *Root)
{
	LCRSTree *Tree = malloc(sizeof(LCRSTree));

	if (Tree == NULL)
	{
		return NULL;
	}
	Tree->Root = Root;
	Tree->Count =(Root != NULL) ? 1 : 0;

	return Tree;
}
void LCRST_DestroyTree(LCRSTree *Tree)
{
	if (Tree == NULL)
	{
		return;
	}
	if (Tree->Root != NULL)
	{
		LCRST_RemoveNode(Tree->Root);
	}
	free(Tree);
}
void LCRST_RemoveNode(LCRST_Node *Root)
{
	if (Root == NULL)
	{
		return;
	}
	LCRST_RemoveNode(Root->RightSibling);
	LCRST_RemoveNode(Root->LeftChild);
	
	free(Root);
}
LCRST_Node *LCRST_CreateNode(LCRST_DataType NewData)
{
	LCRST_Node *NewNode = malloc(sizeof(LCRST_Node));

	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;

	return NewNode;
}
void LCRST_AddChildNode(LCRST_Node *Parent, LCRST_Node *Child)
{
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
	}
	else
	{
		LCRST_Node *Previous = Parent->LeftChild;
		while (Previous->RightSibling != NULL)
		{
			Previous = Previous->RightSibling;
		}
		Previous->RightSibling = Child;
	}
}

void LCRST_PrintTree(LCRST_Node *Node, size_t Depth)
{
	for (size_t i = 1; i < Depth; i++)
	{
		printf("   ");
	}
	if (Depth > 0)
	{
		printf("+--");
	}
	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
	{
		LCRST_PrintTree(Node->LeftChild, Depth + 1);
	}
	if (Node->RightSibling != NULL)
	{
		LCRST_PrintTree(Node->RightSibling, Depth);
	}
}