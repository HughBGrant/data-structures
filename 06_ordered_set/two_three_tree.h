#ifndef TWO_THREE_TREE_H
#define TWO_THREE_TREE_H

#include <stdbool.h>

typedef struct Node23 Node23;

typedef struct {
    Node23 *root;
} Tree23;

/* 초기화 */
void tree23_init(Tree23 *tree);

/* 탐색 */
bool tree23_search(const Tree23 *tree, int key);

/* 삽입 */
bool tree23_insert(Tree23 *tree, int key);

/* 중위 순회 출력 */
void tree23_print_inorder(const Tree23 *tree);

/* 트리 구조 출력 */
void tree23_print_structure(const Tree23 *tree);

/* 메모리 해제 */
void tree23_destroy(Tree23 *tree);

#endif