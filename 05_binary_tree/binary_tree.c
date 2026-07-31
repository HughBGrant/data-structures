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
bt_node *bt_node_create(bt_data data)
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
void bt_node_destroy(bt_node *node)
{
    free(node);
}
void bt_set_root(binary_tree *tree, bt_node *root)
{
    if (tree == NULL || root == NULL) {
        return;
    }
    tree->root = root;
}
bt_node *bt_node_set_left(bt_node *parent, bt_node *child)
{
    if (parent == NULL || parent->left || child == NULL) {
        return NULL;
    }
    parent->left = child;
    return parent->left;
}
bt_node *bt_node_set_right(bt_node *parent, bt_node *child)
{
    if (parent == NULL || parent->right || child == NULL) {
        return NULL;
    }
    parent->right = child;
    return parent->right;
}
void bt_node_preorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    bt_node_preorder(node->left);
    bt_node_preorder(node->right);
}
void bt_node_inorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_node_inorder(node->left);
    printf("%d ", node->data);
    bt_node_inorder(node->right);
}
void bt_node_postorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_node_postorder(node->left);
    bt_node_postorder(node->right);
    printf("%d ", node->data);
}
void bt_subtree_destroy(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_subtree_destroy(node->left);
    bt_subtree_destroy(node->right);
    bt_node_destroy(node);
}
void bt_destroy(binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    bt_subtree_destroy(tree->root);
    free(tree);
}
