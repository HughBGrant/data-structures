#include "a_v_l_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct avlt_node {
    avlt_item key;
    size_t height;
    struct avlt_node *left;
    struct avlt_node *right;
};

struct a_v_l_tree {
    avlt_node *root;
};

static avlt_node *avlt_node_create(avlt_item key)
{
    avlt_node *new_node = malloc(sizeof(avlt_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->key = key;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
static void avlt_node_destroy(avlt_node *node)
{
    free(node);
}
static void avlt_subtree_destroy(avlt_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    avlt_subtree_destroy(subtree->left);
    avlt_subtree_destroy(subtree->right);
    avlt_node_destroy(subtree);
}
static size_t avlt_height(avlt_node *node) { return node ? node->height : 0; }
static size_t avlt_max(size_t a, size_t b) { return a > b ? a : b; }
static void avlt_update_height(avlt_node *node)
{
    if (node == NULL) {
        return;
    }
    size_t left_height = avlt_height(node->left);
    size_t right_height = avlt_height(node->right);
    node->height = 1 + avlt_max(left_height, right_height);
}
static avlt_node *avlt_rotate_left(avlt_node *x)
{
    if (x == NULL) {
        return NULL;
    }
    avlt_node *y = x->right;
    x->right = y->left;
    y->left = x;
    avlt_update_height(x);
    avlt_update_height(y);
    return y;
}
static avlt_node *avlt_rotate_right(avlt_node *y)
{
    if (y == NULL) {
        return NULL;
    }
    avlt_node *x = y->left;
    y->left = x->right;
    x->right = y;
    avlt_update_height(y);
    avlt_update_height(x);
    return x;
}
static int avlt_balancefactor(avlt_node *node)
{
    return (int)avlt_height(node->left) - (int)avlt_height(node->right);
}
static avlt_node *avlt_rebalance(avlt_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    avlt_update_height(node);
    int balance = avlt_balancefactor(node);

    if (balance > 1) {
        if (avlt_balancefactor(node->left) < 0) {
            node->left = avlt_rotate_left(node->left);
        }

        return avlt_rotate_right(node);
    }
    if (balance < -1) {

        if (avlt_balancefactor(node->right) > 0) {
            node->right = avlt_rotate_right(node->right);
        }
        return avlt_rotate_left(node);
    }
    return node;
}
static avlt_node *avlt_node_insert(avlt_node *node, avlt_item key)
{
    if (node == NULL) {
        return avlt_node_create(key);
    }
    if (key < node->key) {
        node->left = avlt_node_insert(node->left, key);
    } else if (key > node->key) {
        node->right = avlt_node_insert(node->right, key);
    } else {
        return node;
    }
    return avlt_rebalance(node);
}
static avlt_node *avlt_find_min(avlt_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
static avlt_node *avlt_node_remove(avlt_node *node, avlt_item key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = avlt_node_remove(node->left, key);
    } else if (key > node->key) {
        node->right = avlt_node_remove(node->right, key);
    } else {
        if (node->left == NULL || node->right == NULL) {
            avlt_node *child = NULL;
            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }
            avlt_node_destroy(node);
            return child;
        }
        avlt_node *successor = avlt_find_min(node->right);
        node->key = successor->key;
        node->right = avlt_node_remove(node->right, successor->key);
    }

    return avlt_rebalance(node);
}
static void avlt_inorder(avlt_node *node)
{
    if (node == NULL) {
        return;
    }
    avlt_inorder(node->left);
    printf("%d ", node->key);
    avlt_inorder(node->right);
}
avlt_ordered_set *avlt_create(void)
{
    avlt_ordered_set *os = malloc(sizeof(avlt_ordered_set));
    if (os == NULL) {
        return NULL;
    }

    os->root = NULL;

    return os;
}
void avlt_destroy(avlt_ordered_set *os)
{
    if (os == NULL) {
        return;
    }

    avlt_subtree_destroy(os->root);
    free(os);
}
void avlt_insert(avlt_ordered_set *os, avlt_item key)
{
    if (os == NULL) {
        return;
    }
    os->root = avlt_node_insert(os->root, key);
}
void avlt_remove(avlt_ordered_set *os, avlt_item key)
{
    if (os == NULL) {
        return;
    }
    os->root = avlt_node_remove(os->root, key);
}
avlt_node *avlt_search(avlt_ordered_set *os, avlt_item key)
{
    if (os == NULL) {
        return NULL;
    }
    avlt_node *current_node = os->root;
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

void avlt_print(avlt_ordered_set *os)
{
    if (os == NULL || os->root == NULL) {
        return;
    }
    avlt_inorder(os->root);
    printf("\n");
}
avlt_item *avlt_get(avlt_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}