#include "heap_array.h"
#include <stdio.h>
#include <stdlib.h>

void sa_test(void)
{
    int array[10] = {0};
    size_t i = 0;

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    for (i = 0; i < 10; i++) {
        printf("StackArray[%zu] : %d\n", i, array[i]);
    }

    printf("\nSetting 3000 At [2]...\n\n");
    array[2] = 3000;

    for (i = 0; i < 10; i++) {
        printf("StackArray[%zu] : %d\n", i, array[i]);
    }
}
void ha_test(void)
{
    heap_array *array = ha_create(10);
    if (array == NULL) {
        return;
    }
    size_t i = 0;

    for (i = 0; i < ha_size(array); i++) {
        ha_set(array, i, (int)i);
    }

    for (i = 0; i < ha_size(array); i++) {
        printf("Array[%zu] : %d\n", i, ha_get(array, i));
    }

    printf("\nSetting 3000 At [2]...\n\n");
    ha_set(array, 2, 3000);

    for (i = 0; i < ha_size(array); i++) {
        printf("Array[%zu] : %d\n", i, ha_get(array, i));
    }

    printf("\nDestroying Array...\n");
    ha_destroy(array);
}
int main(void)
{
    int array_number = 1;

    switch (array_number) {
    case 0:
        sa_test();
        break;
    case 1:
        ha_test();
        break;

        return 0;
    }
}