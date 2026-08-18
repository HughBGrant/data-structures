#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "linked_binary_tree.h"
#include <stddef.h>

lbt_node *build(char *expression);
double evaluate(lbt_node *tree);

#endif