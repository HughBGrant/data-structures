#ifndef ARRAY_BINARY_TREE_H
#define ARRAY_BINARY_TREE_H

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int size;
} BinaryTree;

/* 초기화 */
void init(BinaryTree *tree);

/* 노드 추가 */
void insert(BinaryTree *tree, int value);

/* 인덱스 관계 */
int parent(int index);
int leftChild(int index);
int rightChild(int index);

/* 출력 */
void printTree(BinaryTree *tree);

#endif