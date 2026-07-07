#define _CRT_SECURE_NO_WARNINGS
#include "array_stack.h"
#include "calculator.h"
#include "linked_stack.h"

void as_test(void)
{
    array_stack *stack = as_create(10);

    as_push(stack, 3);
    as_push(stack, 37);
    as_push(stack, 11);
    as_push(stack, 12);

    printf("Count: %zu, Top: %d\n", as_size(stack), as_top(stack));

    while (!as_is_empty(stack)) {
        printf("Popped: %d, ", as_top(stack));
        as_pop(stack);

        if (!as_is_empty(stack))
            printf("Current Top: %d\n", as_top(stack));
        else
            printf("stack Is Empty.\n");
    }
    as_destroy(stack);
}
void ls_test(void)
{
    linked_stack *stack = ls_create();

    ls_push(stack, "abc");
    ls_push(stack, "def");
    ls_push(stack, "efg");
    ls_push(stack, "hij");

    printf("Count: %zu, Top: %s\n\n", ls_size(stack), ls_top(stack));

    while (!ls_is_empty(stack)) {
        printf("Popped: %s, ", ls_top(stack));
        ls_pop(stack);

        if (!ls_is_empty(stack)) {
            printf("Current Top: %s\n", ls_top(stack));
        } else {
            printf("stack Is Empty.\n");
        }
    }
    ls_destroy(stack);
}
void calculator_test(void)
{
    char Infix[100] = "1+3.334/(4.28*(110-7729))";
    char Postfix[100];

    double Result = 0.0;

    memset(Postfix, 0, sizeof(Postfix));

    printf("Enter Infix Expression: %s\n", Infix);

    GetPostfix(Infix, Postfix);

    printf("Infix: %s\nPostfix: %s\n", Infix, Postfix);

    Result = Calculate(Postfix);

    printf("Calculation Result : %f\n", Result);
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
