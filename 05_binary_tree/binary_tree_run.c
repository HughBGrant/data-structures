#include "binary_tree.h"

void bt_test(void)
{

    binary_tree *tree = bt_create();
    bt_node *A = bt_set_root(tree, 1);
    bt_node *B = bt_add_left(A, 2);
    bt_node *C = bt_add_left(B, 3);
    bt_node *D = bt_add_right(B, 4);
    bt_node *E = bt_add_right(A, 5);
    bt_node *F = bt_add_left(E, 6);
    bt_node *G = bt_add_right(E, 7);

    // 트리 출력
    printf("Preorder ...\n");
    bt_preorder(A);
    printf("\n\n");

    printf("Inorder ... \n");
    bt_inorder(A);
    printf("\n\n");

    printf("Postorder ... \n");
    bt_postorder(A);
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