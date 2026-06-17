#ifndef ARRAY_STACK_H
#define	ARRAY_STACK_H

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
} ArrayStack;




#endif // !ARRAY_STACK_H
