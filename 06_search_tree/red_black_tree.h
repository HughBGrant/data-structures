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
void rbt_destroy(RBDictionary *st);
void rbt_insert(RBDictionary *st, RBItem key);
RBNode *rbt_search(RBDictionary *st, RBItem key);
int rbt_delete(RBDictionary *st, RBItem key);
void rbt_print(RBDictionary *st);

#endif
