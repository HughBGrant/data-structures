#include "array_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

array_binary_tree *abt_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    array_binary_tree *tree = malloc(sizeof(array_binary_tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->items = malloc(sizeof(abt_data) * capacity);
    if (tree->items == NULL) {
        free(tree);
        return NULL;
    }
    tree->capacity = capacity;
    tree->count = 0;

    return tree;
}
void abt_destroy(array_binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    free(tree->items);
    free(tree);
}
void abt_insert(array_binary_tree *tree, abt_data data)
{
    if (tree == NULL) {
        return;
    }

    if (tree->count >= tree->capacity) {
        printf("Tree is full.\n");
        return;
    }

    tree->items[tree->count] = data;
    tree->count++;
}
abt_data *abt_get_parent(array_binary_tree *tree, size_t child_pos)
{
    if (abt_is_empty(tree) || child_pos == 0 || child_pos >= tree->count) {
        return NULL;
    }
    size_t parent_pos = (child_pos - 1) / 2;

    return &tree->items[parent_pos];
}
abt_data *abt_get_left(array_binary_tree *tree, size_t parent_pos)
{
    if (abt_is_empty(tree) || parent_pos >= tree->count) {
        return NULL;
    }
    size_t left_pos = 2 * parent_pos + 1;
    if (left_pos >= tree->count) {
        return NULL;
    }
    return &tree->items[left_pos];
}
abt_data *abt_get_right(array_binary_tree *tree, size_t parent_pos)
{
    if (abt_is_empty(tree) || parent_pos >= tree->count) {
        return NULL;
    }

    size_t right_pos = 2 * parent_pos + 2;
    if (right_pos >= tree->count) {
        return NULL;
    }
    return &tree->items[right_pos];
}
void abt_print(array_binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    for (size_t i = 0; i < tree->count; i++) {
        printf("index %zu : %d\n", i, tree->items[i]);
    }
}
bool abt_is_empty(array_binary_tree *tree)
{
    return tree == NULL || tree->count == 0;
}
size_t abt_size(array_binary_tree *tree)
{
    return tree ? tree->count : 0;
}