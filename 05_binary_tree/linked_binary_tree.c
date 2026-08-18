#include "linked_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void lbt_subtree_destroy(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    lbt_subtree_destroy(node->left);
    lbt_subtree_destroy(node->right);
    lbt_node_destroy(node);
}
lbt_node *lbt_node_create(lbt_data data)
{
    lbt_node *new_node = malloc(sizeof(lbt_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void lbt_node_destroy(lbt_node *node)
{
    free(node);
}
lbt_node *lbt_insert_left(lbt_node *parent, lbt_data data)
{
    if (parent == NULL) {
        return NULL;
    }

    lbt_node *new_child = lbt_node_create(data);
    if (new_child == NULL) {
        return NULL;
    }

    if (parent->left != NULL) {
        new_child->left = parent->left;
    }

    parent->left = new_child;

    return new_child;
}
lbt_node *lbt_insert_right(lbt_node *parent, lbt_data data)
{
    if (parent == NULL) {
        return NULL;
    }

    lbt_node *new_child = lbt_node_create(data);
    if (new_child == NULL) {
        return NULL;
    }

    if (parent->right != NULL) {
        new_child->right = parent->right;
    }

    parent->right = new_child;

    return new_child;
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