#include "a_v_l_tree.h"
#include "binary_search_tree.h"
#include "red_black_tree.h"
#include <stdio.h>

void bst_test(void)
{
    bst_ordered_set *os = bst_create();
    bst_item values[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        bst_insert(os, values[i]);
    }

    bst_print(os);
    bst_node *node = bst_search(os, 40);
    if (node != NULL) {
        printf("result: %d\n", *bst_get(node));
    }
    printf("after removing 30: ");
    bst_delete(os, 30);
    bst_print(os);
    bst_destroy(os);
}
void avlt_test(void)
{
    avlt_ordered_set *os = avlt_create();
    avlt_item values[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        avlt_insert(os, values[i]);
    }

    avlt_print(os);
    printf("after removing 30\n");
    avlt_delete(os, 30);
    avlt_print(os);
    avlt_destroy(os);
}
void rbt_test(void)
{
    rbt_node *Nil;
    rbt_node *Tree = NULL;
    rbt_node *Node = NULL;

    Nil = RBT_CreateNode(0);
    Nil->Color = BLACK;

    while (1) {
        int cmd = 0;
        int param = 0;
        char buffer[10];

        printf("Enter command number :\n");
        printf("(1) Create a node, (2) Remove a node, (3) Search a Node\n");
        printf("(4) Display Tree (5) quit\n");
        printf("command number:");

        fgets(buffer, sizeof(buffer) - 1, stdin);
        sscanf(buffer, "%d", &cmd);

        if (cmd < 1 || cmd > 5) {
            printf("Invalid command number.\n");
            continue;
        } else if (cmd == 4) {
            RBT_PrintTree(Tree, 0, 0);
            printf("\n");
            continue;
        } else if (cmd == 5)
            break;

        printf("Enter parameter (1~200) :\n");

        fgets(buffer, sizeof(buffer) - 1, stdin);
        sscanf(buffer, "%d", &param);

        if (param < 1 || param > 200) {
            printf("Invalid parameter.%d\n", param);
            continue;
        }

        switch (cmd) {
        case 1:
            RBT_InsertNode(&Tree, RBT_CreateNode(param));
            break;
        case 2:
            Node = RBT_RemoveNode(&Tree, param);

            if (Node == NULL)
                printf("Not found node to delete:%d\n", param);
            else
                RBT_DestroyNode(Node);

            break;
        case 3:
            Node = RBT_SearchNode(Tree, param);

            if (Node == NULL)
                printf("Not found node:%d\n", param);
            else
                printf("Found Node: %d(Color:%s)\n",
                       Node->data, (Node->Color == RED) ? "RED" : "BLACK");
            break;
        }

        printf("\n");
    }

    RBT_DestroyTree(Tree);
}
int main(void)
{
    int os_number = 1;

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
