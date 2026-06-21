#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_LIST_STACK_H
#define	LINKED_LIST_STACK_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);
Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* _Node);
void LLS_Push(LinkedListStack* Stack, char* NewData);
void LLS_Pop(LinkedListStack* Stack);
char* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

#endif