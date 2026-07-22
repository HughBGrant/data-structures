#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bt_node *build_expression_tree(char *expression);
double evaluate_tree(bt_node *tree);

#endif