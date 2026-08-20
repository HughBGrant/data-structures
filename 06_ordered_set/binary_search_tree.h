#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

typedef int bst_item;
typedef struct bst_node bst_node;
typedef struct binary_search_tree bst_ordered_set;

bst_ordered_set *bst_create(void);
void bst_destroy(bst_ordered_set *os);
void bst_insert(bst_ordered_set *os, bst_item key);
void bst_remove(bst_ordered_set *os, bst_item key);
bst_node *bst_search(bst_ordered_set *os, bst_item key);
bst_item *bst_get(bst_node *node);
void bst_print(bst_ordered_set *os);

#endif