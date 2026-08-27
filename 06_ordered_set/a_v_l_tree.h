#ifndef A_V_L_TREE_H
#define A_V_L_TREE_H

#include <stddef.h>

typedef int avlt_item;
typedef struct avlt_node avlt_node;
typedef struct a_v_l_tree avlt_ordered_set;

avlt_ordered_set *avlt_create(void);
void avlt_destroy(avlt_ordered_set *os);
void avlt_insert(avlt_ordered_set *os, avlt_item key);
void avlt_delete(avlt_ordered_set *os, avlt_item key);
avlt_node *avlt_search(avlt_ordered_set *os, avlt_item key);
avlt_item *avlt_get(avlt_node *node);
void avlt_print(avlt_ordered_set *os);

#endif