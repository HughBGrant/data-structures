#ifndef A_V_L_TREE_H
#define A_V_L_TREE_H

#include <stddef.h>

typedef int AVLItem;
typedef struct AVLNode AVLNode;
typedef struct AVLTree AVLDictionary;

AVLDictionary *avl_create(void);
void avl_destroy(AVLDictionary *os);
void avl_insert(AVLDictionary *os, AVLItem key);
void avl_delete(AVLDictionary *os, AVLItem key);
AVLNode *avl_search(AVLDictionary *os, AVLItem key);
AVLItem *avl_get(AVLNode *node);
void avl_print(AVLDictionary *os);

#endif