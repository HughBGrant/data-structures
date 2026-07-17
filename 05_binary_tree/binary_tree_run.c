#include "binary_tree.h"

void bt_test(void)
{
    binary_tree *tree = bt_create();
    bt_node *A = bt_set_root(tree, 'A');
    bt_node *B = bt_add_left(A, 'B');
    bt_node *C = bt_add_left(B, 'C');
    bt_node *D = bt_add_right(B, 'D');
    bt_node *E = bt_add_right(A, 'E');
    bt_node *F = bt_add_left(E, 'F');
    bt_node *G = bt_add_right(E, 'G');

    // 트리 출력
    printf("Preorder ...\n");
    bt_preorder(tree->root);
    printf("\n\n");

    printf("Inorder ... \n");
    bt_inorder(tree->root);
    printf("\n\n");

    printf("Postorder ... \n");
    bt_postorder(tree->root);
    printf("\n");

    // 트리 소멸
    bt_destroy(tree);
}
int main(void)
{
    int tree_number = 0;

    switch (tree_number) {
    case 0:
        bt_test();
        break;
    }
    return 0;
}