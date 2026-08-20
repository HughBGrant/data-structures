#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <stddef.h>

typedef int lbt_item;
typedef struct lbt_node lbt_node;
typedef struct linked_binary_tree lbt_binary_tree;

lbt_node *lbt_set_left(lbt_node *parent, lbt_item data);
lbt_node *lbt_set_right(lbt_node *parent, lbt_item data);
lbt_node *lbt_left(lbt_node *node);
lbt_node *lbt_right(lbt_node *node);
lbt_item lbt_data(lbt_node *node);
void lbt_preorder(lbt_node *node);
void lbt_inorder(lbt_node *node);
void lbt_postorder(lbt_node *node);

void lbt_subtree_destroy(lbt_node *node);
lbt_node *lbt_node_create(lbt_item data);
void lbt_node_destroy(lbt_node *node);

#endif