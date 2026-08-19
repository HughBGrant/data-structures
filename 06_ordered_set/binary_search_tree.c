#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

bst_node *bst_node_create(bst_item key)
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
bst_node *bst_node_insert(bst_node *node, bst_item key)
{
    if (node == NULL) {
        return bst_node_create(key);
    }
    if (key < node->key) {
        node->left = bst_node_insert(node->left, key);
    } else if (key > node->key) {
        node->right = bst_node_insert(node->right, key);
    }
    return node;
}
bst_node *bst_node_remove(bst_node *node, bst_item key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = bst_node_remove(node->left, key);
    } else if (key > node->key) {
        node->right = bst_node_remove(node->right, key);
    } else {
        if (node->left == NULL || node->right == NULL) {
            bst_node *child = NULL;

            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }
            bst_node_destroy(node);
            return child;
        }

        bst_node *successor = bst_find_min(node->right);
        node->key = successor->key;
        node->right = bst_node_remove(node->right, successor->key);
    }
    return node;
}

bst_node *bst_find_min(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
bst_node *bst_search(bst_node *node, bst_item key)
{
    bst_node *current_node = node;
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
    printf("%d ", node->key);
    bst_inorder(node->right);
}
bst_item *bst_key(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}