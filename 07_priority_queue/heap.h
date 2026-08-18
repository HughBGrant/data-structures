#ifndef MAX_BINARY_HEAP_1_H
#define MAX_BINARY_HEAP_1_H

#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 생성
HeapType *create(void);

// 초기화
void init(HeapType *h);

// 삽입
void insert_max_heap(HeapType *h, element item);

// 삭제
element delete_max_heap(HeapType *h);

#endif