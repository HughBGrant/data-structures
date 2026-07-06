#include "array_stack.h"

AS *AS_CreateStack(size_t Capacity)
{
    AS *Stack = malloc(sizeof(AS));

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
void AS_DestroyStack(AS *Stack)
{
    if (Stack == NULL) {
        return;
    }
    free(Stack->Array);
    free(Stack);
}
void AS_Push(AS *Stack, AS_DataType Data)
{
    if (AS_IsFull(Stack)) {
        return;
    }
    Stack->Array[Stack->Count] = Data;
    Stack->Count++;
}
void AS_Pop(AS *Stack)
{
    if (AS_IsEmpty(Stack)) {
        return;
    }
    Stack->Count--;
}
AS_DataType AS_Top(AS *Stack)
{
    return Stack->Array[Stack->Count - 1];
}
size_t AS_GetSize(AS *Stack)
{
    return Stack->Count;
}
bool AS_IsEmpty(AS *Stack)
{
    if (Stack == NULL) {
        return true;
    }
    return Stack->Count == 0;
}
bool AS_IsFull(AS *Stack) { return Stack->Count == Stack->Capacity; }
