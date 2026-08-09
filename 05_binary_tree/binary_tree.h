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

void bt_subtree_destroy(bt_node *node);
bt_node *bt_node_create(bt_data data);
void bt_node_destroy(bt_node *node);

bt_node *bt_insert_left(bt_node *parent, bt_data data);
bt_node *bt_insert_right(bt_node *parent, bt_data data);

void bt_preorder(bt_node *node);
void bt_inorder(bt_node *node);
void bt_postorder(bt_node *node);

#endif