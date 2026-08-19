#ifndef A_V_L_TREE_H
#define A_V_L_TREE_H

#include <stddef.h>

typedef int avlt_item;

typedef struct _avlt_node {
    avlt_item key;
    size_t height;
    struct _avlt_node *left;
    struct _avlt_node *right;
} avlt_node;

struct a_v_l_tree {
    avlt_node *root;
};

typedef struct a_v_l_tree avlt_ordered_set;

avlt_node *avlt_node_insert(avlt_node *node, avlt_item key);
avlt_node *avlt_node_remove(avlt_node *p, avlt_item key);
avlt_node *avlt_rebalance(avlt_node *node);
void avlt_update_height(avlt_node *node);
size_t avlt_height(avlt_node *node);
size_t avlt_max(size_t a, size_t b);
int avlt_balancefactor(avlt_node *node);
avlt_node *avlt_rotate_right(avlt_node *y);
avlt_node *avlt_rotate_left(avlt_node *x);
avlt_node *avlt_find_min(avlt_node *node);
void avlt_inorder(avlt_node *node);

avlt_node *avlt_node_create(avlt_item key);
void avlt_node_destroy(avlt_node *node);
void avlt_subtree_destroy(avlt_node *node);

#endif