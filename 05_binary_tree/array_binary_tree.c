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
void abt_destroy(abt_binary_tree *bt)
{
    if (bt == NULL) {
        return;
    }
    free(bt->data);
    free(bt);
}
void abt_insert(abt_binary_tree *bt, abt_item data)
{
    if (bt == NULL) {
        return;
    }

    if (bt->count >= bt->capacity) {
        printf("Tree is full.\n");
        return;
    }

    bt->data[bt->count] = data;
    bt->count++;
}
abt_item *abt_get_parent(abt_binary_tree *bt, size_t child_pos)
{
    if (abt_is_empty(bt) || child_pos == 0 || child_pos >= bt->count) {
        return NULL;
    }
    size_t parent_pos = (child_pos - 1) / 2;

    return &bt->data[parent_pos];
}
abt_item *abt_get_left(abt_binary_tree *bt, size_t parent_pos)
{
    if (abt_is_empty(bt) || parent_pos >= bt->count) {
        return NULL;
    }
    size_t left_pos = 2 * parent_pos + 1;
    if (left_pos >= bt->count) {
        return NULL;
    }
    return &bt->data[left_pos];
}
abt_item *abt_get_right(abt_binary_tree *bt, size_t parent_pos)
{
    if (abt_is_empty(bt) || parent_pos >= bt->count) {
        return NULL;
    }

    size_t right_pos = 2 * parent_pos + 2;
    if (right_pos >= bt->count) {
        return NULL;
    }
    return &bt->data[right_pos];
}
void abt_print(abt_binary_tree *bt)
{
    if (bt == NULL) {
        return;
    }
    for (size_t i = 0; i < bt->count; i++) {
        printf("index %zu : %d\n", i, bt->data[i]);
    }
}
bool abt_is_empty(abt_binary_tree *bt)
{
    return bt == NULL || bt->count == 0;
}
size_t abt_size(abt_binary_tree *bt)
{
    return bt ? bt->count : 0;
}