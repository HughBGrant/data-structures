#include "array_binary_tree.h"
#include <stdio.h>

void init(BinaryTree *tree)
{
    tree->size = 0;
}

void insert(BinaryTree *tree, int value)
{
    if (tree->size >= MAX_SIZE) {
        printf("Tree is full.\n");
        return;
    }

    tree->items[tree->size] = value;
    tree->size++;
}

int parent(int index)
{
    if (index == 0)
        return -1;

    return (index - 1) / 2;
}

int leftChild(int index)
{
    return 2 * index + 1;
}

int rightChild(int index)
{
    return 2 * index + 2;
}

void printTree(BinaryTree *tree)
{
    for (int i = 0; i < tree->size; i++) {
        printf("index %d : %d\n", i, tree->items[i]);
    }
}