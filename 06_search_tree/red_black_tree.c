#include "red_black_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct RBNode {
    RBItem key;
    Color color;
    struct RBNode *parent;
    struct RBNode *left;
    struct RBNode *right;
};
struct RBTree {
    RBNode *root;
    RBNode *nil;
};
static void rbt_node_destroy(RBNode *node);
static void rbt_subtree_destroy(RBDictionary *tree, RBNode *node);
static RBNode *rbt_node_search(RBDictionary *tree, RBNode *node, RBItem key);
static void rbt_transplant(RBDictionary *tree, RBNode *old_node, RBNode *new_node);
static void rbt_fix_delete(RBDictionary *tree, RBNode *node);
static void rbt_print_node(RBDictionary *tree, RBNode *node, int depth, int black_count);
static RBNode *rbt_node_search_min(RBDictionary *tree, RBNode *node);
static void rbt_node_insert(RBDictionary *tree, RBNode *node);
static void rbt_rotate_left(RBDictionary *tree, RBNode *node);
static void rbt_rotate_right(RBDictionary *tree, RBNode *node);
static void rbt_fix_insert(RBDictionary *tree, RBNode *node);

RBDictionary *rbt_create(void)
{
    RBDictionary *tree = malloc(sizeof(RBDictionary));
    if (tree == NULL) {
        return NULL;
    }
    tree->nil = rbt_node_create(0);
    if (tree->nil == NULL) {
        free(tree);
        return NULL;
    }
    tree->nil->color = BLACK;
    tree->nil->parent = tree->nil;
    tree->nil->left = tree->nil;
    tree->nil->right = tree->nil;
    tree->root = tree->nil;

    return tree;
}
void rbt_destroy(RBDictionary *tree)
{
    if (tree == NULL) {
        return;
    }

    rbt_subtree_destroy(tree, tree->root);
    rbt_node_destroy(tree->nil);
    free(tree);
}
static RBNode *rbt_node_create(RBItem key)
{
    RBNode *node = malloc(sizeof(RBNode));
    if (node == NULL) {
        return NULL;
    }

    node->key = key;
    node->color = BLACK;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}
static void rbt_node_destroy(RBNode *node)
{
    free(node);
}
static void rbt_subtree_destroy(RBDictionary *tree, RBNode *node)
{
    if (node == tree->nil) {
        return;
    }
    rbt_subtree_destroy(tree, node->left);
    rbt_subtree_destroy(tree, node->right);
    rbt_node_destroy(node);
}
RBNode *rbt_search(RBDictionary *tree, RBItem key)
{
    if (tree == NULL) {
        return NULL;
    }
    return rbt_node_search(tree, tree->root, key);
}
static RBNode *rbt_node_search(
    RBDictionary *tree,
    RBNode *node,
    RBItem key)
{
    if (node == tree->nil || node->key == key) {
        return node == tree->nil ? NULL : node;
    }
    if (key < node->key) {
        return rbt_node_search(tree, node->left, key);
    }
    return rbt_node_search(tree, node->right, key);
}
static RBNode *rbt_node_search_min(RBDictionary *tree, RBNode *node)
{
    if (node == tree->nil) {
        return tree->nil;
    }

    if (node->left == tree->nil) {
        return node;
    }

    return rbt_node_search_min(tree, node->left);
}

