#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

avl_node *avl_node_create(avl_data key)
{
    avl_node *new_node = malloc(sizeof(avl_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->key = key;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void avl_subtree_destroy(avl_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    avl_subtree_destroy(subtree->left);
    avl_subtree_destroy(subtree->right);
    avl_node_destroy(subtree);
}
void avl_node_destroy(avl_node *node)
{
    free(node);
}
avl_node *avl_node_insert(avl_node *node, avl_data key)
{
    if (node == NULL) {
        return avl_node_create(key);
    }
    if (key < node->key) {
        node->left = avl_node_insert(node->left, key);
    } else if (key > node->key) {
        node->right = avl_node_insert(node->right, key);
    } else {
        return node;
    }
    return avl_rebalance(node);
}
avl_node *avl_node_remove(avl_node *node, avl_data key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = avl_node_remove(node->left, key);
    } else if (key > node->key) {
        node->right = avl_node_remove(node->right, key);
    } else {
        if (node->left == NULL || node->right == NULL) {
            avl_node *child = NULL;
            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }
            avl_node_destroy(node);
            return child;
        }
        avl_node *successor = avl_find_min(node->right);
        node->key = successor->key;
        node->right = avl_node_remove(node->right, successor->key);
    }

    return avl_rebalance(node);
}
avl_node *avl_rebalance(avl_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    avl_update_height(node);
    int balance = avl_balancefactor(node);

    if (balance > 1) {
        if (avl_balancefactor(node->left) < 0) {
            node->left = avl_rotate_left(node->left);
        }

        return avl_rotate_right(node);
    }
    if (balance < -1) {

        if (avl_balancefactor(node->right) > 0) {
            node->right = avl_rotate_right(node->right);
        }
        return avl_rotate_left(node);
    }
    return node;
}
void avl_update_height(avl_node *node)
{
    if (node == NULL) {
        return;
    }
    size_t left_height = avl_height(node->left);
    size_t right_height = avl_height(node->right);
    node->height = 1 + avl_max(left_height, right_height);
}
avl_node *avl_rotate_right(avl_node *y)
{
    if (y == NULL) {
        return NULL;
    }
    avl_node *x = y->left;
    y->left = x->right;
    x->right = y;
    avl_update_height(y);
    avl_update_height(x);
    return x;
}
avl_node *avl_rotate_left(avl_node *x)
{
    if (x == NULL) {
        return NULL;
    }
    avl_node *y = x->right;
    x->right = y->left;
    y->left = x;
    avl_update_height(x);
    avl_update_height(y);
    return y;
}
avl_node *avl_find_min(avl_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
void avl_inorder(avl_node *node)
{
    if (node == NULL) {
        return;
    }
    avl_inorder(node->left);
    printf("%d ", node->key);
    avl_inorder(node->right);
}
size_t avl_height(avl_node *node) { return node ? node->height : 0; }
size_t avl_max(size_t a, size_t b) { return a > b ? a : b; }
int avl_balancefactor(avl_node *node)
{
    return (int)avl_height(node->left) - (int)avl_height(node->right);
}
