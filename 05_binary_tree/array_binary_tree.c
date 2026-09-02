#include "array_binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 32

struct ArrayBinaryTree {
    AItem *items;
    size_t capacity;
    size_t size;
};

ABinaryTree *a_create(void)
{
    ABinaryTree *bt = malloc(sizeof(ABinaryTree));
    if (bt == NULL) {
        return NULL;
    }

    size_t capacity = INITIAL_CAPACITY;
    bt->items = malloc(sizeof(AItem) * capacity);
    if (bt->items == NULL) {
        free(bt);
        return NULL;
    }
    bt->capacity = capacity;
    bt->size = 0;

    return bt;
}
void a_destroy(ABinaryTree *bt)
{
    if (bt == NULL) {
        return;
    }
    free(bt->items);
    free(bt);
}
void a_insert(ABinaryTree *bt, AItem data)
{
    if (bt == NULL) {
        return;
    }

    if (bt->size == bt->capacity) {
        return;
    }

    bt->items[bt->size] = data;
    bt->size++;
}
AItem *a_get_parent(ABinaryTree *bt, size_t chil_pos)
{
    if (a_is_empty(bt) || chil_pos == 0 || chil_pos >= bt->size) {
        return NULL;
    }
    size_t parent_pos = (chil_pos - 1) / 2;

    return &bt->items[parent_pos];
}
AItem *a_get_left(ABinaryTree *bt, size_t parent_pos)
{
    if (a_is_empty(bt) || parent_pos >= bt->size) {
        return NULL;
    }
    size_t left_pos = 2 * parent_pos + 1;
    if (left_pos >= bt->size) {
        return NULL;
    }
    return &bt->items[left_pos];
}
AItem *a_get_right(ABinaryTree *bt, size_t parent_pos)
{
    if (a_is_empty(bt) || parent_pos >= bt->size) {
        return NULL;
    }

    size_t right_pos = 2 * parent_pos + 2;
    if (right_pos >= bt->size) {
        return NULL;
    }
    return &bt->items[right_pos];
}
void a_print(ABinaryTree *bt)
{
    if (bt == NULL) {
        return;
    }
    for (size_t i = 0; i < bt->size; i++) {
        printf("index %zu : %d\n", i, bt->items[i]);
    }
}
bool a_is_empty(ABinaryTree *bt)
{
    return bt == NULL || bt->size == 0;
}
size_t a_size(ABinaryTree *bt)
{
    return bt ? bt->size : 0;
}