#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

typedef int BSItem;
typedef struct BSNode BSNode;
typedef struct BinarySearchTree BSDictionary;

BSDictionary *bst_create(void);
void bst_destroy(BSDictionary *st);
void bst_insert(BSDictionary *st, BSItem key);
void bst_delete(BSDictionary *st, BSItem key);
BSNode *bst_search(BSDictionary *st, BSItem key);
BSItem *bst_get(BSNode *node);
void bst_print(BSDictionary *st);

#endif
