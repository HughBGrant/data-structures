#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct bst_node {
    bst_item key;
    struct bst_node *left;
    struct bst_node *right;
};

struct binary_search_tree {
    bst_node *root;
};

static void bst_node_destroy(bst_node *node);

static void bst_subtree_destroy(bst_node *subtree);

static bst_node *bst_node_create(bst_item key);

static bst_node *bst_node_insert(bst_node *node, bst_item key);

static bst_node *bst_find_min(bst_node *node);

static bst_node *bst_node_remove(bst_node *node, bst_item key);

static void bst_inorder(bst_node *node);
static void bst_node_destroy(bst_node *node)
{
    free(node);
}
static void bst_subtree_destroy(bst_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bst_subtree_destroy(subtree->left);
    bst_subtree_destroy(subtree->right);
    bst_node_destroy(subtree);
}
static bst_node *bst_node_create(bst_item key)
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
static bst_node *bst_node_insert(bst_node *node, bst_item key)
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
static bst_node *bst_find_min(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
static bst_node *bst_node_remove(bst_node *node, bst_item key)
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
static void bst_inorder(bst_node *node)
{
    if (node == NULL) {
        return;
    }
    bst_inorder(node->left);
    printf("%d ", node->key);
    bst_inorder(node->right);
}
bst_ordered_set *bst_create(void)
{
    bst_ordered_set *os = malloc(sizeof(bst_ordered_set));
    if (os == NULL) {
        return NULL;
    }

    os->root = NULL;

    return os;
}
void bst_destroy(bst_ordered_set *os)
{
    if (os == NULL) {
        return;
    }

    bst_subtree_destroy(os->root);
    free(os);
}
void bst_insert(bst_ordered_set *os, bst_item key)
{
    if (os == NULL) {
        return;
    }
    os->root = bst_node_insert(os->root, key);
}
void bst_remove(bst_ordered_set *os, bst_item key)
{
    if (os == NULL) {
        return;
    }
    os->root = bst_node_remove(os->root, key);
}
bst_node *bst_search(bst_ordered_set *os, bst_item key)
{
    if (os == NULL) {
        return NULL;
    }
    bst_node *current_node = os->root;
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
void bst_print(bst_ordered_set *os)
{
    if (os == NULL || os->root == NULL) {
        return;
    }
    bst_inorder(os->root);
    printf("\n");
}
bst_item *bst_get(bst_node *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}