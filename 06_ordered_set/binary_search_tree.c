#include "binary_search_tree.h"

binary_search_tree *bst_create()
{
    binary_search_tree *tree = malloc(sizeof(binary_search_tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;

    return tree;
}
bst_node *bst_create_node(bst_data key)
{
    bst_node *new_node = malloc(sizeof(bst_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void bst_insert(binary_search_tree *tree, bst_data key)
{
    if (tree == NULL) {
        return;
    }
    /* 루트가 비어 있는 경우 */
    if (tree->root == NULL) {
        tree->root = bst_create_node(key);
        return;
    }
    bst_node *parent_node = NULL;
    bst_node *current_node = tree->root;

    while (current_node != NULL) {
        if (key == current_node->data) {
            return;
        }
        parent_node = current_node;
        if (key < current_node->data) {
            current_node = current_node->left;
        } else if (key > current_node->data) {
            current_node = current_node->right;
        }
    }

    bst_node *new_node = bst_create_node(key);
    if (new_node == NULL) {
        return;
    }

    if (key < parent_node->data) {
        parent_node->left = new_node;
    } else {
        parent_node->right = new_node;
    }
}
bst_node *bst_delete(bst_node *node, bst_data key)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL || node->right == NULL) {

        free(node);
        return NULL;
    }
    if (key < node->data) {
        node->left = bst_delete(node->left, key);
    } else if (key > node->data) {
        node->right = bst_delete(node->right, key);

    } else {
        bst_node *successor = NULL;
        if (bst_height(node->left) > bst_height(node->right)) {
            successor = bst_predecessor(node->left);
            node->data = successor->data;
            node->left = bst_delete(node->left, successor->data);
        } else {
            successor = bst_successor(node->right);
            node->data = successor->data;
            node->right = bst_delete(node->right, successor->data);
        }
    }
    return node;
}
size_t bst_height(bst_node *node)
{
    if (node == NULL) {
        return 0;
    }
    size_t left_height = bst_height(node->left);
    size_t right_height = bst_height(node->right);
    return left_height > right_height ? left_height + 1 : right_height + 1;
}
bst_node *bst_predecessor(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node && node->right) {
        node = node->right;
    }
    return node;
}
bst_node *bst_successor(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node && node->left) {
        node = node->left;
    }
    return node;
}
bst_node *bst_search(binary_search_tree *tree, bst_data key)
{
    if (tree == NULL) {
        return NULL;
    }
    bst_node *current_node = tree->root;
    while (current_node != NULL) {
        if (key == current_node->data) {
            return current_node;
        } else if (key < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }
    return NULL;
}
void bst_inorder(bst_node *node)
{
    if (node == NULL) {
        return;
    }
    bst_inorder(node->left);
    printf("%d, ", node->data);
    bst_inorder(node->right);
}
void bst_destroy_subtree(bst_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bst_destroy_subtree(subtree->left);
    bst_destroy_subtree(subtree->right);
    free(subtree);
}
void bst_destroy(binary_search_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    bst_destroy_subtree(tree->root);
    free(tree);
}
