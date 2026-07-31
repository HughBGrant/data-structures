#include "binary_tree.h"

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
    printf(" %c", node->data);
    bt_preorder(node->left);
    bt_preorder(node->right);
}
void bt_inorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_inorder(node->left);
    printf(" %c", node->data);
    bt_inorder(node->right);
}
void bt_postorder(bt_node *node)
{
    if (node == NULL) {
        return;
    }
    bt_postorder(node->left);
    bt_postorder(node->right);
    printf(" %c", node->data);
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
