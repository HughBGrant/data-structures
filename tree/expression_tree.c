#include "expression_tree.h"

ET_Node *ET_CreateNode(ET_DataType NewData)
{
    ET_Node *NewNode = malloc(sizeof(ET_Node));
    if (NewNode == NULL)
    {
        return NULL;
    }
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}
void ET_DestroyTree(ET_Node *Root)
{
    if (Root == NULL)
        return;

    ET_DestroyTree(Root->Left);
    ET_DestroyTree(Root->Right);
    free(Root);
}
void ET_PreorderPrintTree(ET_Node *Node)
{
    if (Node == NULL)
        return;

    printf(" %c", Node->Data);

    ET_PreorderPrintTree(Node->Left);
    ET_PreorderPrintTree(Node->Right);
}
void ET_InorderPrintTree(ET_Node *Node)
{
    if (Node == NULL)
        return;

    printf("(");
    ET_InorderPrintTree(Node->Left);

    printf("%c", Node->Data);

    ET_InorderPrintTree(Node->Right);
    printf(")");
}
void ET_PostorderPrintTree(ET_Node *Node)
{
    if (Node == NULL)
        return;

    ET_PostorderPrintTree(Node->Left);
    ET_PostorderPrintTree(Node->Right);
    printf(" %c", Node->Data);
}
void ET_BuildExpressionTree(char *PostfixExpression, ET_Node **Node)
{
    int len = strlen(PostfixExpression);
    char Token = PostfixExpression[len - 1];
    PostfixExpression[len - 1] = '\0';

    switch (Token)
    {
        // 연산자인 경우
    case '+': case '-': case '*': case '/':
        (*Node) = ET_CreateNode(Token);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
        ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
        break;

        // 피연산자인 경우
    default:
        (*Node) = ET_CreateNode(Token);
        break;
    }
}
double ET_Evaluate(ET_Node *Tree)
{
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (Tree == NULL)
        return 0;

    switch (Tree->Data)
    {
        // 연산자인 경우
    case '+': case '-': case '*': case '/':
        Left = ET_Evaluate(Tree->Left);
        Right = ET_Evaluate(Tree->Right);

        if (Tree->Data == '+') Result = Left + Right;
        else if (Tree->Data == '-') Result = Left - Right;
        else if (Tree->Data == '*') Result = Left * Right;
        else if (Tree->Data == '/') Result = Left / Right;

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