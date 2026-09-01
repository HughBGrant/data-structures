#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int rbt_item;

typedef struct _rbt_node {
    rbt_item data;
    struct _rbt_node *parent;
    struct _rbt_node *left;
    struct _rbt_node *right;

    enum { RED,
           BLACK } Color;

} rbt_node;

void rbt_destroy(rbt_node *node);

rbt_node *rbt_node_create(rbt_item data);
void rbt_node_destroy(rbt_node *node);

rbt_node *rbt_node_search(rbt_node *node, rbt_item target);
rbt_node *rbt_node_search_min(rbt_node *node);
void rbt_node_insert(rbt_node **node, rbt_node *child);
void rbt_node_insert_helper(rbt_node **node, rbt_node *child);
rbt_node *rbt_node_delete(rbt_node **root, rbt_item target);
void rbt_rebuild_after_insert(rbt_node **node, rbt_node *child);
void rbt_rebuild_after_delete(rbt_node **root, rbt_node *x);

void rbt_node_print(rbt_node *node, int depth, int black_size);
void rbt_rotate_left(rbt_node **root, rbt_node *parent);
void rbt_rotate_right(rbt_node **root, rbt_node *parent);

#endif
