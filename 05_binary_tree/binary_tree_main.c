#include "binary_tree.h"
#include "expression_tree.h"

void bt_test(void)
{
    binary_tree *tree = bt_create();
    bt_node *root = bt_node_create(1);
    bt_set_root(tree, root);

    bt_node *B = bt_insert_left(root, 2);
    bt_node *C = bt_insert_left(B, 3);
    bt_node *D = bt_insert_right(B, 4);
    bt_node *E = bt_insert_right(root, 5);
    bt_node *F = bt_insert_left(E, 6);
    bt_node *G = bt_insert_right(E, 7);

    // 트리 출력
    printf("Preorder ...\n");
    bt_preorder(root);
    printf("\n\n");

    printf("Inorder ... \n");
    bt_inorder(root);
    printf("\n\n");

    printf("Postorder ... \n");
    bt_postorder(root);
    printf("\n");

    // 트리 소멸
    bt_destroy(tree);
}

void et_test(void)
{
    binary_tree *tree = bt_create();
    char expression[32] = "71*52-/";
    bt_node *root = build(expression);
    bt_set_root(tree, root);

    // 트리 출력
    printf("Preorder ... \n");
    bt_preorder(root);
    printf("\n\n");

    printf("Inorder ... \n");
    bt_inorder(root);
    printf("\n\n");

    printf("Postorder ... \n");
    bt_postorder(root);
    printf("\n");

    printf("Evaluation Result : %f \n", evaluate(root));

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
    case 1:
        et_test();
        break;
    }
    return 0;
}