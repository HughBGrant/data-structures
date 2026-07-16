#include "linked_binary_tree.h"

void lbt_test(void)
{
    linked_binary_tree *tree = lbt_create('A');
    lbt_node *A = tree->root;
    lbt_node *B = lbt_create_node('B');
    lbt_node *C = lbt_create_node('C');
    lbt_node *D = lbt_create_node('D');
    lbt_node *E = lbt_create_node('E');
    lbt_node *F = lbt_create_node('F');
    lbt_node *G = lbt_create_node('G');

    // 트리에 노드 추가
    lbt_insert_left(A, B);
    lbt_insert_left(B, C);
    lbt_insert_right(B, D);

    lbt_insert_right(A, E);
    lbt_insert_left(E, F);
    lbt_insert_right(E, G);

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