#include "linked_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct lbt_node {
    lbt_item data;
    struct lbt_node *left;
    struct lbt_node *right;
};
struct linked_binary_tree {
    lbt_node *root;
};
void lbt_subtree_destroy(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    lbt_subtree_destroy(node->left);
    lbt_subtree_destroy(node->right);
    lbt_node_destroy(node);
}
lbt_node *lbt_node_create(lbt_item value)
{
    lbt_node *new_node = malloc(sizeof(lbt_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void lbt_node_destroy(lbt_node *node)
{
    free(node);
}
lbt_node *lbt_set_left(lbt_node *parent, lbt_item value)
{
    if (parent == NULL) {
        return NULL;
    }

    lbt_node *new_child = lbt_node_create(value);
    if (new_child == NULL) {
        return NULL;
    }

    // if (parent->left != NULL) {
    //     new_child->left = parent->left;
    // }

    parent->left = new_child;

    return new_child;
}
lbt_node *lbt_set_right(lbt_node *parent, lbt_item value)
{
    if (parent == NULL) {
        return NULL;
    }

    lbt_node *new_child = lbt_node_create(value);
    if (new_child == NULL) {
        return NULL;
    }

    // if (parent->right != NULL) {
    //     new_child->right = parent->right;
    // }

    parent->right = new_child;

    return new_child;
}
lbt_node *lbt_left(lbt_node *node)
{
    return node == NULL ? NULL : node->left;
}

lbt_node *lbt_right(lbt_node *node)
{
    return node == NULL ? NULL : node->right;
}

lbt_item *lbt_get(lbt_node *node)
{
    return node == NULL ? NULL : &node->data;
}
void lbt_preorder(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    lbt_preorder(node->left);
    lbt_preorder(node->right);
}
void lbt_inorder(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    lbt_inorder(node->left);
    printf("%d ", node->data);
    lbt_inorder(node->right);
}
void lbt_postorder(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    lbt_postorder(node->left);
    lbt_postorder(node->right);
    printf("%d ", node->data);
}