static void rbt_node_insert(RBDictionary *tree, RBNode *node)
{
    RBNode *parent = tree->nil;
    RBNode *current = tree->root;

    while (current != tree->nil) {
        parent = current;

        if (node->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    node->parent = parent;

    if (parent == tree->nil) {
        tree->root = node;
    } else if (node->key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    node->left = tree->nil;
    node->right = tree->nil;
    node->color = RED;
}

static void rbt_rotate_left(RBDictionary *tree, RBNode *node)
{
    RBNode *child = node->right;

    node->right = child->left;

    if (child->left != tree->nil) {
        child->left->parent = node;
    }

    child->parent = node->parent;

    if (node->parent == tree->nil) {
        tree->root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }

    child->left = node;
    node->parent = child;
}

static void rbt_rotate_right(RBDictionary *tree, RBNode *node)
{
    RBNode *child = node->left;

    node->left = child->right;

    if (child->right != tree->nil) {
        child->right->parent = node;
    }

    child->parent = node->parent;

    if (node->parent == tree->nil) {
        tree->root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }

    child->right = node;
    node->parent = child;
}

static void rbt_fix_insert(RBDictionary *tree, RBNode *node)
{
    while (node->parent->color == RED) {
        RBNode *parent = node->parent;
        RBNode *grand = parent->parent;

        if (parent == grand->left) {
            RBNode *uncle = grand->right;

            if (uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                node = grand;
            } else {
                if (node == parent->right) {
                    node = parent;
                    rbt_rotate_left(tree, node);
                    parent = node->parent;
                    grand = parent->parent;
                }

                parent->color = BLACK;
                grand->color = RED;
                rbt_rotate_right(tree, grand);
            }
        } else {
            RBNode *uncle = grand->left;

            if (uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                node = grand;
            } else {
                if (node == parent->left) {
                    node = parent;
                    rbt_rotate_right(tree, node);
                    parent = node->parent;
                    grand = parent->parent;
                }

                parent->color = BLACK;
                grand->color = RED;
                rbt_rotate_left(tree, grand);
            }
        }
    }

    tree->root->color = BLACK;
}

void rbt_insert(RBDictionary *tree, RBItem key)
{
    RBNode *node;

    if (tree == NULL) {
        return;
    }

    node = rbt_node_create(key);

    if (node == NULL) {
        return;
    }

    rbt_node_insert(tree, node);
    rbt_fix_insert(tree, node);
}

static void rbt_transplant(RBDictionary *tree, RBNode *old_node, RBNode *new_node)
{
    if (old_node->parent == tree->nil) {
        tree->root = new_node;
    } else if (old_node == old_node->parent->left) {
        old_node->parent->left = new_node;
    } else {
        old_node->parent->right = new_node;
    }

    new_node->parent = old_node->parent;
}

static void rbt_fix_delete(RBDictionary *tree, RBNode *node)
{
    while (node != tree->root && node->color == BLACK) {
        if (node == node->parent->left) {
            RBNode *sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rbt_rotate_left(tree, node->parent);
                sibling = node->parent->right;
            }

            if (sibling->left->color == BLACK &&
                sibling->right->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rbt_rotate_right(tree, sibling);
                    sibling = node->parent->right;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rbt_rotate_left(tree, node->parent);
                node = tree->root;
            }
        } else {
            RBNode *sibling = node->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rbt_rotate_right(tree, node->parent);
                sibling = node->parent->left;
            }

            if (sibling->right->color == BLACK &&
                sibling->left->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rbt_rotate_left(tree, sibling);
                    sibling = node->parent->left;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rbt_rotate_right(tree, node->parent);
                node = tree->root;
            }
        }
    }
    node->color = BLACK;
}
int rbt_delete(RBDictionary *tree, RBItem key)
{
    RBNode *target;
    RBNode *removed;
    RBNode *child;
    Color removed_color;

    if (tree == NULL) {
        return 0;
    }

    target = rbt_search(tree, key);

    if (target == NULL) {
        return 0;
    }

    removed = target;

    if (target->left != tree->nil &&
        target->right != tree->nil) {
        removed = rbt_node_search_min(tree, target->right);
        target->key = removed->key;
    }

    removed_color = removed->color;

    if (removed->left != tree->nil) {
        child = removed->left;
    } else {
        child = removed->right;
    }

    rbt_transplant(tree, removed, child);

    if (removed_color == BLACK) {
        rbt_fix_delete(tree, child);
    }

    rbt_node_destroy(removed);

    return 1;
}

static void rbt_print_node(RBDictionary *tree, RBNode *node, int depth, int black_count)
{
    int i;
    int parent_key = -1;
    char position = 'X';

    if (node == tree->nil) {
        return;
    }

    if (node->color == BLACK) {
        black_count++;
    }

    if (node->parent != tree->nil) {
        parent_key = node->parent->key;

        if (node == node->parent->left)
            position = 'L';
        else
            position = 'R';
    }

    for (i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("%d %s [%c,%d]", node->key, node->color == RED ? "RED" : "BLACK", position, parent_key);

    if (node->left == tree->nil && node->right == tree->nil) {
        printf(" --------- %d", black_count);
    }

    printf("\n");

    rbt_print_node(tree, node->left, depth + 1, black_count);

    rbt_print_node(tree, node->right, depth + 1, black_count);
}

void rbt_print(RBDictionary *tree)
{
    if (tree == NULL) {
        return;
    }

    rbt_print_node(tree, tree->root, 0, 0);
}
