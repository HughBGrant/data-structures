#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	*Stack = malloc(sizeof(LinkedListStack));

	if (*Stack != NULL)
	{
		(*Stack)->Top = NULL;
	}
}
void LLS_DestroyStack(LinkedListStack* Stack)
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
Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		return NULL;
	}
	NewNode->Data = malloc(strlen(NewData) + 1);

	if (NewNode->Data == NULL)
	{
		free(NewNode);
		return NULL;
	}
	strcpy(NewNode->Data, NewData);
	NewNode->NextNode = NULL;
	
	return NewNode;
}
void LLS_DestroyNode(Node* Node)
{
	if (Node == NULL)
	{
		return;
	}

	free(Node->Data);
	free(Node);
}
void LLS_Push(LinkedListStack* Stack, char* NewData)
{
	Node* NewNode = LLS_CreateNode(NewData);

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
	Node* TopNode = Stack->Top;

	Stack->Top = TopNode->NextNode;
	
	LLS_DestroyNode(TopNode);
}
char* LLS_Top(LinkedListStack* Stack)
{
	if (Stack->Top == NULL)
	{
		return NULL;
	}
	return Stack->Top->Data;
}
size_t LLS_GetCount(LinkedListStack* Stack)
{
	size_t Count = 0;
	Node* Current = Stack->Top;

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
