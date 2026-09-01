#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef enum {
    RED,
    BLACK
} Color;

typedef int rbt_item;
typedef struct rbt_node rbt_node;
typedef struct rbt_tree rbt_ordered_set;

rbt_ordered_set *rbt_create(void);
void rbt_destroy(rbt_ordered_set *tree);
void rbt_insert(rbt_ordered_set *tree, rbt_item key);
rbt_node *rbt_search(rbt_ordered_set *tree, rbt_item key);
int rbt_delete(rbt_ordered_set *tree, rbt_item key);
void rbt_print(rbt_ordered_set *tree);

#endif
