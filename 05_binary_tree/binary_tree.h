#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bt_data;

typedef struct _bt_node {
    bt_data data;
    struct _bt_node *left;
    struct _bt_node *right;
} bt_node;

typedef struct {
    bt_node *root;
} binary_tree;

binary_tree *bt_create();
bt_node *bt_create_node(bt_data data);
bt_node *bt_set_root(binary_tree *tree, bt_data data);
bt_node *bt_add_left(bt_node *parent, bt_data data);
bt_node *bt_add_right(bt_node *parent, bt_data data);

void bt_preorder(bt_node *node);
void bt_inorder(bt_node *node);
void bt_postorder(bt_node *node);
void bt_destroy_subtree(bt_node *node);
void bt_destroy(binary_tree *tree);

#endif