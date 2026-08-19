#include "avl_tree.h"
#include "binary_search_tree.h"
#include <stdio.h>

void bst_test(void)
{
    bst_node *root = NULL;
    bst_item keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = bst_node_insert(root, keys[i]);
    }

    printf("inorder: ");
    bst_inorder(root);
    printf("\n");
    bst_node *node = bst_search(root, 40);
    if (node != NULL) {
        printf("result: %d\n", *bst_key(node));
    }
    printf("after removing 30: ");
    bst_node_remove(root, 30);
    bst_inorder(root);
    bst_subtree_destroy(root);
}
void avl_test(void)
{
    avl_node *root = NULL;
    avl_item keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = avl_node_insert(root, keys[i]);
    }
    printf("Root after rebalancing: %d\n", root->key);
    printf("In-order: ");
    avl_inorder(root);
    printf("\n");

    printf("remove 20\n");
    root = avl_node_remove(root, 20);
    avl_inorder(root);
    printf("\n");

    avl_subtree_destroy(root);
}
int main(void)
{
    int set_number = 0;

    switch (set_number) {
    case 0:
        bst_test();
        break;
    case 1:
        avl_test();
        break;
    }
    return 0;
}
