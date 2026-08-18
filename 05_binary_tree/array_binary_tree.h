#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef int abt_data;

typedef struct {
    abt_data *items;
    size_t capacity;
    size_t count;
} array_binary_tree;

array_binary_tree *abt_create(size_t capacity);
void abt_destroy(array_binary_tree *tree);
void abt_insert(array_binary_tree *tree, abt_data data);
abt_data *abt_get_parent(array_binary_tree *tree, size_t child_pos);
abt_data *abt_get_left(array_binary_tree *tree, size_t parent_pos);
abt_data *abt_get_right(array_binary_tree *tree, size_t parent_pos);
void abt_print(array_binary_tree *tree);
bool abt_is_empty(array_binary_tree *tree);
size_t abt_size(array_binary_tree *tree);

#endif