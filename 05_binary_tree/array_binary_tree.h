#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef int abt_item;

typedef struct {
    abt_item *data;
    size_t capacity;
    size_t count;
} abt_tree;

void abt_insert(abt_tree *tree, abt_item data);
abt_item *abt_get_parent(abt_tree *tree, size_t child_pos);
abt_item *abt_get_left(abt_tree *tree, size_t parent_pos);
abt_item *abt_get_right(abt_tree *tree, size_t parent_pos);
void abt_print(abt_tree *tree);
bool abt_is_empty(abt_tree *tree);
size_t abt_size(abt_tree *tree);

abt_tree *abt_create(size_t capacity);
void abt_destroy(abt_tree *tree);

#endif