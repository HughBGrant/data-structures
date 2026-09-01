#include "array_binary_tree.h"
#include "linked_binary_tree.h"
#include <stdio.h>

void abt_test(void)
{
    ABinaryTree *bt = abt_create();

    AItem datas[] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < 7; i++) {
        abt_insert(bt, datas[i]);
    }

    abt_print(bt);

    printf("\n");
    printf("left of 20: %d\n", *abt_get_left(bt, 1));

    printf("right of 20: %d\n", *abt_get_right(bt, 1));

    printf("parent of 50: %d\n", *abt_get_parent(bt, 4));

    abt_destroy(bt);
}

void lbt_test(void)
{
    LNode *root = lbt_node_create(1);

    LNode *B = lbt_set_left(root, 2);
    LNode *C = lbt_set_left(B, 3);
    LNode *D = lbt_set_right(B, 4);
    LNode *E = lbt_set_right(root, 5);
    LNode *F = lbt_set_left(E, 6);
    LNode *G = lbt_set_right(E, 7);

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
int main(void)
{
    int bt_number = 1;

    switch (bt_number) {
    case 0:
        abt_test();
        break;
    case 1:
        lbt_test();
        break;
    }
    return 0;
}