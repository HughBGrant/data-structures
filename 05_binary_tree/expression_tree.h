#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "linked_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lbt_node *build(char *expression);
double evaluate(lbt_node *tree);

#endif