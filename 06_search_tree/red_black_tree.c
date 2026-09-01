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
static void rbt_subtree_destroy(RBDictionary *st, RBNode *node);
static RBNode *rbt_node_search(RBDictionary *st, RBNode *node, RBItem key);
static void rbt_transplant(RBDictionary *st, RBNode *old_node, RBNode *new_node);
static void rbt_fix_delete(RBDictionary *st, RBNode *node);
static void rbt_print_node(RBDictionary *st, RBNode *node, int depth, int black_count);
static RBNode *rbt_node_search_min(RBDictionary *st, RBNode *node);
static void rbt_node_insert(RBDictionary *st, RBNode *node);
static void rbt_rotate_left(RBDictionary *st, RBNode *node);
static void rbt_rotate_right(RBDictionary *st, RBNode *node);
static void rbt_fix_insert(RBDictionary *st, RBNode *node);

RBDictionary *rbt_create(void)
{
    RBDictionary *st = malloc(sizeof(RBDictionary));
    if (st == NULL) {
        return NULL;
    }
    st->nil = rbt_node_create(0);
    if (st->nil == NULL) {
        free(st);
        return NULL;
    }
    st->nil->color = BLACK;
    st->nil->parent = st->nil;
    st->nil->left = st->nil;
    st->nil->right = st->nil;
    st->root = st->nil;

    return st;
}
void rbt_destroy(RBDictionary *st)
{
    if (st == NULL) {
        return;
    }

    rbt_subst_destroy(st, st->root);
    rbt_node_destroy(st->nil);
    free(st);
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
static void rbt_subst_destroy(RBDictionary *st, RBNode *node)
{
    if (node == st->nil) {
        return;
    }
    rbt_subst_destroy(st, node->left);
    rbt_subst_destroy(st, node->right);
    rbt_node_destroy(node);
}
RBNode *rbt_search(RBDictionary *st, RBItem key)
{
    if (st == NULL) {
        return NULL;
    }
    return rbt_node_search(st, st->root, key);
}
static RBNode *rbt_node_search(
    RBDictionary *st,
    RBNode *node,
    RBItem key)
{
    if (node == st->nil || node->key == key) {
        return node == st->nil ? NULL : node;
    }
    if (key < node->key) {
        return rbt_node_search(st, node->left, key);
    }
    return rbt_node_search(st, node->right, key);
}
static RBNode *rbt_node_search_min(RBDictionary *st, RBNode *node)
{
    if (node == st->nil) {
        return st->nil;
    }

    if (node->left == st->nil) {
        return node;
    }

    return rbt_node_search_min(st, node->left);
}

static void rbt_node_insert(RBDictionary *st, RBNode *node)
{
    RBNode *parent = st->nil;
    RBNode *current = st->root;

    while (current != st->nil) {
        parent = current;

        if (node->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    node->parent = parent;

    if (parent == st->nil) {
        st->root = node;
    } else if (node->key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    node->left = st->nil;
    node->right = st->nil;
    node->color = RED;
}

static void rbt_rotate_left(RBDictionary *st, RBNode *node)
{
    RBNode *child = node->right;

    node->right = child->left;

    if (child->left != st->nil) {
        child->left->parent = node;
    }

    child->parent = node->parent;

    if (node->parent == st->nil) {
        st->root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }

    child->left = node;
    node->parent = child;
}

static void rbt_rotate_right(RBDictionary *st, RBNode *node)
{
    RBNode *child = node->left;

    node->left = child->right;

    if (child->right != st->nil) {
        child->right->parent = node;
    }

    child->parent = node->parent;

    if (node->parent == st->nil) {
        st->root = child;
    } else if (node == node->parent->left) {
        node->parent->left = child;
    } else {
        node->parent->right = child;
    }

    child->right = node;
    node->parent = child;
}

static void rbt_fix_insert(RBDictionary *st, RBNode *node)
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
                    rbt_rotate_left(st, node);
                    parent = node->parent;
                    grand = parent->parent;
                }

                parent->color = BLACK;
                grand->color = RED;
                rbt_rotate_right(st, grand);
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
                    rbt_rotate_right(st, node);
                    parent = node->parent;
                    grand = parent->parent;
                }

                parent->color = BLACK;
                grand->color = RED;
                rbt_rotate_left(st, grand);
            }
        }
    }

    st->root->color = BLACK;
}

void rbt_insert(RBDictionary *st, RBItem key)
{
    RBNode *node;

    if (st == NULL) {
        return;
    }

    node = rbt_node_create(key);

    if (node == NULL) {
        return;
    }

    rbt_node_insert(st, node);
    rbt_fix_insert(st, node);
}

static void rbt_transplant(RBDictionary *st, RBNode *old_node, RBNode *new_node)
{
    if (old_node->parent == st->nil) {
        st->root = new_node;
    } else if (old_node == old_node->parent->left) {
        old_node->parent->left = new_node;
    } else {
        old_node->parent->right = new_node;
    }

    new_node->parent = old_node->parent;
}

static void rbt_fix_delete(RBDictionary *st, RBNode *node)
{
    while (node != st->root && node->color == BLACK) {
        if (node == node->parent->left) {
            RBNode *sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rbt_rotate_left(st, node->parent);
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
                    rbt_rotate_right(st, sibling);
                    sibling = node->parent->right;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rbt_rotate_left(st, node->parent);
                node = st->root;
            }
        } else {
            RBNode *sibling = node->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rbt_rotate_right(st, node->parent);
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
                    rbt_rotate_left(st, sibling);
                    sibling = node->parent->left;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rbt_rotate_right(st, node->parent);
                node = st->root;
            }
        }
    }
    node->color = BLACK;
}
int rbt_delete(RBDictionary *st, RBItem key)
{
    RBNode *target;
    RBNode *removed;
    RBNode *child;
    Color removed_color;

    if (st == NULL) {
        return 0;
    }

    target = rbt_search(st, key);

    if (target == NULL) {
        return 0;
    }

    removed = target;

    if (target->left != st->nil &&
        target->right != st->nil) {
        removed = rbt_node_search_min(st, target->right);
        target->key = removed->key;
    }

    removed_color = removed->color;

    if (removed->left != st->nil) {
        child = removed->left;
    } else {
        child = removed->right;
    }

    rbt_transplant(st, removed, child);

    if (removed_color == BLACK) {
        rbt_fix_delete(st, child);
    }

    rbt_node_destroy(removed);

    return 1;
}

static void rbt_print_node(RBDictionary *st, RBNode *node, int depth, int black_count)
{
    int i;
    int parent_key = -1;
    char position = 'X';

    if (node == st->nil) {
        return;
    }

    if (node->color == BLACK) {
        black_count++;
    }

    if (node->parent != st->nil) {
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

    if (node->left == st->nil && node->right == st->nil) {
        printf(" --------- %d", black_count);
    }

    printf("\n");

    rbt_print_node(st, node->left, depth + 1, black_count);

    rbt_print_node(st, node->right, depth + 1, black_count);
}

void rbt_print(RBDictionary *st)
{
    if (st == NULL) {
        return;
    }

    rbt_print_node(st, st->root, 0, 0);
}
