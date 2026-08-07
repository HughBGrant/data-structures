#include "avl_tree.h"
avl_tree *avl_create()
{
    avl_tree *tree = malloc(sizeof(avl_tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;

    return tree;
}
avl_node *avl_node_create(avl_data key)
{
    avl_node *new_node = malloc(sizeof(avl_node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->left = NULL;
    new_node->key = key;
    new_node->height = 1;
    new_node->right = NULL;

    return new_node;
}
void avl_insert(avl_tree *tree, avl_data key)
{
    if (tree == NULL) {
        return;
    }

    if (tree->root == NULL) {
        tree->root = avl_node_create(key);
        return;
    }

    avl_node *current_node = tree->root;

    while (1) {
        if (key == current_node->key) {
            return;
        }

        if (key < current_node->key) {
            if (current_node->left == NULL) {
                current_node->left = avl_node_create(key);
                return;
            }

            current_node = current_node->left;
        } else {
            if (current_node->right == NULL) {
                current_node->right = avl_node_create(key);
                return;
            }

            current_node = current_node->right;
        }
    }
}