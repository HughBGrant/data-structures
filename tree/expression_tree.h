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

ET_Node *ET_CreateTree(char *Postfix);
ET_Node *ET_CreateNode(ET_DataType NewData);
void ET_PreorderPrintSubTree(ET_Node *Node);
void ET_InorderPrintSubTree(ET_Node *Node);
void ET_PostorderPrintSubTree(ET_Node *Node);
void ET_DestroyTree(ET_Node *Root);

double ET_Evaluate(ET_Node *Tree);

#endif