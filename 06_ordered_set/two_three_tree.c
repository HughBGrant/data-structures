#include "two_three_tree.h"

#include <stdio.h>
#include <stdlib.h>

/* =========================
   Node
   ========================= */

struct Node23 {
    int nkeys;        // key 개수: 1 또는 2
    int keys[2];      // 최대 2개의 key
    Node23 *child[3]; // 최대 3개의 자식
};

static Node23 *node_create(int key)
{
    Node23 *node = malloc(sizeof(Node23));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->nkeys = 1;

    node->keys[0] = key;
    node->keys[1] = 0;

    node->child[0] = NULL;
    node->child[1] = NULL;
    node->child[2] = NULL;

    return node;
}

static bool is_leaf(const Node23 *node)
{
    return node->child[0] == NULL;
}

/* =========================
   초기화
   ========================= */

void tree23_init(Tree23 *tree)
{
    tree->root = NULL;
}

/* =========================
   탐색
   ========================= */

bool tree23_search(const Tree23 *tree, int key)
{
    const Node23 *node = tree->root;

    while (node != NULL) {

        if (key == node->keys[0])
            return true;

        if (node->nkeys == 2 &&
            key == node->keys[1])
            return true;

        if (key < node->keys[0]) {

            node = node->child[0];

        } else if (node->nkeys == 1 ||
                   key < node->keys[1]) {

            node = node->child[1];

        } else {

            node = node->child[2];
        }
    }

    return false;
}

/* =========================
   재귀 삽입
   ========================= */

static bool insert_recursive(
    Node23 *node,
    int key,
    int *promoted_key,
    Node23 **new_right)
{
    /* =========================
       Leaf
       ========================= */

    if (is_leaf(node)) {

        /*
            2-node에 삽입

            [10] + 20
              ↓
            [10 | 20]
        */

        if (node->nkeys == 1) {

            if (key < node->keys[0]) {

                node->keys[1] = node->keys[0];
                node->keys[0] = key;

            } else {

                node->keys[1] = key;
            }

            node->nkeys = 2;

            return false;
        }

        /*
            3-node에 삽입

            [10 | 20] + 30

            임시:
            [10 | 20 | 30]

            split:
                 20
                /  \
             [10] [30]
        */

        int temp_keys[3] = {
            node->keys[0],
            node->keys[1],
            key};

        /* key 정렬 */
        for (int i = 0; i < 2; ++i) {

            for (int j = i + 1; j < 3; ++j) {

                if (temp_keys[j] < temp_keys[i]) {

                    int temp = temp_keys[i];

                    temp_keys[i] = temp_keys[j];
                    temp_keys[j] = temp;
                }
            }
        }

        /* 기존 node를 왼쪽 노드로 사용 */
        node->nkeys = 1;
        node->keys[0] = temp_keys[0];
        node->keys[1] = 0;

        /* 가운데 key를 부모로 올림 */
        *promoted_key = temp_keys[1];

        /* 오른쪽 노드 생성 */
        *new_right = node_create(temp_keys[2]);

        return true;
    }

    /* =========================
       Internal Node
       ========================= */

    int child_index;

    /*
             [10 | 20]

         <10   10~20   >20
          ↓      ↓      ↓
          0      1      2
    */

    if (key < node->keys[0]) {

        child_index = 0;

    } else if (node->nkeys == 1 ||
               key < node->keys[1]) {

        child_index = 1;

    } else {

        child_index = 2;
    }

    int child_promoted;
    Node23 *child_new_right = NULL;

    bool child_split =
        insert_recursive(
            node->child[child_index],
            key,
            &child_promoted,
            &child_new_right);

    /* 자식이 split되지 않음 */
    if (!child_split)
        return false;

    /* =========================
       현재 노드가 2-node
       ========================= */

    if (node->nkeys == 1) {

        /*
            왼쪽 자식에서 split
        */

        if (child_index == 0) {

            node->keys[1] = node->keys[0];
            node->keys[0] = child_promoted;

            node->child[2] = node->child[1];
            node->child[1] = child_new_right;
        }

        /*
            오른쪽 자식에서 split
        */

        else {

            node->keys[1] = child_promoted;

            node->child[2] = child_new_right;
        }

        node->nkeys = 2;

        return false;
    }

    /* =========================
       현재 노드도 3-node
       ========================= */

    /*
        현재 노드까지 split해야 한다.

        임시로

        key   : 3개
        child : 4개

        를 만든다.
    */

    int temp_keys[3];
    Node23 *temp_child[4];

    /* promoted key 삽입 */
    int key_index = 0;

    for (int i = 0; i < 3; ++i) {

        if (i == child_index) {

            temp_keys[i] = child_promoted;

        } else {

            temp_keys[i] =
                node->keys[key_index++];
        }
    }

    /* 새로 생긴 오른쪽 자식 삽입 */
    int child_i = 0;

    for (int i = 0; i < 4; ++i) {

        if (i == child_index + 1) {

            temp_child[i] = child_new_right;

        } else {

            temp_child[i] =
                node->child[child_i++];
        }
    }

    /*
        가운데 key를 부모로 올린다.
    */

    *promoted_key = temp_keys[1];

    /*
        기존 node를 왼쪽 노드로 재사용
    */

    node->nkeys = 1;

    node->keys[0] = temp_keys[0];
    node->keys[1] = 0;

    node->child[0] = temp_child[0];
    node->child[1] = temp_child[1];
    node->child[2] = NULL;

    /*
        오른쪽 노드 생성
    */

    Node23 *right =
        node_create(temp_keys[2]);

    right->child[0] = temp_child[2];
    right->child[1] = temp_child[3];

    *new_right = right;

    /*
        현재 node도 split되었음을
        부모에게 알림
    */

    return true;
}

