#include "binary_search_tree.h"

int main(void)
{
    binary_search_tree *bst = bst_create();

    bst_insert(bst, 10);
    bst_insert(bst, 5);
    bst_insert(bst, 20);
    bst_insert(bst, 8);
    bst_insert(bst, 30);
    /* 중위 순회 */
    bst_inorder(bst->root);
    printf("\n");

    bst_node *temp = bst_search(bst, 2);

    if (temp != NULL) {
        printf("%d\n", temp->data);
    } else {
        printf("Element not found\n");
    }

    bst_destroy(bst);

    return 0;
}