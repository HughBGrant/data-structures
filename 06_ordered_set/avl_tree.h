#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stddef.h>

typedef int avl_data;

typedef struct _avl_node {
    avl_data key;
    size_t height;
    struct _avl_node *left;
    struct _avl_node *right;
} avl_node;

avl_node *avl_node_create(avl_data key);
void avl_node_destroy(avl_node *node);
void avl_subtree_destroy(avl_node *node);
avl_node *avl_node_insert(avl_node *node, avl_data key);
avl_node *avl_node_remove(avl_node *p, avl_data key);
avl_node *avl_rebalance(avl_node *node);
void avl_update_height(avl_node *node);
size_t avl_height(avl_node *node);
size_t avl_max(size_t a, size_t b);
int avl_balancefactor(avl_node *node);
avl_node *avl_rotate_right(avl_node *y);
avl_node *avl_rotate_left(avl_node *x);
avl_node *avl_find_min(avl_node *node);
void avl_inorder(avl_node *node);

#endif