#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef int AItem;
typedef struct ArrayBinaryTree ABinaryTree;

ABinaryTree *a_create(void);
void a_destroy(ABinaryTree *bt);
void a_insert(ABinaryTree *bt, AItem data);
AItem *a_get_parent(ABinaryTree *bt, size_t chil_pos);
AItem *a_get_left(ABinaryTree *bt, size_t parent_pos);
AItem *a_get_right(ABinaryTree *bt, size_t parent_pos);
void a_print(ABinaryTree *bt);
bool a_is_empty(ABinaryTree *bt);
size_t a_size(ABinaryTree *bt);

#endif