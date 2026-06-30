#include "binary_tree.h"

//BinaryTree *BT_CreateTree(BT_DataType NewData)
//{
//	BinaryTree *Tree = malloc(sizeof(BinaryTree));
//	if (Tree == NULL)
//	{
//		return NULL;
//	}
//	Tree->Root = BT_CreateNode(NewData);
//	Tree->Count = 1;
//
//	return Tree;
//}
void BT_DestroyTree(BT_Node *Node)
{
	if (Node == NULL)
	{
		return;
	}
	BT_DestroyTree(Node->Left);
	BT_DestroyTree(Node->Right);
	free(Node);
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
	BT_InorderPrintTree(Node->Left);
	BT_InorderPrintTree(Node->Right);
	printf(" %c", Node->Data);
}

//void BT_DestroySubTree(BT_Node *SubTree)
//{
//	if (SubTree == NULL)
//	{
//		return;
//	}
//	BT_Node *Child = SubTree->Child;
//	while (Child != NULL)
//	{
//		BT_Node *Next = Child->Sibling;
//		BT_DestroySubTree(Child);
//		Child = Next;
//	}
//	free(SubTree);
//}
//void BT_AddChild(BinaryTree *Tree, BT_Node *Parent, BT_Node *Child)
//{
//	if (Tree == NULL || Parent == NULL || Child == NULL)
//	{
//		return;
//	}
//	if (Parent->Child == NULL)
//	{
//		Parent->Child = Child;
//	}
//	else
//	{
//		BT_Node *Previous = Parent->Child;
//		while (Previous->Sibling != NULL)
//		{
//			Previous = Previous->Sibling;
//		}
//		Previous->Sibling = Child;
//	}
//	Tree->Count++;
//}
//void BT_RemoveSubTree(BinaryTree *SubTree, BT_Node *Parent, BT_Node *Target)
//{
//	if (SubTree == NULL || Target == NULL)
//	{
//		return;
//	}
//	if (SubTree->Root == Target)
//	{
//		SubTree->Count -= BT_GetSubTreeSize(Target);
//
//		BT_DestroySubTree(Target);
//
//		SubTree->Root = NULL;
//
//		return;
//	}
//
//	if (Parent == NULL)
//		return;
//
//	if (Parent->Child == Target)
//	{
//		Parent->Child = Target->Sibling;
//	}
//	else
//	{
//		BT_Node *Prev = Parent->Child;
//
//		while (Prev != NULL &&
//			Prev->Sibling != Target)
//		{
//			Prev = Prev->Sibling;
//		}
//
//		if (Prev == NULL)
//			return;
//
//		Prev->Sibling = Target->Sibling;
//	}
//
//	Target->Sibling = NULL;
//
//	SubTree->Count -= BT_GetSubTreeSize(Target);
//
//	BT_DestroySubTree(Target);
//}
//size_t BT_GetSubTreeSize(BT_Node *SubTree)
//{
//	if (SubTree == NULL)
//		return 0;
//
//	size_t Count = 1;
//
//	BT_Node *Child = SubTree->Child;
//
//	while (Child != NULL)
//	{
//		Count += BT_GetSubTreeSize(Child);
//		Child = Child->Sibling;
//	}
//	return Count;
//}
//void BT_PrintSubTree(BT_Node *SubTree, size_t Depth)
//{
//	for (size_t i = 1; i < Depth; i++)
//	{
//		printf("   ");
//	}
//	if (Depth > 0)
//	{
//		printf("+--");
//	}
//	printf("%c\n", SubTree->Data);
//
//	if (SubTree->Child != NULL)
//	{
//		BT_PrintSubTree(SubTree->Child, Depth + 1);
//	}
//	if (SubTree->Sibling != NULL)
//	{
//		BT_PrintSubTree(SubTree->Sibling, Depth);
//	}
//}