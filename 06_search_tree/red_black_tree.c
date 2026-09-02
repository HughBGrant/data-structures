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
struct RedBlackTree {
    RBNode *root;
    RBNode *nil;
};
static void rb_node_destroy(RBNode *node);
static void rb_subtree_destroy(RBDictionary *st, RBNode *node);
static RBNode *rb_node_search(RBDictionary *st, RBNode *node, RBItem key);
static void rb_transplant(RBDictionary *st, RBNode *ol_node, RBNode *new_node);
static void rb_delete_fixup(RBDictionary *st, RBNode *node);
static void rb_node_print(RBDictionary *st, RBNode *node, int depth, int black_count);
static RBNode *rb_node_search_min(RBDictionary *st, RBNode *node);
static void rb_node_insert(RBDictionary *st, RBNode *node);
static void rb_rotate_left(RBDictionary *st, RBNode *node);
static void rb_rotate_right(RBDictionary *st, RBNode *node);
static void rb_insert_fixup(RBDictionary *st, RBNode *node);

RBDictionary *rb_create(void)
{
    RBDictionary *st = malloc(sizeof(RBDictionary));
    if (st == NULL) {
        return NULL;
    }

    st->nil = rb_node_create(0);
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
void rb_destroy(RBDictionary *st)
{
    if (st == NULL) {
        return;
    }
    rb_subtree_destroy(st, st->root);
    rb_node_destroy(st->nil);
    free(st);
}
static RBNode *rb_node_create(RBItem key)
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
static void rb_node_destroy(RBNode *node)
{
    free(node);
}
static void rb_subtree_destroy(RBDictionary *st, RBNode *node)
{
    if (node == st->nil) {
        return;
    }
    rb_subtree_destroy(st, node->left);
    rb_subtree_destroy(st, node->right);
    rb_node_destroy(node);
}
static void rb_rotate_left(RBDictionary *st, RBNode *x)
{
    RBNode *y = x->right;

    x->right = y->left;
    if (y->left != st->nil) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == st->nil) {
        st->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}
static void rb_rotate_right(RBDictionary *st, RBNode *y)
{
    RBNode *x = y->left;

    y->left = x->right;
    if (x->right != st->nil) {
        x->right->parent = y;
    }

    x->parent = y->parent;
    if (y->parent == st->nil) {
        st->root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}
void rb_insert(RBDictionary *st, RBItem key)
{
    if (st == NULL) {
        return;
    }
    RBNode *node = rb_node_create(key);
    if (node == NULL) {
        return;
    }

    rb_node_insert(st, node);
    rb_insert_fixup(st, node);
}
static void rb_node_insert(RBDictionary *st, RBNode *z)
{
    RBNode *y = st->nil;
    RBNode *current = st->root;

    while (current != st->nil) {
        y = current;

        if (z->key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    z->parent = y;

    if (y == st->nil) {
        st->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->left = st->nil;
    z->right = st->nil;
    z->color = RED;
}
static void rb_insert_fixup(RBDictionary *st, RBNode *z)
{
    while (z->parent->color == RED) {
        RBNode *parent = z->parent;
        RBNode *grand = parent->parent;

        if (parent == grand->left) {
            RBNode *uncle = grand->right;

            if (uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                z = grand;
            } else {
                if (z == parent->right) {
                    z = parent;
                    rb_rotate_left(st, z);
                    parent = z->parent;
                    grand = parent->parent;
                }

                parent->color = BLACK;
                grand->color = RED;
                rb_rotate_right(st, grand);
            }
        } else {
            RBNode *uncle = grand->left;

            if (uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grand->color = RED;
                z = grand;
            } else {
                if (z == parent->left) {
                    z = parent;
                    rb_rotate_right(st, z);
                    parent = z->parent;
                    grand = parent->parent;
                }

                parent->color = BLACK;
                grand->color = RED;
                rb_rotate_left(st, grand);
            }
        }
    }

    st->root->color = BLACK;
}
RBNode *rb_search(RBDictionary *st, RBItem key)
{
    if (st == NULL) {
        return NULL;
    }
    return rb_node_search(st, st->root, key);
}
static RBNode *rb_node_search(RBDictionary *st, RBNode *node, RBItem key)
{
    if (node == st->nil || node->key == key) {
        return node == st->nil ? NULL : node;
    }
    if (key < node->key) {
        return rb_node_search(st, node->left, key);
    }
    return rb_node_search(st, node->right, key);
}
static RBNode *rb_node_search_min(RBDictionary *st, RBNode *node)
{
    if (node == st->nil) {
        return st->nil;
    }

    if (node->left == st->nil) {
        return node;
    }

    return rb_node_search_min(st, node->left);
}
static void rb_transplant(RBDictionary *st, RBNode *ol_node, RBNode *new_node)
{
    if (ol_node->parent == st->nil) {
        st->root = new_node;
    } else if (ol_node == ol_node->parent->left) {
        ol_node->parent->left = new_node;
    } else {
        ol_node->parent->right = new_node;
    }

    new_node->parent = ol_node->parent;
}
int rb_delete(RBDictionary *st, RBItem key)
{
    RBNode *target;
    RBNode *removed;
    RBNode *child;
    Color removed_color;

    if (st == NULL) {
        return 0;
    }

    target = rb_search(st, key);

    if (target == NULL) {
        return 0;
    }

    removed = target;

    if (target->left != st->nil &&
        target->right != st->nil) {
        removed = rb_node_search_min(st, target->right);
        target->key = removed->key;
    }

    removed_color = removed->color;

    if (removed->left != st->nil) {
        child = removed->left;
    } else {
        child = removed->right;
    }

    rb_transplant(st, removed, child);

    if (removed_color == BLACK) {
        rb_delete_fixup(st, child);
    }

    rb_node_destroy(removed);

    return 1;
}
static void rb_delete_fixup(RBDictionary *st, RBNode *node)
{
    while (node != st->root && node->color == BLACK) {
        if (node == node->parent->left) {
            RBNode *sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rb_rotate_left(st, node->parent);
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
                    rb_rotate_right(st, sibling);
                    sibling = node->parent->right;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rb_rotate_left(st, node->parent);
                node = st->root;
            }
        } else {
            RBNode *sibling = node->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rb_rotate_right(st, node->parent);
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
                    rb_rotate_left(st, sibling);
                    sibling = node->parent->left;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rb_rotate_right(st, node->parent);
                node = st->root;
            }
        }
    }
    node->color = BLACK;
}
void rb_print(RBDictionary *st)
{
    if (st == NULL) {
        return;
    }

    rb_node_print(st, st->root, 0, 0);
}

static void rb_node_print(RBDictionary *st, RBNode *node, int depth, int black_count)
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

    rb_node_print(st, node->left, depth + 1, black_count);

    rb_node_print(st, node->right, depth + 1, black_count);
}