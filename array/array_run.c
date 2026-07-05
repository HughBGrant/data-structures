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
    size_t capacity = 10;
    int *array = malloc(sizeof(int) * capacity);
    if (array == NULL) {
        return;
    }
    size_t i = 0;

    for (i = 0; i < capacity; i++) {
        array[i] = (int)i;
    }

    for (i = 0; i < capacity; i++) {
        printf("Array[%zu] : %d\n", i, array[i]);
    }

    printf("\nSetting 3000 At [2]...\n\n");
    array[2] = 3000;

    for (i = 0; i < capacity; i++) {
        printf("Array[%zu] : %d\n", i, array[i]);
    }

    printf("\nDestroying Array...\n");
    free(array);
}
int main(void)
{
    int ArrayNumber = 1;

    switch (ArrayNumber) {
    case 0:
        sa_test();
        break;
    case 1:
        ha_test();
        break;

        return 0;
    }
}