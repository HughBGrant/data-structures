#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack **Stack)
{
	*Stack = malloc(sizeof(LinkedListStack));

	if (*Stack == NULL)
	{
		return;
	}
	(*Stack)->Top = NULL;
}
void LLS_DestroyStack(LinkedListStack *Stack)
{
	if (Stack == NULL)
	{
		return;
	}
	while (!LLS_IsEmpty(Stack))
	{
		LLS_Pop(Stack);
	}
	free(Stack);
}
LLS_Node *LLS_CreateNode(LLS_DataType NewData)
{
	LLS_Node *NewNode = malloc(sizeof(LLS_Node));

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
void LLS_DestroyNode(LLS_Node* Node)
{
	if (Node == NULL)
	{
		return;
	}
	free(Node->Data);
	free(Node);
}
void LLS_Push(LinkedListStack* Stack, LLS_DataType NewData)
{
	LLS_Node *NewNode = LLS_CreateNode(NewData);

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
void LLS_Pop(LinkedListStack* Stack)
{
	if (Stack == NULL || Stack->Top == NULL)
	{
		return;
	}
	LLS_Node *TopNode = Stack->Top;

	Stack->Top = TopNode->NextNode;

	LLS_DestroyNode(TopNode);
}
LLS_DataType LLS_Top(LinkedListStack* Stack)
{
	if (Stack->Top == NULL)
	{
		return NULL;
	}
	return Stack->Top->Data;
}
size_t LLS_GetSize(LinkedListStack* Stack)
{
	size_t Count = 0;
	LLS_Node *Current = Stack->Top;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}
bool LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->Top) == NULL;
}
