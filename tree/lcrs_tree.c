#include "lcrs_tree.h"

void LCRST_DestroyTree(LCRST_Node *Root)
{
	if (Root->RightSibling != NULL)
	{
		LCRST_DestroyTree(Root->RightSibling);
	}
	if (Root->LeftChild != NULL)
	{
		LCRST_DestroyTree(Root->LeftChild);
	}
	LCRST_DestroyNode(Root);
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
void LCRST_DestroyNode(LCRST_Node *Node)
{
	free(Node);
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
void LCRST_PrintTree(LCRST_Node *Node, int Depth)
{
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
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