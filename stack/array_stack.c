#include "array_stack.h"

ArrayStack *AS_CreateStack(size_t Capacity)
{
    ArrayStack *Stack = malloc(sizeof(ArrayStack));

    if (Stack == NULL) {
        return NULL;
    }
    Stack->Array = malloc(sizeof(AS_DataType) * Capacity);

    if (Stack->Array == NULL) {
        free(Stack);
        return NULL;
    }
    Stack->Capacity = Capacity;
    Stack->Count = 0;

    return Stack;
}
void AS_DestroyStack(ArrayStack *Stack)
{
    if (Stack == NULL) {
        return;
    }
    free(Stack->Array);
    free(Stack);
}
void AS_Push(ArrayStack *Stack, AS_DataType Data)
{
    if (AS_IsFull(Stack)) {
        return;
    }
    Stack->Count++;
    Stack->Array[Stack->Count - 1] = Data;
}
void AS_Pop(ArrayStack *Stack)
{
    if (AS_IsEmpty(Stack)) {
        return;
    }
    Stack->Count--;
}
AS_DataType AS_Top(ArrayStack *Stack) { return Stack->Array[Stack->Count - 1]; }
size_t AS_GetSize(ArrayStack *Stack) { return Stack->Count; }
bool AS_IsEmpty(ArrayStack *Stack)
{
    if (Stack == NULL) {
        return true;
    }
    return Stack->Count == 0;
}
bool AS_IsFull(ArrayStack *Stack) { return Stack->Count == Stack->Capacity; }
