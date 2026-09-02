#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

typedef int BSItem;
typedef struct BSNode BSNode;
typedef struct BinarySearchTree BSOrderedSet;

BSOrderedSet *bs_create(void);
void bs_destroy(BSOrderedSet *st);
void bs_insert(BSOrderedSet *st, BSItem key);
void bs_delete(BSOrderedSet *st, BSItem key);
BSNode *bs_search(BSOrderedSet *st, BSItem key);
BSItem *bs_get(BSNode *node);
void bs_print(BSOrderedSet *st);

#endif
