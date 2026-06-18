#ifndef LINKED_LIST_STACK_H
#define	LINKED_LIST_STACK_H

#include <stdio.h>
#include <stdlib.h>

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

#endif