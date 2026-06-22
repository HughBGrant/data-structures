#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	*Stack = malloc(sizeof(LinkedListStack));
	if (*Stack != NULL)
	{
		(*Stack)->List = NULL;
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
	return;
}
Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = malloc(sizeof(Node));
	if (NewNode != NULL)
	{
		NewNode->Data = malloc(strlen(NewData) + 1);
		if (NewNode->Data != NULL)
		{
			strcpy(NewNode->Data, NewData);

			NewNode->NextNode = NULL;

		}
	}
	return NewNode;
}
void LLS_DestroyNode(Node* Node)
{
	free(Node->Data);
	free(Node);
}
void LLS_Push(LinkedListStack* Stack, char* NewData)
{
	Node* NewNode = LLS_CreateNode(NewData);
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}
	Stack->Top = NewNode;
}
void LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		Stack->Top = CurrentTop;

		if (Stack->Top != NULL)
		{
			Stack->Top->NextNode = NULL;
		}
	}
	LLS_DestroyNode(TopNode);
	return;
}
char* LLS_Top(LinkedListStack* Stack)
{
	if (Stack->Top == NULL)
	{
		return NULL;
	}
	return Stack->Top->Data;
}
int LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}
int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List) == NULL;
}
