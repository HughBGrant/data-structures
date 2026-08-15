#include "avl_tree.h"
#include "binary_search_tree.h"
#include "two_three_tree.h"

void bst_test(void)
{
    bst_node *root = NULL;
    bst_data keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = bst_node_insert(root, keys[i]);
    }

    printf("inorder: ");
    bst_inorder(root);
    printf("\n");
    bst_node *node = bst_search(root, 40);
    if (node != NULL) {
        printf("result: %d\n", *bst_key(node));
    }
    printf("after removing 30: ");
    bst_node_remove(root, 30);
    bst_inorder(root);
    bst_subtree_destroy(root);
}
void avl_test(void)
{
    avl_node *root = NULL;
    int keys[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = avl_node_insert(root, keys[i]);
    }
    printf("Root after rebalancing: %d\n", root->key);
    printf("In-order: ");
    avl_inorder(root);
    printf("\n");

    printf("remove 20\n");
    root = avl_node_remove(root, 20);
    avl_inorder(root);
    printf("\n");

    avl_subtree_destroy(root);
}
void ttt_test(void)
{
    Tree23 tree;

    tree23_init(&tree);

    int values[] = {
        50, 20, 70,
        10, 30, 60, 80,
        25, 27, 26,
        5, 15,
        65, 90};

    int size =
        sizeof(values) /
        sizeof(values[0]);

    /* 삽입 */
    for (int i = 0; i < size; ++i) {

        tree23_insert(
            &tree,
            values[i]);
    }

    /* 트리 구조 */
    printf("Tree structure:\n");

    tree23_print_structure(&tree);

    /* 중위 순회 */
    printf("\nInorder:\n");

    tree23_print_inorder(&tree);

    /* 탐색 */
    printf(
        "\nSearch 27: %s\n",
        tree23_search(&tree, 27)
            ? "found"
            : "not found");

    printf(
        "Search 99: %s\n",
        tree23_search(&tree, 99)
            ? "found"
            : "not found");

    /* 메모리 해제 */
    tree23_destroy(&tree);
}
int main(void)
{
    int set_number = 0;

    switch (set_number) {
    case 0:
        bst_test();
        break;
    case 1:
        avl_test();
        break;
    }
    return 0;
}
