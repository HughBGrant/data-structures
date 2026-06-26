#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_LIST_STACK_H
#define	LINKED_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
typedef char *LLS_DataType;

typedef struct tagLLS_Node
{
	LLS_DataType Data;
	struct tagLLS_Node *NextNode;
} LLS_Node;

typedef struct
{
	LLS_Node *Top;
} LinkedListStack;

LinkedListStack *LLS_CreateStack(void);
void LLS_DestroyStack(LinkedListStack *Stack);
LLS_Node* LLS_CreateNode(LLS_DataType NewData);
void LLS_DestroyNode(LLS_Node* _Node);
void LLS_Push(LinkedListStack *Stack, LLS_DataType NewData);
void LLS_Pop(LinkedListStack *Stack);
LLS_DataType LLS_Top(LinkedListStack *Stack);
size_t LLS_GetSize(LinkedListStack *Stack);
bool LLS_IsEmpty(LinkedListStack *Stack);

#endif