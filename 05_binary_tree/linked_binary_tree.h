#ifndef LINKED_BINARY_TREE_H
#define LINKED_BINARY_TREE_H

#include <stddef.h>

typedef int LItem;
typedef struct LNode LNode;
typedef struct LinkedBinaryTree LBinaryTree;

LNode *lbt_set_left(LNode *parent, LItem value);
LNode *lbt_set_right(LNode *parent, LItem value);
LNode *lbt_left(LNode *node);
LNode *lbt_right(LNode *node);
LItem *lbt_get(LNode *node);
void lbt_preorder(LNode *node);
void lbt_inorder(LNode *node);
void lbt_postorder(LNode *node);

void lbt_subtree_destroy(LNode *node);
LNode *lbt_node_create(LItem value);
void lbt_node_destroy(LNode *node);

#endif