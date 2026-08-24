#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} OrderedSet;

/* =========================
   ADT Operations
   ========================= */

// Set 생성
OrderedSet *createSet(void)
{
    OrderedSet *set = (OrderedSet *)malloc(sizeof(OrderedSet));

    if (set == NULL) {
        return NULL;
    }

    set->size = 0;
    return set;
}

// Set 삭제
void destroySet(OrderedSet *set)
{
    free(set);
}

// 크기
int size(OrderedSet *set)
{
    return set->size;
}

// 비어있는지 확인
bool isEmpty(OrderedSet *set)
{
    return set->size == 0;
}

// 특정 원소의 위치 찾기
// 존재하면 해당 index
// 존재하지 않으면 삽입되어야 할 위치를 반환
int lowerBound(OrderedSet *set, int value)
{
    int left = 0;
    int right = set->size;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (set->data[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

// 원소 존재 여부
bool contains(OrderedSet *set, int value)
{
    int index = lowerBound(set, value);

    return index < set->size &&
           set->data[index] == value;
}

// 원소 삽입
bool insert(OrderedSet *set, int value)
{

    if (set->size == MAX_SIZE) {
        return false; // full
    }

    // 삽입 위치 찾기
    int index = lowerBound(set, value);

    // 이미 존재하면 삽입하지 않음
    if (index < set->size &&
        set->data[index] == value) {
        return false;
    }

    // 뒤의 원소들을 한 칸씩 이동
    for (int i = set->size; i > index; i--) {
        set->data[i] = set->data[i - 1];
    }

    // 삽입
    set->data[index] = value;
    set->size++;

    return true;
}

// 원소 삭제
bool removeElement(OrderedSet *set, int value)
{

    int index = lowerBound(set, value);

    // 원소가 없으면 삭제 실패
    if (index == set->size ||
        set->data[index] != value) {
        return false;
    }

    // 뒤의 원소들을 한 칸씩 이동
    for (int i = index; i < set->size - 1; i++) {
        set->data[i] = set->data[i + 1];
    }

    set->size--;

    return true;
}

// 최소값
bool getMin(OrderedSet *set, int *result)
{

    if (isEmpty(set)) {
        return false;
    }

    *result = set->data[0];
    return true;
}

// 최대값
bool getMax(OrderedSet *set, int *result)
{

    if (isEmpty(set)) {
        return false;
    }

    *result = set->data[set->size - 1];
    return true;
}

// 출력
void printSet(OrderedSet *set)
{

    printf("{ ");

    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->data[i]);
    }

    printf("}\n");
}

/* =========================
   Test
   ========================= */

int main(void)
{

    OrderedSet *set = createSet();

    if (set == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    insert(set, 30);
    insert(set, 10);
    insert(set, 20);
    insert(set, 40);
    insert(set, 20); // 중복 -> 삽입되지 않음

    printSet(set);

    printf("size = %d\n", size(set));

    printf("contains(20) = %s\n",
           contains(set, 20) ? "true" : "false");

    printf("contains(50) = %s\n",
           contains(set, 50) ? "true" : "false");

    removeElement(set, 20);

    printSet(set);

    int min, max;

    if (getMin(set, &min)) {
        printf("min = %d\n", min);
    }

    if (getMax(set, &max)) {
        printf("max = %d\n", max);
    }

    destroySet(set);

    return 0;
}