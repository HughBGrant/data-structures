#define _CRT_SECURE_NO_WARNINGS
#include "array_stack.h"
#include "linked_stack.h"
#include "postfix_calculator.h"
#include <stdio.h>

void as_test(void)
{
    as_stack *stack = as_create();

    as_push(stack, 3);
    as_push(stack, 37);
    as_push(stack, 11);
    as_push(stack, 12);

    printf(
        "Count: %zu, Top: %d\n",
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
    ls_stack *stack = ls_create();

    ls_push(stack, 10);
    ls_push(stack, 20);
    ls_push(stack, 30);
    ls_push(stack, 40);

    printf(
        "Count: %zu, Top: %d\n\n",
        ls_size(stack),
        ls_top(stack));

    while (ls_is_empty(stack) == false) {
        printf("Popped: %d\n", ls_pop(stack));
    }

    printf("stack Is Empty.\n");

    ls_destroy(stack);
}

void calculator_test(void)
{
    char infix[] = "1+3/(4*(8-7))";
    char postfix[64] = {0};

    convert(infix, postfix);

    printf("infix  : %s\n", infix);
    printf("postfix: %s\n", postfix);
    printf("result : %d\n", evaluate(postfix));
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

    case 2:
        calculator_test();
        break;
    }

    return 0;
}