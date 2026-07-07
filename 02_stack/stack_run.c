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
void TestLS(void)
{
    LS *Stack = LS_CreateStack();

    LS_Push(Stack, "abc");
    LS_Push(Stack, "def");
    LS_Push(Stack, "efg");
    LS_Push(Stack, "hij");

    printf("Count: %zu, Top: %s\n\n", LS_GetSize(Stack), LS_Top(Stack));

    while (!LS_IsEmpty(Stack)) {
        printf("Popped: %s, ", LS_Top(Stack));
        LS_Pop(Stack);

        if (!LS_IsEmpty(Stack)) {
            printf("Current Top: %s\n", LS_Top(Stack));
        } else {
            printf("Stack Is Empty.\n");
        }
    }
    LS_DestroyStack(Stack);
}
void TestCalculator(void)
{
    // 1
    /*char Infix[100];
    char Postfix[100];

    double Result = 0.0;

    memset(Infix, 0, sizeof(Infix));
    memset(Postfix, 0, sizeof(Postfix));

    printf("Enter Infix : ");
    scanf("%s", Infix);*/
    // 2
    char Infix[100] = "1+3.334/(4.28*(110-7729))";
    char Postfix[100];

    double Result = 0.0;

    memset(Postfix, 0, sizeof(Postfix));

    printf("Enter Infix Expression: %s\n", Infix);
    //

    GetPostfix(Infix, Postfix);

    printf("Infix: %s\nPostfix: %s\n", Infix, Postfix);

    Result = Calculate(Postfix);

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
        TestLS();
        break;
    case 2:
        TestCalculator();
        break;
    }
    return 0;
}
