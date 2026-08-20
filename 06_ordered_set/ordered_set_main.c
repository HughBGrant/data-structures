#include "a_v_l_tree.h"
#include "binary_search_tree.h"
#include <stdio.h>

void bst_test(void)
{
    bst_ordered_set *os = bst_create();
    bst_item items[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        bst_insert(os, items[i]);
    }

    bst_print(os);
    bst_node *node = bst_search(os, 40);
    if (node != NULL) {
        printf("result: %d\n", *bst_get(node));
    }
    printf("after removing 30: ");
    bst_remove(os, 30);
    bst_print(os);
    bst_destroy(os);
}
void avlt_test(void)
{
    avlt_node *root = NULL;
    avlt_item items[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = avlt_node_insert(root, items[i]);
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
    int os_number = 0;

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
