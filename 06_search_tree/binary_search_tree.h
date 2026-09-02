#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

typedef int BSItem;
typedef struct BSNode BSNode;
typedef struct BinarySearchTree BSDictionary;

BSDictionary *bs_create(void);
void bs_destroy(BSDictionary *st);
void bs_insert(BSDictionary *st, BSItem key);
void bs_delete(BSDictionary *st, BSItem key);
BSNode *bs_search(BSDictionary *st, BSItem key);
BSItem *bs_get(BSNode *node);
void bs_print(BSDictionary *st);

#endif
