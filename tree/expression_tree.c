#include "expression_tree.h"

ExpressionTree *ET_CreateTree(char *Postfix)
{
    ExpressionTree *Tree = malloc(sizeof(ExpressionTree));
    if (Tree == NULL) {
        return NULL;
    }

    Tree->Root = ET_CreateSubTree(Postfix);
    if (Tree->Root == NULL) {
        free(Tree);
        return NULL;
    }

    return Tree;
}
ET_Node *ET_CreateSubTree(char *Postfix)
{
    size_t len = strlen(Postfix);
    if (len == 0) {
        return NULL;
    }

    ET_DataType Token = Postfix[len - 1];
    ET_Node *NewNode = ET_CreateNode(Token);
    if (NewNode == NULL) {
        return NULL;
    }

    Postfix[len - 1] = '\0';

    switch (Token) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        NewNode->Right = ET_CreateSubTree(Postfix);
        NewNode->Left = ET_CreateSubTree(Postfix);

        if (NewNode->Right == NULL || NewNode->Left == NULL) {
            ET_DestroySubTree(NewNode);
            return NULL;
        }
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
    if (Tree == NULL) {
        return;
    }
    printf(" %c", Tree->Data);
    ET_PreorderPrintSubTree(Tree->Left);
    ET_PreorderPrintSubTree(Tree->Right);
}
void ET_InorderPrintSubTree(ET_Node *Tree)
{
    if (Tree == NULL) {
        return;
    }
    printf("(");
    ET_InorderPrintSubTree(Tree->Left);
    printf("%c", Tree->Data);
    ET_InorderPrintSubTree(Tree->Right);
    printf(")");
}
void ET_PostorderPrintSubTree(ET_Node *Tree)
{
    if (Tree == NULL) {
        return;
    }
    ET_PostorderPrintSubTree(Tree->Left);
    ET_PostorderPrintSubTree(Tree->Right);
    printf(" %c", Tree->Data);
}
void ET_DestroySubTree(ET_Node *SubTree)
{
    if (SubTree == NULL) {
        return;
    }
    ET_DestroySubTree(SubTree->Left);
    ET_DestroySubTree(SubTree->Right);
    free(SubTree);
}
void ET_DestroyTree(ExpressionTree *Tree)
{
    if (Tree == NULL) {
        return;
    }
    ET_DestroySubTree(Tree->Root);
    free(Tree);
}
double ET_Calculate(ET_Node *SubTree)
{
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (SubTree == NULL) {
        return 0;
    }
    switch (SubTree->Data) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        Left = ET_Calculate(SubTree->Left);
        Right = ET_Calculate(SubTree->Right);

        if (SubTree->Data == '+')
            Result = Left + Right;
        else if (SubTree->Data == '-')
            Result = Left - Right;
        else if (SubTree->Data == '*')
            Result = Left * Right;
        else if (SubTree->Data == '/')
            Result = Left / Right;
        break;
    default: // 피연산자인 경우
        memset(Temp, 0, sizeof(Temp));
        Temp[0] = SubTree->Data;
        Result = atof(Temp);
        break;
    }
    return Result;
}
