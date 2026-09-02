#ifndef A_V_L_TREE_H
#define A_V_L_TREE_H

#include <stddef.h>

typedef int AVLItem;
typedef struct AVLNode AVLNode;
typedef struct AVLTree AVLOrderedSet;

AVLOrderedSet *avl_create(void);
void avl_destroy(AVLOrderedSet *os);
void avl_insert(AVLOrderedSet *os, AVLItem key);
void avl_delete(AVLOrderedSet *os, AVLItem key);
AVLNode *avl_search(AVLOrderedSet *os, AVLItem key);
AVLItem *avl_get(AVLNode *node);
void avl_print(AVLOrderedSet *os);

#endif