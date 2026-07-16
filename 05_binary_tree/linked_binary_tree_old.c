#include "linked_binary_tree_old.h"

linked_binary_tree_old *lbto_create(lbto_data data)
{
    linked_binary_tree_old *tree = malloc(sizeof(linked_binary_tree_old));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = lbto_create_node(data);
    if (tree->root == NULL) {
        free(tree);
        return NULL;
    }

    return tree;
}
lbto_node *lbto_create_node(lbto_data data)
{
    lbto_node *new_node = malloc(sizeof(lbto_node));

    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void lbto_insert_left(lbto_node *parent, lbto_node *child)
{
    if (parent == NULL || child == NULL || parent->left) {
        return;
    }
    parent->left = child;
}
void lbto_insert_right(lbto_node *parent, lbto_node *child)
{
    if (parent == NULL || child == NULL || parent->right) {
        return;
    }
    parent->right = child;
}
void lbto_destroy_subtree(lbto_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    lbto_destroy_subtree(subtree->left);
    lbto_destroy_subtree(subtree->right);
    free(subtree);
}
void lbto_delete_left(lbto_node *parent)
{
    if (parent == NULL) {
        return;
    }
    lbto_destroy_subtree(parent->left);
}
void lbto_delete_right(lbto_node *parent)
{
    if (parent == NULL) {
        return;
    }
    lbto_destroy_subtree(parent->right);
}
void lbto_preorder(lbto_node *node)
{
    if (node == NULL) {
        return;
    }
    printf(" %c", node->data);
    lbto_preorder(node->left);
    lbto_preorder(node->right);
}
void lbto_inorder(lbto_node *node)
{
    if (node == NULL) {
        return;
    }
    lbto_inorder(node->left);
    printf(" %c", node->data);
    lbto_inorder(node->right);
}
void lbto_postorder(lbto_node *node)
{
    if (node == NULL) {
        return;
    }
    lbto_postorder(node->left);
    lbto_postorder(node->right);
    printf(" %c", node->data);
}
void lbto_destroy(linked_binary_tree_old *tree)
{
    if (tree == NULL) {
        return;
    }
    lbto_destroy_subtree(tree->root);
    free(tree);
}
