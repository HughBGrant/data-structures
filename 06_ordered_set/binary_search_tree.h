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
binary_search_tree *bst_create();
bst_node *bst_create_node(int key);
void bst_insert(binary_search_tree *tree, int key);
bst_node *bst_search(binary_search_tree *tree, int key);
void bst_inorder(bst_node *node);
void bst_destroy_subtree(bst_node *node);
void bst_destroy(binary_search_tree *tree);

#endif