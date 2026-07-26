#include "binary_search_tree.h"

/* BST 초기화 */
void bst_create(binary_search_tree *bst)
{
    bst->root = NULL;
}

/* 새로운 노드 생성 */
bst_node *bst_create_node(int key)
{
    bst_node *node = (bst_node *)malloc(sizeof(bst_node));

    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(EXIT_FAILURE);
    }

    node->data = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* 노드 삽입 */
void bst_insert(binary_search_tree *bst, int key)
{
    bst_node *t = bst->root;
    bst_node *p;
    bst_node *r = NULL;

    /* 루트가 비어 있는 경우 */
    if (bst->root == NULL) {
        bst->root = bst_create_node(key);
        return;
    }

    while (t != NULL) {
        r = t;

        if (key < t->data) {
            t = t->left;
        } else if (key > t->data) {
            t = t->right;
        } else {
            /* 중복된 값은 삽입하지 않음 */
            return;
        }
    }

    p = bst_create_node(key);

    if (key < r->data) {
        r->left = p;
    } else {
        r->right = p;
    }
}

/* 중위 순회 */
void bst_inorder(bst_node *p)
{
    if (p != NULL) {
        bst_inorder(p->left);
        printf("%d, ", p->data);
        bst_inorder(p->right);
    }
}

/* 노드 검색 */
bst_node *bst_search(binary_search_tree *bst, int key)
{
    bst_node *t = bst->root;

    while (t != NULL) {
        if (key == t->data) {
            return t;
        } else if (key < t->data) {
            t = t->left;
        } else {
            t = t->right;
        }
    }

    return NULL;
}

/* 동적 할당된 노드 해제 */
void bst_destroy_node(bst_node *p)
{
    if (p == NULL) {
        return;
    }
    bst_destroy_node(p->left);
    bst_destroy_node(p->right);
    free(p);
}

int main(void)
{
    binary_search_tree bst;
    bst_node *temp;

    bst_create(&bst);

    /* 삽입 */
    bst_insert(&bst, 10);
    bst_insert(&bst, 5);
    bst_insert(&bst, 20);
    bst_insert(&bst, 8);
    bst_insert(&bst, 30);

    /* 중위 순회 */
    bst_inorder(bst.root);
    printf("\n");

    /* 검색 */
    temp = bst_search(&bst, 2);

    if (temp != NULL) {
        printf("%d\n", temp->data);
    } else {
        printf("Element not found\n");
    }

    bst_destroy_node(bst.root);

    return 0;
}