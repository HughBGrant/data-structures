#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <stddef.h>

typedef int lbt_item;

typedef struct _lbt_node {
    lbt_item data;
    struct _lbt_node *left;
    struct _lbt_node *right;
} lbt_node;

lbt_node *lbt_insert_left(lbt_node *parent, lbt_item data);
lbt_node *lbt_insert_right(lbt_node *parent, lbt_item data);
void lbt_preorder(lbt_node *node);
void lbt_inorder(lbt_node *node);
void lbt_postorder(lbt_node *node);

void lbt_subtree_destroy(lbt_node *node);
lbt_node *lbt_node_create(lbt_item data);
void lbt_node_destroy(lbt_node *node);

#endif