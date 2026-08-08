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
void bst_destroy(binary_search_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    bst_subtree_destroy(tree->root);
    free(tree);
}
bst_node *bst_node_create(bst_data key)
{
    bst_node *new_node = malloc(sizeof(bst_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void bst_node_destroy(bst_node *node)
{
    free(node);
}
void bst_subtree_destroy(bst_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bst_subtree_destroy(subtree->left);
    bst_subtree_destroy(subtree->right);
    bst_node_destroy(subtree);
}
void bst_insert(binary_search_tree *tree, bst_data key)
{
    if (tree == NULL) {
        return;
    }

    if (tree->root == NULL) {
        tree->root = bst_node_create(key);
        return;
    }

    bst_node *current_node = tree->root;

    while (1) {
        if (key == current_node->key) {
            return;
        }

        if (key < current_node->key) {
            if (current_node->left == NULL) {
                current_node->left = bst_node_create(key);
                return;
            }

            current_node = current_node->left;
        } else {
            if (current_node->right == NULL) {
                current_node->right = bst_node_create(key);
                return;
            }

            current_node = current_node->right;
        }
    }
}
void bst_remove(binary_search_tree *tree, bst_data key)
{
    if (tree == NULL) {
        return;
    }
    tree->root = bst_node_remove(tree->root, key);
}
bst_node *bst_node_remove(bst_node *node, bst_data key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = bst_node_remove(node->left, key);
    } else if (key > node->key) {
        node->right = bst_node_remove(node->right, key);
    } else {
        if (node->left == NULL) {
            bst_node *right_child = node->right;
            bst_node_destroy(node);
            return right_child;
        }

        if (node->right == NULL) {
            bst_node *left_child = node->left;
            bst_node_destroy(node);
            return left_child;
        }

        bst_node *successor = bst_min(node->right);
        node->key = successor->key;
        node->right = bst_node_remove(node->right, successor->key);
    }
    return node;
}
bst_node *bst_min(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
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
        if (key == current_node->key) {
            return current_node;
        } else if (key < current_node->key) {
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
    printf("%d, ", node->key);
    bst_inorder(node->right);
}
void bst_print(binary_search_tree *tree)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }
    bst_inorder(tree->root);
    printf("\n");
}
bst_data *bst_key(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}