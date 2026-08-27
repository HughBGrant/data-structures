#include "a_v_l_tree.h"
#include "binary_search_tree.h"
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
    }
    return 0;
}
