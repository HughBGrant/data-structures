#include "linked_binary_tree.h"

void lbt_test(void)
{
    linked_binary_tree *tree = lbt_create();
    lbt_node *A = lbt_set_root(tree, 'A');
    lbt_node *B = lbt_add_left(A, 'B');
    lbt_node *C = lbt_add_left(B, 'C');
    lbt_node *D = lbt_add_right(B, 'D');
    lbt_node *E = lbt_add_right(A, 'E');
    lbt_node *F = lbt_add_left(E, 'F');
    lbt_node *G = lbt_add_right(E, 'G');

    // 트리 출력
    printf("Preorder ...\n");
    lbt_preorder(tree->root);
    printf("\n\n");

    printf("Inorder ... \n");
    lbt_inorder(tree->root);
    printf("\n\n");

    printf("Postorder ... \n");
    lbt_postorder(tree->root);
    printf("\n");

    // 트리 소멸
    lbt_destroy(tree);
}
int main(void)
{
    int tree_number = 0;

    switch (tree_number) {
    case 0:
        lbt_test();
        break;
    }
    return 0;
}