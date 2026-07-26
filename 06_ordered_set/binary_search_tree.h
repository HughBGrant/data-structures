#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bst_data;

typedef struct _bst_node {
    struct _bst_node *left;
    bst_data data;
    struct _bst_node *right;
} bst_node;

typedef struct {
    bst_node *root;
} binary_search_tree;

#endif