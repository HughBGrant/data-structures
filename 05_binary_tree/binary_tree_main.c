#include "array_binary_tree.h"
#include "expression_tree.h"
#include "linked_binary_tree.h"

void abt_test(void)
{
    BinaryTree tree;

    init(&tree);

    insert(&tree, 10);
    insert(&tree, 20);
    insert(&tree, 30);
    insert(&tree, 40);
    insert(&tree, 50);
    insert(&tree, 60);
    insert(&tree, 70);

    printTree(&tree);

    printf("\n");

    printf("20의 왼쪽 자식: %d\n",
           tree.items[leftChild(1)]);

    printf("20의 오른쪽 자식: %d\n",
           tree.items[rightChild(1)]);

    printf("50의 부모: %d\n",
           tree.items[parent(4)]);
}

void lbt_test(void)
{
    lbt_node *root = lbt_node_create(1);

    lbt_node *B = lbt_insert_left(root, 2);
    lbt_node *C = lbt_insert_left(B, 3);
    lbt_node *D = lbt_insert_right(B, 4);
    lbt_node *E = lbt_insert_right(root, 5);
    lbt_node *F = lbt_insert_left(E, 6);
    lbt_node *G = lbt_insert_right(E, 7);

    // 트리 출력
    printf("Preorder ...\n");
    lbt_preorder(root);
    printf("\n\n");

    printf("Inorder ... \n");
    lbt_inorder(root);
    printf("\n\n");

    printf("Postorder ... \n");
    lbt_postorder(root);
    printf("\n");
}

void et_test(void)
{
    char expression[32] = "71*52-/";
    lbt_node *root = build(expression);

    // 트리 출력
    printf("Preorder ... \n");
    lbt_preorder(root);
    printf("\n\n");

    printf("Inorder ... \n");
    lbt_inorder(root);
    printf("\n\n");

    printf("Postorder ... \n");
    lbt_postorder(root);
    printf("\n");

    printf("Evaluation Result : %f \n", evaluate(root));
}
int main(void)
{
    int tree_number = 0;

    switch (tree_number) {
    case 0:
        abt_test();
        break;
    case 1:
        lbt_test();
        break;
    case 2:
        et_test();
        break;
    }
    return 0;
}