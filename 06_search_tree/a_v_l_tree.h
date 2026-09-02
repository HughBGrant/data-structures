#ifndef A_V_L_TREE_H
#define A_V_L_TREE_H

#include <stddef.h>

typedef int AVLItem;
typedef struct AVLNode AVLNode;
typedef struct AVLTree AVLDictionary;

AVLDictionary *avlt_create(void);
void avlt_destroy(AVLDictionary *os);
void avlt_insert(AVLDictionary *os, AVLItem key);
void avlt_delete(AVLDictionary *os, AVLItem key);
AVLNode *avlt_search(AVLDictionary *os, AVLItem key);
AVLItem *avlt_get(AVLNode *node);
void avlt_print(AVLDictionary *os);

#endif