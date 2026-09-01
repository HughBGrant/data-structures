#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef enum {
    RED,
    BLACK
} Color;

typedef int RBItem;
typedef struct RBNode RBNode;
typedef struct RBTree RBDictionary;

RBDictionary *rbt_create(void);
void rbt_destroy(RBDictionary *tree);
void rbt_insert(RBDictionary *tree, RBItem key);
RBNode *rbt_search(RBDictionary *tree, RBItem key);
int rbt_delete(RBDictionary *tree, RBItem key);
void rbt_print(RBDictionary *tree);

#endif
