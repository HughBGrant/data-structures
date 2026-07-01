#include "expression_tree.h"

ET_Node *ET_CreateTree(char *Postfix)
{
    size_t len = strlen(Postfix);
    if (len == 0) {
        return NULL;
    }

    ET_DataType Token = Postfix[len - 1];
    ET_Node *NewNode = ET_CreateNode(Token);
    Postfix[len - 1] = '\0';

    switch (Token) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        NewNode->Right = ET_CreateTree(Postfix);
        NewNode->Left = ET_CreateTree(Postfix);
        break;
    }
    return NewNode;
}
ET_Node *ET_CreateNode(ET_DataType NewData)
{
    ET_Node *NewNode = malloc(sizeof(ET_Node));
    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}
void ET_PreorderPrintSubTree(ET_Node *Tree)
{
    if (Tree == NULL)
        return;

    printf(" %c", Tree->Data);

    ET_PreorderPrintSubTree(Tree->Left);
    ET_PreorderPrintSubTree(Tree->Right);
}
void ET_InorderPrintSubTree(ET_Node *Tree)
{
    if (Tree == NULL)
        return;

    printf("(");
    ET_InorderPrintSubTree(Tree->Left);

    printf("%c", Tree->Data);

    ET_InorderPrintSubTree(Tree->Right);
    printf(")");
}
void ET_PostorderPrintSubTree(ET_Node *Tree)
{
    if (Tree == NULL)
        return;

    ET_PostorderPrintSubTree(Tree->Left);
    ET_PostorderPrintSubTree(Tree->Right);
    printf(" %c", Tree->Data);
}
void ET_DestroyTree(ET_Node *Tree)
{
    if (Tree == NULL)
        return;

    ET_DestroyTree(Tree->Left);
    ET_DestroyTree(Tree->Right);
    free(Tree);
}
double ET_Evaluate(ET_Node *Tree)
{
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (Tree == NULL)
        return 0;

    switch (Tree->Data) {
        // 연산자인 경우
    case '+':
    case '-':
    case '*':
    case '/':
        Left = ET_Evaluate(Tree->Left);
        Right = ET_Evaluate(Tree->Right);

        if (Tree->Data == '+')
            Result = Left + Right;
        else if (Tree->Data == '-')
            Result = Left - Right;
        else if (Tree->Data == '*')
            Result = Left * Right;
        else if (Tree->Data == '/')
            Result = Left / Right;

        break;
        // 피연산자인 경우
    default:
        memset(Temp, 0, sizeof(Temp));
        Temp[0] = Tree->Data;
        Result = atof(Temp);
        break;
    }
    return Result;
}
