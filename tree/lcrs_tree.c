#include "lcrs_tree.h"

LCRSTree *LCRST_CreateTree(LCRST_DataType NewData)
{
	LCRSTree *Tree = malloc(sizeof(LCRSTree));
	if (Tree == NULL)
	{
		return NULL;
	}

	LCRST_Node *NewNode = LCRST_CreateNode(NewData);
	if (NewNode == NULL)
	{
		free(Tree);
		return NULL;
	}

	Tree->Root = NewNode;

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
		LCRST_DestroySubTree(Tree->Root);
	}
	free(Tree);
}
LCRST_Node *LCRST_CreateNode(LCRST_DataType NewData)
{
	LCRST_Node *NewNode = malloc(sizeof(LCRST_Node));

	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Data = NewData;
	NewNode->Child = NULL;
	NewNode->Sibling = NULL;

	return NewNode;
}
void LCRST_DestroySubTree(LCRST_Node *SubTree) ////////
{
	if (SubTree == NULL)
	{
		return;
	}
	LCRST_Node *Child = SubTree->Child;
	while (Child != NULL)
	{
		LCRST_Node *Next = Child->Sibling;
		LCRST_DestroySubTree(Child);
		Child = Next;
	}
	free(SubTree);
}
void LCRST_AddChild(LCRST_Node *Parent, LCRST_Node *Child)
{
	if (Parent == NULL || Child == NULL)
	{
		return;
	}
	if (Parent->Child == NULL)
	{
		Parent->Child = Child;
	}
	else
	{
		LCRST_Node *Previous = Parent->Child;
		while (Previous->Sibling != NULL)
		{
			Previous = Previous->Sibling;
		}
		Previous->Sibling = Child;
	}
}
void LCRST_RemoveSubTree(LCRSTree *Tree, LCRST_Node *Parent, LCRST_Node *SubTree) //////
{
	if (Tree == NULL || SubTree == NULL)
	{
		return;
	}
	if (Tree->Root == SubTree)
	{
		LCRST_DestroySubTree(SubTree);

		Tree->Root = NULL;

		return;
	}

	if (Parent == NULL)
		return;

	if (Parent->Child == SubTree)
	{
		Parent->Child = SubTree->Sibling;
	}
	else
	{
		LCRST_Node *Prev = Parent->Child;

		while (Prev != NULL &&
			Prev->Sibling != SubTree)
		{
			Prev = Prev->Sibling;
		}

		if (Prev == NULL)
			return;

		Prev->Sibling = SubTree->Sibling;
	}

	SubTree->Sibling = NULL;

	LCRST_DestroySubTree(SubTree);
}
size_t LCRST_GetSubTreeSize(LCRST_Node *SubTree) ////////
{
	if (SubTree == NULL)
		return 0;

	size_t Count = 1;

	LCRST_Node *Child = SubTree->Child;

	while (Child != NULL)
	{
		Count += LCRST_GetSubTreeSize(Child);
		Child = Child->Sibling;
	}
	return Count;
}
void LCRST_PrintSubTree(LCRST_Node *SubTree, size_t Depth)
{
	for (size_t i = 1; i < Depth; i++)
	{
		printf("   ");
	}
	if (Depth > 0)
	{
		printf("+--");
	}
	printf("%c\n", SubTree->Data);

	if (SubTree->Child != NULL)
	{
		LCRST_PrintSubTree(SubTree->Child, Depth + 1);
	}
	if (SubTree->Sibling != NULL)
	{
		LCRST_PrintSubTree(SubTree->Sibling, Depth);
	}
}