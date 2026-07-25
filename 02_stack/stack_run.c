#define _CRT_SECURE_NO_WARNINGS
#include "array_stack.h"
#include "linked_stack.h"
#include "postfix_calculator.h"

void as_test(void)
{
    array_stack *stack = as_create(2);

    as_push(stack, 3);
    as_push(stack, 37);
    as_push(stack, 11);
    as_push(stack, 12);

    printf("Count: %zu, Top: %d\n", as_size(stack), *as_top(stack));

    while (as_is_empty(stack) == false) {
        printf("Popped: %d\n", *as_top(stack));
        as_pop(stack);
    }
    printf("stack Is Empty.\n");
    as_destroy(stack);
}
void ls_test(void)
{
    linked_stack *stack = ls_create();

    ls_push(stack, "abc");
    ls_push(stack, "def");
    ls_push(stack, "efg");
    ls_push(stack, "hij");

    printf("Count: %zu, Top: %s\n\n", ls_size(stack), *ls_top(stack));

    while (ls_is_empty(stack) == false) {
        printf("Popped: %s\n", *ls_top(stack));
        ls_pop(stack);
    }
    printf("stack Is Empty.\n");
    ls_destroy(stack);
}
void calculator_test(void)
{
    char infix[] = "1+3.334/(4.28*(110-7729))";
    char postfix[64];
    memset(postfix, 0, sizeof(postfix));

    double Result = 0.0;
    printf("Enter infix Expression: %s\n", infix);

    convert(infix, postfix);
    printf("infix: %s\npostfix: %s\n", infix, postfix);

    Result = evaluate(postfix);
    printf("Calculation Result : %f\n", Result);
}
int main(void)
{

    int stack_number = 2;

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
