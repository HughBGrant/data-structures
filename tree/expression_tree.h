#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ET_DataType;

typedef struct tagET_Node
{
    struct tagET_Node *Left;
    struct tagET_Node *Right;
    ET_DataType Data;

} ET_Node;

typedef struct
{
    ET_Node *Root;
} ExpressionTree;

// ExpressionTree ET_CreateTree(ET_DataType NewData);
ET_Node *ET_CreateNode(ET_DataType NewData);



void ET_PreorderPrintTree(ET_Node *Node);
void ET_InorderPrintTree(ET_Node *Node);
void ET_PostorderPrintTree(ET_Node *Node);
void ET_DestroyTree(ET_Node *Root);
void ET_BuildExpressionTree(char *PostfixExpression, ET_Node **Node);
double ET_Evaluate(ET_Node *Tree);
// void ET_DestroyTree(ExpressionTree Tree);

#endif