#include "array_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

abt_tree *abt_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    abt_tree *tree = malloc(sizeof(abt_tree));
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
void abt_destroy(abt_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    free(tree->items);
    free(tree);
}
void abt_insert(abt_tree *tree, abt_data data)
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
abt_data *abt_get_parent(abt_tree *tree, size_t child_pos)
{
    if (abt_is_empty(tree) || child_pos == 0 || child_pos >= tree->count) {
        return NULL;
    }
    size_t parent_pos = (child_pos - 1) / 2;

    return &tree->items[parent_pos];
}
abt_data *abt_get_left(abt_tree *tree, size_t parent_pos)
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
abt_data *abt_get_right(abt_tree *tree, size_t parent_pos)
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
void abt_print(abt_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    for (size_t i = 0; i < tree->count; i++) {
        printf("index %zu : %d\n", i, tree->items[i]);
    }
}
bool abt_is_empty(abt_tree *tree)
{
    return tree == NULL || tree->count == 0;
}
size_t abt_size(abt_tree *tree)
{
    return tree ? tree->count : 0;
}