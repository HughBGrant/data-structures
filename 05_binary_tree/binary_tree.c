#include "binary_tree.h"

binary_tree *bt_create()
{
    binary_tree *tree = malloc(sizeof(binary_tree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;

    return tree;
}
bt_node *bt_create_node(bt_data data)
{
    bt_node *new_node = malloc(sizeof(bt_node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
bt_node *bt_set_root(binary_tree *tree, bt_data data)
{
    if (tree == NULL) {
        return NULL;
    }
    bt_node *root = bt_create_node(data);
    if (root == NULL) {
        return NULL;
    }
    tree->root = root;
    return tree->root;
}
bt_node *bt_add_left(bt_node *parent, bt_data data)
{
    if (parent == NULL || parent->left) {
        return NULL;
    }
    bt_node *left = bt_create_node(data);
    if (left == NULL) {
        return NULL;
    }
    parent->left = left;
    return parent->left;
}
bt_node *bt_add_right(bt_node *parent, bt_data data)
{
    if (parent == NULL || parent->right) {
        return NULL;
    }
    bt_node *right = bt_create_node(data);
    if (right == NULL) {
        return NULL;
    }
    parent->right = right;
    return parent->right;
}

void bt_preorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    printf(" %d", node->data);
    bt_preorder(node->left);
    bt_preorder(node->right);
}
void bt_inorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_inorder(node->left);
    printf(" %d", node->data);
    bt_inorder(node->right);
}
void bt_postorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_postorder(node->left);
    bt_postorder(node->right);
    printf(" %d", node->data);
}
void bt_destroy_subtree(bt_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bt_destroy_subtree(subtree->left);
    bt_destroy_subtree(subtree->right);
    free(subtree);
}
void bt_destroy(binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    bt_destroy_subtree(tree->root);
    free(tree);
}
