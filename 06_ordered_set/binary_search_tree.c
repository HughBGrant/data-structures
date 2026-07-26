#include "binary_search_tree.h"

binary_search_tree *bst_create()
{
    binary_search_tree *tree = malloc(sizeof(binary_search_tree));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;

    return tree;
}
/* 새로운 노드 생성 */
bst_node *bst_create_node(int key)
{
    bst_node *node = malloc(sizeof(bst_node));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }

    node->data = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}
/* 노드 삽입 */
void bst_insert(binary_search_tree *tree, int key)
{
    if (tree == NULL) {
        return;
    }
    /* 루트가 비어 있는 경우 */
    if (tree->root == NULL) {
        tree->root = bst_create_node(key);
        return;
    }
    bst_node *current_node = tree->root;
    bst_node *parent_node = NULL;

    while (current_node != NULL) {
        if (key == current_node->data) {
            return;
        }
        parent_node = current_node;
        if (key < current_node->data) {
            current_node = current_node->left;
        } else if (key > current_node->data) {
            current_node = current_node->right;
        }
    }

    bst_node *new_node = bst_create_node(key);
    if (new_node == NULL) {
        return;
    }

    if (key < parent_node->data) {
        parent_node->left = new_node;
    } else {
        parent_node->right = new_node;
    }
}
/* 중위 순회 */
void bst_inorder(bst_node *node)
{
    if (node == NULL) {
        return;
    }
    bst_inorder(node->left);
    printf("%d, ", node->data);
    bst_inorder(node->right);
}
/* 노드 검색 */
bst_node *bst_search(binary_search_tree *tree, int key)
{
    if (tree == NULL) {
        return NULL;
    }
    bst_node *current_node = tree->root;
    while (current_node != NULL) {
        if (key == current_node->data) {
            return current_node;
        } else if (key < current_node->data) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }
    return NULL;
}

/* 동적 할당된 노드 해제 */
void bst_destroy_subtree(bst_node *subtree)
{
    if (subtree == NULL) {
        return;
    }
    bst_destroy_subtree(subtree->left);
    bst_destroy_subtree(subtree->right);
    free(subtree);
}
void bst_destroy(binary_search_tree *tree)
{
    if (tree == NULL) {
        return;
    }
    bst_destroy_subtree(tree->root);
    free(tree);
}
