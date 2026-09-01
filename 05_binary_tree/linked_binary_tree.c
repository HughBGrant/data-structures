#include "linked_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct LNode {
    LItem data;
    struct LNode *left;
    struct LNode *right;
};
struct LinkedBinaryTree {
    LNode *root;
};
void lbt_subtree_destroy(LNode *node)
{
    if (node == NULL) {
        return;
    }
    lbt_subtree_destroy(node->left);
    lbt_subtree_destroy(node->right);
    lbt_node_destroy(node);
}
LNode *lbt_node_create(LItem data)
{
    LNode *new_node = malloc(sizeof(LNode));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void lbt_node_destroy(LNode *node)
{
    free(node);
}
LNode *lbt_set_left(LNode *parent, LItem data)
{
    if (parent == NULL) {
        return NULL;
    }

    LNode *new_child = lbt_node_create(data);
    if (new_child == NULL) {
        return NULL;
    }

    // if (parent->left != NULL) {
    //     new_child->left = parent->left;
    // }

    parent->left = new_child;

    return new_child;
}
LNode *lbt_set_right(LNode *parent, LItem data)
{
    if (parent == NULL) {
        return NULL;
    }

    LNode *new_child = lbt_node_create(data);
    if (new_child == NULL) {
        return NULL;
    }

    // if (parent->right != NULL) {
    //     new_child->right = parent->right;
    // }

    parent->right = new_child;

    return new_child;
}
LNode *lbt_left(LNode *node)
{
    return node == NULL ? NULL : node->left;
}

LNode *lbt_right(LNode *node)
{
    return node == NULL ? NULL : node->right;
}

LItem *lbt_get(LNode *node)
{
    return node == NULL ? NULL : &node->data;
}
void lbt_preorder(LNode *node)
{
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    lbt_preorder(node->left);
    lbt_preorder(node->right);
}
void lbt_inorder(LNode *node)
{
    if (node == NULL) {
        return;
    }
    lbt_inorder(node->left);
    printf("%d ", node->data);
    lbt_inorder(node->right);
}
void lbt_postorder(LNode *node)
{
    if (node == NULL) {
        return;
    }
    lbt_postorder(node->left);
    lbt_postorder(node->right);
    printf("%d ", node->data);
}