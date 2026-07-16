#include "linked_binary_tree_old.h"

void lbto_test(void)
{
    linked_binary_tree_old *tree = lbto_create('A');
    lbto_node *A = tree->root;
    lbto_node *B = lbto_create_node('B');
    lbto_node *C = lbto_create_node('C');
    lbto_node *D = lbto_create_node('D');
    lbto_node *E = lbto_create_node('E');
    lbto_node *F = lbto_create_node('F');
    lbto_node *G = lbto_create_node('G');

    // 트리에 노드 추가
    lbto_insert_left(A, B);
    lbto_insert_left(B, C);
    lbto_insert_right(B, D);

    lbto_insert_right(A, E);
    lbto_insert_left(E, F);
    lbto_insert_right(E, G);

    // 트리 출력
    printf("Preorder ...\n");
    lbto_preorder(tree->root);
    printf("\n\n");

    printf("Inorder ... \n");
    lbto_inorder(tree->root);
    printf("\n\n");

    printf("Postorder ... \n");
    lbto_postorder(tree->root);
    printf("\n");

    // 트리 소멸
    lbto_destroy(tree);
}
int main(void)
{

    int tree_number = 0;

    switch (tree_number) {
    case 0:
        lbto_test();
        break;
    }
    return 0;
}