#include "a_v_l_tree.h"
#include "binary_search_tree.h"
#include "red_black_tree.h"
#include <stdio.h>

void bst_test(void)
{
    BSDictionary *os = bst_create();
    BSItem datas[] = {10, 20, 30, 40, 50, 25};

    for (int i = 0; i < 6; i++)
        bst_insert(os, datas[i]);

    bst_print(os);

    BSNode *node = bst_search(os, 40);

    if (node != NULL)
        printf("result: %d\n", *bst_get(node));

    printf("after removing 30: ");
    bst_delete(os, 30);
    bst_print(os);

    bst_destroy(os);
}

void avlt_test(void)
{
    AVLDictionary *os = avlt_create();
    AVLItem datas[] = {10, 20, 30, 40, 50, 25};

    for (int i = 0; i < 6; i++)
        avlt_insert(os, datas[i]);

    avlt_print(os);

    printf("after removing 30\n");
    avlt_delete(os, 30);
    avlt_print(os);

    avlt_destroy(os);
}

void rbt_test(void)
{
    RBDictionary *os = rbt_create();

    if (os == NULL)
        return;

    while (1) {
        int cmd;
        int param;
        char buffer[10];

        printf("Enter command number :\n");
        printf("(1) Create a node, (2) Remove a node, (3) Search a Node\n");
        printf("(4) Display Tree (5) quit\n");
        printf("command number:");

        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &cmd);

        if (cmd < 1 || cmd > 5) {
            printf("Invalid command number.\n");
            continue;
        }

        if (cmd == 4) {
            rbt_print(os);
            printf("\n");
            continue;
        }

        if (cmd == 5)
            break;

        printf("Enter parameter (1~200) :\n");

        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &param);

        if (param < 1 || param > 200) {
            printf("Invalid parameter.%d\n", param);
            continue;
        }

        switch (cmd) {
        case 1:
            rbt_insert(os, param);
            break;

        case 2:
            if (!rbt_delete(os, param))
                printf("Not found node to delete:%d\n", param);
            break;

        case 3:
            if (rbt_search(os, param) == NULL)
                printf("Not found node:%d\n", param);
            break;
        }

        printf("\n");
    }

    rbt_destroy(os);
}

int main(void)
{
    int os_number = 2;

    switch (os_number) {
    case 0:
        bst_test();
        break;

    case 1:
        avlt_test();
        break;

    case 2:
        rbt_test();
        break;
    }

    return 0;
}
