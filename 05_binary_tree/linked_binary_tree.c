#include "linked_binary_tree.h"

linked_binary_tree *lbt_create(lbt_data data)
{
    linked_binary_tree *tree = malloc(sizeof(linked_binary_tree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = lbt_create_node(data);
    if (tree->root == NULL) {
        free(tree);
        return NULL;
    }

    return tree;
}
lbt_node *lbt_create_node(lbt_data data)
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
void lbt_insert_left(lbt_node *parent, lbt_node *child)
{
    if (parent == NULL || child == NULL || parent->left) {
        return;
    }
    parent->left = child;
}
void lbt_insert_right(lbt_node *parent, lbt_node *child)
{
    if (parent == NULL || child == NULL || parent->right) {
        return;
    }
    parent->right = child;
}
void lbt_destroy_subtree(lbt_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    lbt_destroy_subtree(subtree->left);
    lbt_destroy_subtree(subtree->right);
    free(subtree);
}
void lbt_delete_left(lbt_node *parent)
{
    if (parent == NULL) {
        return;
    }
    lbt_destroy_subtree(parent->left);
}
void lbt_delete_right(lbt_node *parent)
{
    if (parent == NULL) {
        return;
    }
    lbt_destroy_subtree(parent->right);
}
void lbt_preorder(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    printf(" %c", node->data);
    lbt_preorder(node->left);
    lbt_preorder(node->right);
}
void lbt_inorder(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    lbt_inorder(node->left);
    printf(" %c", node->data);
    lbt_inorder(node->right);
}
void lbt_postorder(lbt_node *node)
{
    if (node == NULL) {
        return;
    }
    lbt_postorder(node->left);
    lbt_postorder(node->right);
    printf(" %c", node->data);
}
void lbt_destroy(linked_binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    lbt_destroy_subtree(tree->root);
    free(tree);
}
