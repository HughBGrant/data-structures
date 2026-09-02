#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef enum {
    RED,
    BLACK
} Color;

typedef int RBItem;
typedef struct RBNode RBNode;
typedef struct RedBlackTree RBDictionary;

RBDictionary *rb_create(void);
void rb_destroy(RBDictionary *st);
void rb_insert(RBDictionary *st, RBItem key);
RBNode *rb_search(RBDictionary *st, RBItem key);
int rb_delete(RBDictionary *st, RBItem key);
void rb_print(RBDictionary *st);

#endif
