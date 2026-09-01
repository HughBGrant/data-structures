#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

typedef int BSItem;
typedef struct BSNode BSNode;
typedef struct BinarySearchTree BSDictionary;

BSDictionary *bst_create(void);
void bst_destroy(BSDictionary *os);
void bst_insert(BSDictionary *os, BSItem key);
void bst_delete(BSDictionary *os, BSItem key);
BSNode *bst_search(BSDictionary *os, BSItem key);
BSItem *bst_get(BSNode *node);
void bst_print(BSDictionary *os);

#endif
