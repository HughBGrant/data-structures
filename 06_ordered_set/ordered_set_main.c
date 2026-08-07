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
        printf("result: %d\n", *bst_node_get_key(node));
    }
    printf("after removing 30: ");
    bst_remove(bst, 30);
    bst_print(bst);

    bst_destroy(bst);
}

int main(void)
{
    int set_number = 0;

    switch (set_number) {
    case 0:
        bst_test();
        break;
    }
    return 0;
}
