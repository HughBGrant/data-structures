#include "heap_array.h"

int main(void)
{
    size_t i = 0;

    heap_array *array = ha_create(5);

    for (i = 0; i < ha_size(array); i++) {
        ha_set(array, i, (int)i);
    }

    for (i = 0; i < ha_size(array); i++) {
        printf("Array[%zu] : %d\n", i, *ha_get(array, i));
    }

    printf("\nSetting 3000 At [2]...\n\n");
    ha_set(array, 2, 3000);

    for (i = 0; i < ha_size(array); i++) {
        printf("Array[%zu] : %d\n", i, *ha_get(array, i));
    }

    printf("\nDestroying Array...\n");
    ha_destroy(array);

    return 0;
}
