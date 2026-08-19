#include "a_v_l_tree.h"
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
void avlt_test(void)
{
    avlt_node *root = NULL;
    avlt_item keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = avlt_node_insert(root, keys[i]);
    }
    printf("Root after rebalancing: %d\n", root->key);
    printf("In-order: ");
    avlt_inorder(root);
    printf("\n");

    printf("remove 20\n");
    root = avlt_node_remove(root, 20);
    avlt_inorder(root);
    printf("\n");

    avlt_subtree_destroy(root);
}
int main(void)
{
    int os_number = 1;

    switch (os_number) {
    case 0:
        bst_test();
        break;
    case 1:
        avlt_test();
        break;
    }
    return 0;
}
