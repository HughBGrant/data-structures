#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
typedef int avl_data;

typedef struct _avl_node {
    struct _avl_node *left;
    avl_data key;
    size_t height;
    struct _avl_node *right;
} avl_node;

typedef struct {
    avl_node *root;
} avl_tree;

#endif