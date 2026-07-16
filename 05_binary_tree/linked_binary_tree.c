#include "linked_binary_tree.h"

linked_binary_tree *lbt_create()
{
    linked_binary_tree *tree = malloc(sizeof(linked_binary_tree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;

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
lbt_node *lbt_set_root(linked_binary_tree *tree, lbt_data data)
{
    if (tree == NULL) {
        return NULL;
    }
    lbt_node *root = lbt_create_node(data);
    if (root == NULL) {
        return NULL;
    }
    tree->root = root;
    return tree->root;
}
lbt_node *lbt_add_left(lbt_node *parent, lbt_data data)
{
    if (parent == NULL || parent->left) {
        return NULL;
    }
    lbt_node *left = lbt_create_node(data);
    if (left == NULL) {
        return NULL;
    }
    parent->left = left;
    return parent->left;
}
lbt_node *lbt_add_right(lbt_node *parent, lbt_data data)
{
    if (parent == NULL || parent->right) {
        return NULL;
    }
    lbt_node *right = lbt_create_node(data);
    if (right == NULL) {
        return NULL;
    }
    parent->right = right;
    return parent->right;
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
