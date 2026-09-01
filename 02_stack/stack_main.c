#define _CRT_SECURE_NO_WARNINGS
#include "array_stack.h"
#include "linked_stack.h"
#include <stdio.h>

void as_test(void)
{
    AStack *stack = as_create();

    as_push(stack, 3);
    as_push(stack, 37);
    as_push(stack, 11);
    as_push(stack, 12);

    printf(
        "size: %zu, Top: %d\n",
        as_size(stack),
        as_top(stack));

    while (as_is_empty(stack) == false) {
        printf("Popped: %d\n", as_pop(stack));
    }

    printf("stack Is Empty.\n");

    as_destroy(stack);
}

void ls_test(void)
{
    LStack *stack = ls_create();

    ls_push(stack, 10);
    ls_push(stack, 20);
    ls_push(stack, 30);
    ls_push(stack, 40);

    printf(
        "size: %zu, Top: %d\n\n",
        ls_size(stack),
        ls_top(stack));

    while (ls_is_empty(stack) == false) {
        printf("Popped: %d\n", ls_pop(stack));
    }

    printf("stack Is Empty.\n");

    ls_destroy(stack);
}

int main(void)
{
    int stack_number = 1;

    switch (stack_number) {
    case 0:
        as_test();
        break;

    case 1:
        ls_test();
        break;
    }

    return 0;
}