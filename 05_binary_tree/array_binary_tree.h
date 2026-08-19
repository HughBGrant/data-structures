#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef int abt_item;
typedef struct array_binary_tree abt_binary_tree;

void abt_insert(abt_binary_tree *tree, abt_item data);
abt_item *abt_get_parent(abt_binary_tree *tree, size_t child_pos);
abt_item *abt_get_left(abt_binary_tree *tree, size_t parent_pos);
abt_item *abt_get_right(abt_binary_tree *tree, size_t parent_pos);
void abt_print(abt_binary_tree *tree);
bool abt_is_empty(abt_binary_tree *tree);
size_t abt_size(abt_binary_tree *tree);

abt_binary_tree *abt_create(size_t capacity);
void abt_destroy(abt_binary_tree *tree);

#endif