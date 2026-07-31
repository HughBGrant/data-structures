#include "binary_search_tree.h"

int main(void)
{
    binary_search_tree *bst = bst_create();

    bst_insert(bst, 50);
    bst_insert(bst, 30);
    bst_insert(bst, 70);
    bst_insert(bst, 20);
    bst_insert(bst, 40);

    printf("inorder: ");
    bst_node_inorder(bst->root);
    printf("\n");

    bst_node *node = bst_search(bst, 40);

    if (node != NULL) {
        printf("result: %d\n", node->data);
    }

    printf("min: %d\n",
           bst_node_get_min(bst->root)->data);

    bst->root = bst_node_remove(bst->root, 30);

    printf("after removing 30: ");
    bst_node_inorder(bst->root);
    printf("\n");

    bst_destroy(bst);

    return 0;
}