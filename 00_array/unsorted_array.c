#include <stdio.h>
#include <stdlib.h>
//
// static int a_linear_search_transpose(a_list *list, a_item key);
//
// static int a_linear_search_move2front(a_list *list, a_item key);
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sort_bubble(int array[], int size)
{
    for (size_t i = 0; i < size - 1; i++) {
        int flag = 0;

        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}
void print(int array[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
// static int a_linear_search_transpose(a_list *list, a_item key)
//{
//     if (list == NULL) {
//         return -1;
//     }
//     int index = 0;
//
//     while (index < list->size && list->items[index] != key) {
//         index++;
//     }
//     if (index == list->size) {
//         return -1;
//     }
//     if (index > 0) {
//         a_item temp = list->items[index - 1];
//         list->items[index - 1] = list->items[index];
//         list->items[index] = temp;
//         index--;
//     }
//     return index;
// }
// static int a_linear_search_move2front(a_list *list, a_item key)
//{
//     if (list == NULL) {
//         return -1;
//     }
//     int index = 0;
//
//     while (index < list->size && list->items[index] != key) {
//         index++;
//     }
//     if (index == list->size) {
//         return -1;
//     }
//     while (index > 0) {
//         list->items[index] = list->items[index - 1];
//         index--;
//     }
//     list->items[0] = key;
//
//     return index;
// }
int main()
{
    int array[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};

    size_t size = 10;

    sort_bubble(array, size);
    print(array, size);

    return 0;
}