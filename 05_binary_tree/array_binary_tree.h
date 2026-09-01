#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef int AItem;
typedef struct ArrayBinaryTree ABinaryTree;

void abt_insert(ABinaryTree *bt, AItem value);
AItem *abt_get_parent(ABinaryTree *bt, size_t child_pos);
AItem *abt_get_left(ABinaryTree *bt, size_t parent_pos);
AItem *abt_get_right(ABinaryTree *bt, size_t parent_pos);
void abt_print(ABinaryTree *bt);
bool abt_is_empty(ABinaryTree *bt);
size_t abt_size(ABinaryTree *bt);

ABinaryTree *abt_create(void);
void abt_destroy(ABinaryTree *bt);

#endif