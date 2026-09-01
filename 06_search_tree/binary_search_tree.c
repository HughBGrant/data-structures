#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct BSNode {
    BSItem key;
    struct BSNode *left;
    struct BSNode *right;
};

struct BinarySearchTree {
    BSNode *root;
};

static void bst_node_destroy(BSNode *node);

static void bst_subtree_destroy(BSNode *subtree);

static BSNode *bst_node_create(BSItem key);

static BSNode *bst_node_insert(BSNode *node, BSItem key);

static BSNode *bst_find_min(BSNode *node);

static BSNode *bst_node_delete(BSNode *node, BSItem key);

static void bst_inorder(BSNode *node);
static void bst_node_destroy(BSNode *node)
{
    free(node);
}
static void bst_subtree_destroy(BSNode *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bst_subtree_destroy(subtree->left);
    bst_subtree_destroy(subtree->right);
    bst_node_destroy(subtree);
}
static BSNode *bst_node_create(BSItem key)
{
    BSNode *new_node = malloc(sizeof(BSNode));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
static BSNode *bst_node_insert(BSNode *node, BSItem key)
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
static BSNode *bst_find_min(BSNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
static BSNode *bst_node_delete(BSNode *node, BSItem key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = bst_node_delete(node->left, key);
    } else if (key > node->key) {
        node->right = bst_node_delete(node->right, key);
    } else {
        if (node->left == NULL || node->right == NULL) {
            BSNode *child = NULL;

            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }
            bst_node_destroy(node);
            return child;
        }

        BSNode *successor = bst_find_min(node->right);
        node->key = successor->key;
        node->right = bst_node_delete(node->right, successor->key);
    }
    return node;
}
static void bst_inorder(BSNode *node)
{
    if (node == NULL) {
        return;
    }
    bst_inorder(node->left);
    printf("%d ", node->key);
    bst_inorder(node->right);
}
BSDictionary *bst_create(void)
{
    BSDictionary *os = malloc(sizeof(BSDictionary));
    if (os == NULL) {
        return NULL;
    }

    os->root = NULL;

    return os;
}
void bst_destroy(BSDictionary *os)
{
    if (os == NULL) {
        return;
    }

    bst_subtree_destroy(os->root);
    free(os);
}
void bst_insert(BSDictionary *os, BSItem key)
{
    if (os == NULL) {
        return;
    }
    os->root = bst_node_insert(os->root, key);
}
void bst_delete(BSDictionary *os, BSItem key)
{
    if (os == NULL) {
        return;
    }
    os->root = bst_node_delete(os->root, key);
}
BSNode *bst_search(BSDictionary *os, BSItem key)
{
    if (os == NULL) {
        return NULL;
    }
    BSNode *current_node = os->root;
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
void bst_print(BSDictionary *os)
{
    if (os == NULL || os->root == NULL) {
        return;
    }
    bst_inorder(os->root);
    printf("\n");
}
BSItem *bst_get(BSNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}