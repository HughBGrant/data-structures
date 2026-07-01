#include "linked_stack.h"

LinkedStack *LS_CreateStack(void)
{
    LinkedStack *Stack = malloc(sizeof(LinkedStack));

    if (Stack == NULL) {
        return NULL;
    }
    Stack->Top = NULL;
    Stack->Count = 0;

    return Stack;
}
void LS_DestroyStack(LinkedStack *Stack)
{
    if (Stack == NULL) {
        return;
    }
    while (!LS_IsEmpty(Stack)) {
        LS_Pop(Stack);
    }
    free(Stack);
}
LS_Node *LS_CreateNode(LS_DataType NewData)
{
    LS_Node *NewNode = malloc(sizeof(LS_Node));

    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Data = malloc(strlen(NewData) + 1);

    if (NewNode->Data == NULL) {
        free(NewNode); // 데이터가 아닌 노드 해제
        return NULL;
    }
    strcpy(NewNode->Data, NewData);
    NewNode->NextNode = NULL;

    return NewNode;
}
void LS_Push(LinkedStack *Stack, LS_DataType NewData)
{
    LS_Node *NewNode = LS_CreateNode(NewData);
    if (NewNode == NULL) {
        return;
    }

    if (Stack->Top != NULL) {
        NewNode->NextNode = Stack->Top;
    }
    Stack->Top = NewNode;
    Stack->Count++;
}
void LS_Pop(LinkedStack *Stack)
{
    if (Stack == NULL || Stack->Top == NULL) {
        return;
    }
    LS_Node *TopNode = Stack->Top;

    Stack->Top = TopNode->NextNode;

    free(TopNode->Data);
    free(TopNode);
    Stack->Count--;
}
LS_DataType LS_Top(LinkedStack *Stack)
{
    if (Stack->Top == NULL) {
        return NULL;
    }
    return Stack->Top->Data;
}
size_t LS_GetSize(LinkedStack *Stack)
{
    if (Stack == NULL) {
        return 0;
    }
    return Stack->Count;
}
bool LS_IsEmpty(LinkedStack *Stack) { return Stack->Count == 0; }
