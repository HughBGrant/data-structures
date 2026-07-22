#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ET_DataType;

typedef struct {
    bt_node *Root;
} ET;

ET *ET_CreateTree(char *Postfix);
bt_node *ET_CreateSubTree(char *Postfix);
bt_node *ET_CreateNode(ET_DataType NewData);
void ET_PreorderPrintSubTree(bt_node *Node);
void ET_InorderPrintSubTree(bt_node *Node);
void ET_PostorderPrintSubTree(bt_node *Node);
void ET_DestroySubTree(bt_node *Root);
void ET_DestroyTree(ET *Tree);

double ET_Calculate(bt_node *Tree);

#endif