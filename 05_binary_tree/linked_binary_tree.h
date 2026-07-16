#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char lbt_data;

typedef struct _lbt_node {
    lbt_data data;
    struct _lbt_node *left;
    struct _lbt_node *right;
} lbt_node;

typedef struct {
    lbt_node *root;
} linked_binary_tree;

linked_binary_tree *lbt_create();
lbt_node *lbt_create_node(lbt_data data);
lbt_node *lbt_set_root(linked_binary_tree *tree, lbt_data data);
lbt_node *lbt_add_left(lbt_node *parent, lbt_data data);
lbt_node *lbt_add_right(lbt_node *parent, lbt_data data);
void lbt_destroy_subtree(lbt_node *node);
void lbt_delete_left(lbt_node *parent);
void lbt_delete_right(lbt_node *parent);

void lbt_preorder(lbt_node *node);
void lbt_inorder(lbt_node *node);
void lbt_postorder(lbt_node *node);
void lbt_destroy(linked_binary_tree *tree);

#endif