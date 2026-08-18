#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#include <stddef.h>

typedef int abt_data;

typedef struct {
    abt_data *items;
    size_t capacity;
    size_t count;
} array_binary_tree;

array_binary_tree *abt_create(size_t capacity);
void abt_insert(array_binary_tree *tree, abt_data data);
abt_data *abt_parent(array_binary_tree *tree, size_t pos);
abt_data *abt_left(array_binary_tree *tree, size_t pos);
abt_data *abt_right(array_binary_tree *tree, size_t pos);
void abt_print(array_binary_tree *tree);

#endif