/* =========================
   삽입
   ========================= */

bool tree23_insert(Tree23 *tree, int key)
{
    /* 중복 key 허용하지 않음 */
    if (tree23_search(tree, key))
        return false;

    /* 빈 트리 */
    if (tree->root == NULL) {

        tree->root = node_create(key);

        return true;
    }

    int promoted_key;
    Node23 *new_right = NULL;

    bool root_split =
        insert_recursive(
            tree->root,
            key,
            &promoted_key,
            &new_right);

    /*
        root까지 split된 경우

             [20]

            /    \
         left    right

        새로운 root를 만든다.
    */

    if (root_split) {

        Node23 *old_root = tree->root;

        Node23 *new_root =
            node_create(promoted_key);

        new_root->child[0] = old_root;
        new_root->child[1] = new_right;

        tree->root = new_root;
    }

    return true;
}

/* =========================
   중위 순회
   ========================= */

static void inorder_node(const Node23 *node)
{
    if (node == NULL)
        return;

    /*
        2-node

             [10]
             /  \

        child0
        10
        child1
    */

    if (node->nkeys == 1) {

        inorder_node(node->child[0]);

        printf("%d ", node->keys[0]);

        inorder_node(node->child[1]);
    }

    /*
        3-node

             [10 | 20]
             /   |   \

        child0
        10
        child1
        20
        child2
    */

    else {

        inorder_node(node->child[0]);

        printf("%d ", node->keys[0]);

        inorder_node(node->child[1]);

        printf("%d ", node->keys[1]);

        inorder_node(node->child[2]);
    }
}

void tree23_print_inorder(const Tree23 *tree)
{
    inorder_node(tree->root);

    putchar('\n');
}

/* =========================
   트리 구조 출력
   ========================= */

static void print_structure_node(
    const Node23 *node,
    int depth)
{
    if (node == NULL)
        return;

    for (int i = 0; i < depth; ++i)
        printf("    ");

    if (node->nkeys == 1) {

        printf(
            "[%d]\n",
            node->keys[0]);

    } else {

        printf(
            "[%d | %d]\n",
            node->keys[0],
            node->keys[1]);
    }

    for (int i = 0;
         i <= node->nkeys;
         ++i) {

        print_structure_node(
            node->child[i],
            depth + 1);
    }
}

void tree23_print_structure(const Tree23 *tree)
{
    print_structure_node(
        tree->root,
        0);
}

/* =========================
   메모리 해제
   ========================= */

static void free_node(Node23 *node)
{
    if (node == NULL)
        return;

    for (int i = 0;
         i <= node->nkeys;
         ++i) {

        free_node(node->child[i]);
    }

    free(node);
}

void tree23_destroy(Tree23 *tree)
{
    free_node(tree->root);

    tree->root = NULL;
}