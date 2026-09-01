#include "a_v_l_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    AVLItem key;
    size_t height;
    struct AVLNode *left;
    struct AVLNode *right;
};
struct AVLree {
    AVLNode *root;
};
static AVLNode *avlt_node_create(AVLItem key);
static void avlt_node_destroy(AVLNode *node);
static void avlt_subtree_destroy(AVLNode *subtree);
static size_t avlt_height(AVLNode *node);
static size_t avlt_max(size_t a, size_t b);
static void avlt_update_height(AVLNode *node);
static AVLNode *avlt_rotate_left(AVLNode *x);
static AVLNode *avlt_rotate_right(AVLNode *y);
static int avlt_balancefactor(AVLNode *node);
static AVLNode *avlt_rebalance(AVLNode *node);
static AVLNode *avlt_node_insert(AVLNode *node, AVLItem key);
static AVLNode *avlt_find_min(AVLNode *node);
static AVLNode *avlt_node_delete(AVLNode *node, AVLItem key);
static void avlt_inorder(AVLNode *node);

AVLDictionary *avlt_create(void)
{
    AVLDictionary *os = malloc(sizeof(AVLDictionary));
    if (os == NULL) {
        return NULL;
    }

    os->root = NULL;

    return os;
}
void avlt_destroy(AVLDictionary *os)
{
    if (os == NULL) {
        return;
    }

    avlt_subtree_destroy(os->root);
    free(os);
}
static AVLNode *avlt_node_create(AVLItem key)
{
    AVLNode *new_node = malloc(sizeof(AVLNode));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->key = key;
    new_node->height = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
static void avlt_node_destroy(AVLNode *node)
{
    free(node);
}
static void avlt_subtree_destroy(AVLNode *subtree)
{
    if (subtree == NULL) {
        return;
    }
    avlt_subtree_destroy(subtree->left);
    avlt_subtree_destroy(subtree->right);
    avlt_node_destroy(subtree);
}
static size_t avlt_height(AVLNode *node)
{
    return node ? node->height : 0;
}
static size_t avlt_max(size_t a, size_t b)
{
    return a > b ? a : b;
}
static void avlt_update_height(AVLNode *node)
{
    if (node == NULL) {
        return;
    }
    size_t left_height = avlt_height(node->left);
    size_t right_height = avlt_height(node->right);
    node->height = 1 + avlt_max(left_height, right_height);
}
static AVLNode *avlt_rotate_left(AVLNode *x)
{
    if (x == NULL) {
        return NULL;
    }
    AVLNode *y = x->right;
    x->right = y->left;
    y->left = x;
    avlt_update_height(x);
    avlt_update_height(y);
    return y;
}
static AVLNode *avlt_rotate_right(AVLNode *y)
{
    if (y == NULL) {
        return NULL;
    }
    AVLNode *x = y->left;
    y->left = x->right;
    x->right = y;
    avlt_update_height(y);
    avlt_update_height(x);
    return x;
}
static int avlt_balancefactor(AVLNode *node)
{
    return (int)avlt_height(node->left) - (int)avlt_height(node->right);
}
static AVLNode *avlt_rebalance(AVLNode *node)
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
static AVLNode *avlt_node_insert(AVLNode *node, AVLItem key)
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
static AVLNode *avlt_find_min(AVLNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
static AVLNode *avlt_node_delete(AVLNode *node, AVLItem key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = avlt_node_delete(node->left, key);
    } else if (key > node->key) {
        node->right = avlt_node_delete(node->right, key);
    } else {
        if (node->left == NULL || node->right == NULL) {
            AVLNode *child = NULL;
            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }
            avlt_node_destroy(node);
            return child;
        }
        AVLNode *successor = avlt_find_min(node->right);
        node->key = successor->key;
        node->right = avlt_node_delete(node->right, successor->key);
    }

    return avlt_rebalance(node);
}
static void avlt_inorder(AVLNode *node)
{
    if (node == NULL) {
        return;
    }
    avlt_inorder(node->left);
    printf("%d ", node->key);
    avlt_inorder(node->right);
}
void avlt_insert(AVLDictionary *os, AVLItem key)
{
    if (os == NULL) {
        return;
    }
    os->root = avlt_node_insert(os->root, key);
}
void avlt_delete(AVLDictionary *os, AVLItem key)
{
    if (os == NULL) {
        return;
    }
    os->root = avlt_node_delete(os->root, key);
}
AVLNode *avlt_search(AVLDictionary *os, AVLItem key)
{
    if (os == NULL) {
        return NULL;
    }
    AVLNode *current_node = os->root;
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

void avlt_print(AVLDictionary *os)
{
    if (os == NULL || os->root == NULL) {
        return;
    }
    avlt_inorder(os->root);
    printf("\n");
}
AVLItem *avlt_get(AVLNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}