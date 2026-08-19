#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

typedef int bst_item;

typedef struct _bst_node {
    bst_item key;
    struct _bst_node *left;
    struct _bst_node *right;
} bst_node;

struct binary_search_tree {
    bst_node *root;
};

typedef struct binary_search_tree bst_ordered_set;

bst_node *bst_node_insert(bst_node *node, bst_item key);
bst_node *bst_node_remove(bst_node *node, bst_item key);
bst_node *bst_search(bst_node *node, bst_item key);
bst_node *bst_find_min(bst_node *node);
bst_item *bst_key(bst_node *node);
void bst_inorder(bst_node *node);

bst_node *bst_node_create(bst_item key);
void bst_node_destroy(bst_node *node);
void bst_subtree_destroy(bst_node *node);

#endif