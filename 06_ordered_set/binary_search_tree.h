#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bst_data;

typedef struct _bst_node {
    bst_data key;
    struct _bst_node *left;
    struct _bst_node *right;
} bst_node;

typedef struct {
    bst_node *root;
} binary_search_tree;

binary_search_tree *bst_create();
void bst_destroy(binary_search_tree *tree);
bst_node *bst_node_create(bst_data key);
void bst_node_destroy(bst_node *node);
void bst_subtree_destroy(bst_node *node);
void bst_insert(binary_search_tree *tree, bst_data key);
bst_node *bst_node_remove(bst_node *node, bst_data key);
void bst_remove(binary_search_tree *tree, bst_data key);
bst_node *bst_search(binary_search_tree *tree, bst_data key);
bst_node *bst_min(bst_node *node);
bst_data *bst_key(bst_node *node);
void bst_inorder(bst_node *node);
void bst_print(binary_search_tree *tree);

#endif