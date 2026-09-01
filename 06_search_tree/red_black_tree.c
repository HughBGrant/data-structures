#include "red_black_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct rbt_node {
    rbt_item key;
    Color color;
    struct rbt_node *parent;
    struct rbt_node *left;
    struct rbt_node *right;
};
struct rbt_tree {
    rbt_node *root;
    rbt_node *nil;
};
static void rbt_node_destroy(rbt_node *node);
static void rbt_subtree_destroy(rbt_ordered_set *tree, rbt_node *node);
static rbt_node *rbt_node_search(rbt_ordered_set *tree, rbt_node *node, rbt_item key);
static void rbt_transplant(rbt_ordered_set *tree, rbt_node *old_node, rbt_node *new_node);
static void rbt_fix_delete(rbt_ordered_set *tree, rbt_node *node);
static void rbt_print_node(rbt_ordered_set *tree, rbt_node *node, int depth, int black_count);
static rbt_node *rbt_node_search_min(rbt_ordered_set *tree, rbt_node *node);
static void rbt_node_insert(rbt_ordered_set *tree, rbt_node *node);
static void rbt_rotate_left(rbt_ordered_set *tree, rbt_node *node);
static void rbt_rotate_right(rbt_ordered_set *tree, rbt_node *node);
static void rbt_fix_insert(rbt_ordered_set *tree, rbt_node *node);

rbt_ordered_set *rbt_create(void)
{
    rbt_ordered_set *tree = malloc(sizeof(rbt_ordered_set));
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
void rbt_destroy(rbt_ordered_set *tree)
{
    if (tree == NULL) {
        return;
    }

    rbt_subtree_destroy(tree, tree->root);
    rbt_node_destroy(tree->nil);
    free(tree);
}
static rbt_node *rbt_node_create(rbt_item key)
{
    rbt_node *node = malloc(sizeof(rbt_node));
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
static void rbt_node_destroy(rbt_node *node)
{
    free(node);
}
static void rbt_subtree_destroy(rbt_ordered_set *tree, rbt_node *node)
{
    if (node == tree->nil) {
        return;
    }
    rbt_subtree_destroy(tree, node->left);
    rbt_subtree_destroy(tree, node->right);
    rbt_node_destroy(node);
}
rbt_node *rbt_search(rbt_ordered_set *tree, rbt_item key)
{
    if (tree == NULL) {
        return NULL;
    }
    return rbt_node_search(tree, tree->root, key);
}
static rbt_node *rbt_node_search(
    rbt_ordered_set *tree,
    rbt_node *node,
    rbt_item key)
{
    if (node == tree->nil || node->key == key) {
        return node == tree->nil ? NULL : node;
    }
    if (key < node->key) {
        return rbt_node_search(tree, node->left, key);
    }
    return rbt_node_search(tree, node->right, key);
}
static rbt_node *rbt_node_search_min(rbt_ordered_set *tree, rbt_node *node)
{
    if (node == tree->nil) {
        return tree->nil;
    }

    if (node->left == tree->nil) {
        return node;
    }

    return rbt_node_search_min(tree, node->left);
}

static void rbt_node_insert(rbt_ordered_set *tree, rbt_node *node)
{
    rbt_node *parent = tree->nil;
    rbt_node *current = tree->root;

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

static void rbt_rotate_left(rbt_ordered_set *tree, rbt_node *node)
{
    rbt_node *child = node->right;

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

static void rbt_rotate_right(rbt_ordered_set *tree, rbt_node *node)
{
    rbt_node *child = node->left;

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

static void rbt_fix_insert(rbt_ordered_set *tree, rbt_node *node)
{
    while (node->parent->color == RED) {
        rbt_node *parent = node->parent;
        rbt_node *grand = parent->parent;

        if (parent == grand->left) {
            rbt_node *uncle = grand->right;

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
            rbt_node *uncle = grand->left;

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

void rbt_insert(rbt_ordered_set *tree, rbt_item key)
{
    rbt_node *node;

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

static void rbt_transplant(rbt_ordered_set *tree, rbt_node *old_node, rbt_node *new_node)
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

static void rbt_fix_delete(rbt_ordered_set *tree, rbt_node *node)
{
    while (node != tree->root && node->color == BLACK) {
        if (node == node->parent->left) {
            rbt_node *sibling = node->parent->right;

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
            rbt_node *sibling = node->parent->left;

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
int rbt_delete(rbt_ordered_set *tree, rbt_item key)
{
    rbt_node *target;
    rbt_node *removed;
    rbt_node *child;
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

static void rbt_print_node(rbt_ordered_set *tree, rbt_node *node, int depth, int black_count)
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

void rbt_print(rbt_ordered_set *tree)
{
    if (tree == NULL) {
        return;
    }

    rbt_print_node(tree, tree->root, 0, 0);
}
