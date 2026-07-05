#include "heap_array.h"

int main(void)
{
    size_t i = 0;

    A *Array = A_CreateArray(5);

    for (i = 0; i < A_GetSize(Array); i++) {
        A_Set(Array, i, (int)i);
    }

    for (i = 0; i < A_GetSize(Array); i++) {
        printf("Array[%zu] : %d\n", i, *A_Get(Array, i));
    }

    printf("\nSetting 3000 At [2]...\n\n");
    A_Set(Array, 2, 3000);

    for (i = 0; i < A_GetSize(Array); i++) {
        printf("Array[%zu] : %d\n", i, *A_Get(Array, i));
    }

    printf("\nDestroying Array...\n");
    A_DestroyArray(Array);

    return 0;
}
