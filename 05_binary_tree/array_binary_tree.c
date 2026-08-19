#include "array_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct array_binary_tree {
    abt_item *data;
    size_t capacity;
    size_t count;
};

abt_binary_tree *abt_create(size_t capacity)
{
    if (capacity == 0) {
        capacity = 1;
    }
    abt_binary_tree *tree = malloc(sizeof(abt_binary_tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->data = malloc(sizeof(abt_item) * capacity);
    if (tree->data == NULL) {
        free(tree);
        return NULL;
    }
    tree->capacity = capacity;
    tree->count = 0;

    return tree;
}
void abt_destroy(abt_binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    free(tree->data);
    free(tree);
}
void abt_insert(abt_binary_tree *tree, abt_item data)
{
    if (tree == NULL) {
        return;
    }

    if (tree->count >= tree->capacity) {
        printf("Tree is full.\n");
        return;
    }

    tree->data[tree->count] = data;
    tree->count++;
}
abt_item *abt_get_parent(abt_binary_tree *tree, size_t child_pos)
{
    if (abt_is_empty(tree) || child_pos == 0 || child_pos >= tree->count) {
        return NULL;
    }
    size_t parent_pos = (child_pos - 1) / 2;

    return &tree->data[parent_pos];
}
abt_item *abt_get_left(abt_binary_tree *tree, size_t parent_pos)
{
    if (abt_is_empty(tree) || parent_pos >= tree->count) {
        return NULL;
    }
    size_t left_pos = 2 * parent_pos + 1;
    if (left_pos >= tree->count) {
        return NULL;
    }
    return &tree->data[left_pos];
}
abt_item *abt_get_right(abt_binary_tree *tree, size_t parent_pos)
{
    if (abt_is_empty(tree) || parent_pos >= tree->count) {
        return NULL;
    }

    size_t right_pos = 2 * parent_pos + 2;
    if (right_pos >= tree->count) {
        return NULL;
    }
    return &tree->data[right_pos];
}
void abt_print(abt_binary_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    for (size_t i = 0; i < tree->count; i++) {
        printf("index %zu : %d\n", i, tree->data[i]);
    }
}
bool abt_is_empty(abt_binary_tree *tree)
{
    return tree == NULL || tree->count == 0;
}
size_t abt_size(abt_binary_tree *tree)
{
    return tree ? tree->count : 0;
}