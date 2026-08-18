#include "array_binary_tree.h"
#include "expression_tree.h"
#include "linked_binary_tree.h"
#include <stdio.h>

void abt_test(void)
{
    array_binary_tree *tree = abt_create(32);

    abt_data data[] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < 7; i++) {
        abt_insert(tree, data[i]);
    }

    abt_print(tree);

    printf("\n");
    printf("left of 20: %d\n", *abt_get_left(tree, 1));

    printf("right of 20: %d\n", *abt_get_right(tree, 1));

    printf("parent of 50: %d\n", *abt_get_parent(tree, 4));

    abt_destroy(tree);
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