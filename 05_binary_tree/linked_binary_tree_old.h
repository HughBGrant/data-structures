#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char lbto_data;

typedef struct _lbto_node {
    struct _lbto_node *left;
    struct _lbto_node *right;
    lbto_data data;
} lbto_node;

typedef struct {
    lbto_node *root;
} linked_binary_tree_old;

linked_binary_tree_old *lbto_create(lbto_data data);
lbto_node *lbto_create_node(lbto_data data);
void lbto_insert_left(lbto_node *parent, lbto_node *child);
void lbto_insert_right(lbto_node *parent, lbto_node *child);
void lbto_destroy_subtree(lbto_node *node);
void lbto_delete_left(lbto_node *parent);
void lbto_delete_right(lbto_node *parent);

void lbto_preorder(lbto_node *node);
void lbto_inorder(lbto_node *node);
void lbto_postorder(lbto_node *node);
void lbto_destroy(linked_binary_tree_old *tree);

#endif