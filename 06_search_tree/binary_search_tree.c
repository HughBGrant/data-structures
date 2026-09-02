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

static void bs_node_destroy(BSNode *node);

static void bs_subtree_destroy(BSNode *subtree);

static BSNode *bs_node_create(BSItem key);

static BSNode *bs_node_insert(BSNode *node, BSItem key);

static BSNode *bs_find_min(BSNode *node);

static BSNode *bs_node_delete(BSNode *node, BSItem key);

static void bs_inorder(BSNode *node);
static void bs_node_destroy(BSNode *node)
{
    free(node);
}
static void bs_subtree_destroy(BSNode *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bs_subtree_destroy(subtree->left);
    bs_subtree_destroy(subtree->right);
    bs_node_destroy(subtree);
}
static BSNode *bs_node_create(BSItem key)
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
static BSNode *bs_node_insert(BSNode *node, BSItem key)
{
    if (node == NULL) {
        return bs_node_create(key);
    }
    if (key < node->key) {
        node->left = bs_node_insert(node->left, key);
    } else if (key > node->key) {
        node->right = bs_node_insert(node->right, key);
    }
    return node;
}
static BSNode *bs_find_min(BSNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
static BSNode *bs_node_delete(BSNode *node, BSItem key)
{
    if (node == NULL) {
        return NULL;
    }

    if (key < node->key) {
        node->left = bs_node_delete(node->left, key);
    } else if (key > node->key) {
        node->right = bs_node_delete(node->right, key);
    } else {
        if (node->left == NULL || node->right == NULL) {
            BSNode *child = NULL;

            if (node->left) {
                child = node->left;
            } else {
                child = node->right;
            }
            bs_node_destroy(node);
            return child;
        }

        BSNode *successor = bs_find_min(node->right);
        node->key = successor->key;
        node->right = bs_node_delete(node->right, successor->key);
    }
    return node;
}
static void bs_inorder(BSNode *node)
{
    if (node == NULL) {
        return;
    }
    bs_inorder(node->left);
    printf("%d ", node->key);
    bs_inorder(node->right);
}
BSDictionary *bs_create(void)
{
    BSDictionary *st = malloc(sizeof(BSDictionary));
    if (st == NULL) {
        return NULL;
    }

    st->root = NULL;

    return st;
}
void bs_destroy(BSDictionary *st)
{
    if (st == NULL) {
        return;
    }

    bs_subtree_destroy(st->root);
    free(st);
}
void bs_insert(BSDictionary *st, BSItem key)
{
    if (st == NULL) {
        return;
    }
    st->root = bs_node_insert(st->root, key);
}
void bs_delete(BSDictionary *st, BSItem key)
{
    if (st == NULL) {
        return;
    }
    st->root = bs_node_delete(st->root, key);
}
BSNode *bs_search(BSDictionary *st, BSItem key)
{
    if (st == NULL) {
        return NULL;
    }
    BSNode *current_node = st->root;
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
void bs_print(BSDictionary *st)
{
    if (st == NULL || st->root == NULL) {
        return;
    }
    bs_inorder(st->root);
    printf("\n");
}
BSItem *bs_get(BSNode *node)
{
    if (node == NULL) {
        return NULL;
    }
    return &node->key;
}