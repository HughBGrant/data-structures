#include "avl_tree.h"

avl_tree *avl_create()
{
    avl_tree *tree = malloc(sizeof(avl_tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;

    return tree;
}
void avl_destroy(avl_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    avl_subtree_destroy(tree->root);
    free(tree);
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
avl_node *avl_node_create(avl_data key)
{
    avl_node *new_node = malloc(sizeof(avl_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->left = NULL;
    new_node->key = key;
    new_node->height = 1;
    new_node->right = NULL;

    return new_node;
}
void avl_node_destroy(avl_node *node)
{
    free(node);
}
void avl_insert(avl_tree *tree, avl_data key)
{
    if (tree == NULL) {
        return;
    }
    tree->root = avl_node_insert(tree->root, key);
}
avl_node *avl_node_insert(avl_node *node, int key)
{
    if (node == NULL)
        return avl_node_create(key);
    if (key < node->key) {
        node->left = avl_node_insert(node->left, key);
    } else if (key > node->key) {
        node->right = avl_node_insert(node->right, key);
    }

    avl_update_height(node);

    int balance = avl_balance_factor(node);

    if (balance > 1) {
        if (avl_balance_factor(node->left) < 0) {
            node->left = avl_rotate_left(node->left);
        }
        return avl_rotate_right(node);
    }
    if (balance < -1) {
        if (avl_balance_factor(node->right) > 0) {
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
int avl_balance_factor(avl_node *node)
{
    if (node == NULL) {
        return 0;
    }
    return (int)(avl_height(node->left) - avl_height(node->right));
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
void avl_inorder(avl_node *node)
{
    if (node == NULL) {
        return;
    }
    avl_inorder(node->left);
    printf("%d ", node->key);
    avl_inorder(node->right);
}
size_t avl_height(avl_node *node)
{
    return node ? node->height : 0;
}
size_t avl_max(size_t a, size_t b)
{
    return a > b ? a : b;
}
