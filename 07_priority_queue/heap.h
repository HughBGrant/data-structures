#ifndef HEAP_H
#define HEAP_H
#define MAX_ELEMENT 200
#include <stddef.h>

typedef struct {
    int key;
} item;

typedef struct {
    item items[MAX_ELEMENT];
    size_t count;
} HeapType;

HeapType *create(void);

// 삽입
void insert_max_heap(HeapType *h, item item);

// 삭제
item delete_max_heap(HeapType *h);

#endif