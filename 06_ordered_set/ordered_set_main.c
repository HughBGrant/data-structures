#include "avl_tree.h"
#include "binary_search_tree.h"

void bst_test(void)
{
    binary_search_tree *bst = bst_create();

    bst_insert(bst, 50);
    bst_insert(bst, 30);
    bst_insert(bst, 70);
    bst_insert(bst, 20);
    bst_insert(bst, 40);

    printf("inorder: ");
    bst_print(bst);
    bst_node *node = bst_search(bst, 40);
    if (node != NULL) {
        printf("result: %d\n", *bst_key(node));
    }
    printf("after removing 30: ");
    bst_remove(bst, 30);
    bst_print(bst);

    bst_destroy(bst);
}
void avl_test(void)
{
    avl_node *root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = avl_node_insert(root, keys[i]);
    }
    printf("Root after rebalancing: %d\n", root->key);
    printf("In-order: ");
    avl_inorder(root);
    printf("\n");
}
int main(void)
{
    int set_number = 1;

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
