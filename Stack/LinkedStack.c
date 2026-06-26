#include "LinkedStack.h"

LinkedStack *LS_CreateStack(void)
{
	LinkedStack *Stack = malloc(sizeof(LinkedStack));

	if (Stack == NULL)
	{
		return NULL;
	}
	Stack->Top = NULL;

	return Stack;
}
void LS_DestroyStack(LinkedStack *Stack)
{
	if (Stack == NULL)
	{
		return;
	}
	while (!LS_IsEmpty(Stack))
	{
		LS_Pop(Stack);
	}
	free(Stack);
}
LS_Node *LS_CreateNode(LS_DataType NewData)
{
	LS_Node *NewNode = malloc(sizeof(LS_Node));

	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Data = malloc(strlen(NewData) + 1);

	if (NewNode->Data == NULL)
	{
		free(NewNode); // 데이터가 아닌 노드 해제
		return NULL;
	}
	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL;

	return NewNode;
}
void LS_DestroyNode(LS_Node* Node)
{
	if (Node == NULL)
	{
		return;
	}
	free(Node->Data);
	free(Node);
}
void LS_Push(LinkedStack* Stack, LS_DataType NewData)
{
	LS_Node *NewNode = LS_CreateNode(NewData);

	if (NewNode == NULL)
	{
		return;
	}
	if (Stack->Top == NULL)
	{
		Stack->Top = NewNode;
	}
	else
	{
		NewNode->NextNode = Stack->Top;
	}
	Stack->Top = NewNode;
}
void LS_Pop(LinkedStack* Stack)
{
	if (Stack == NULL || Stack->Top == NULL)
	{
		return;
	}
	LS_Node *TopNode = Stack->Top;

	Stack->Top = TopNode->NextNode;

	LS_DestroyNode(TopNode);
}
LS_DataType LS_Top(LinkedStack* Stack)
{
	if (Stack->Top == NULL)
	{
		return NULL;
	}
	return Stack->Top->Data;
}
size_t LS_GetSize(LinkedStack* Stack)
{
	size_t Count = 0;
	LS_Node *Current = Stack->Top;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}
bool LS_IsEmpty(LinkedStack* Stack)
{
	return (Stack->Top) == NULL;
}
