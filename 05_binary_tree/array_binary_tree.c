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
    if (tree->count >= tree->capacity) {
        printf("Tree is full.\n");
        return;
    }

    tree->items[tree->count] = data;
    tree->count++;
}
abt_data *abt_parent(array_binary_tree *tree, size_t pos)
{
    if (pos == 0) {
        return NULL;
    }

    return &tree->items[(pos - 1) / 2];
}
abt_data *abt_left(array_binary_tree *tree, size_t pos)
{
    return &tree->items[2 * pos + 1];
}
abt_data *abt_right(array_binary_tree *tree, size_t pos)
{
    return &tree->items[2 * pos + 2];
}
void abt_print(array_binary_tree *tree)
{
    for (int i = 0; i < tree->count; i++) {
        printf("index %d : %d\n", i, tree->items[i]);
    }
}