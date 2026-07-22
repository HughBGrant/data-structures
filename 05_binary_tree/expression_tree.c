#include "expression_tree.h"

ET *ET_CreateTree(char *Postfix)
{
    ET *Tree = malloc(sizeof(ET));
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
bt_node *ET_CreateSubTree(char *Postfix)
{
    size_t len = strlen(Postfix);
    if (len == 0) {
        return NULL;
    }

    ET_dataType Token = Postfix[len - 1];
    bt_node *NewNode = ET_CreateNode(Token);
    if (NewNode == NULL) {
        return NULL;
    }

    Postfix[len - 1] = '\0';

    switch (Token) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        NewNode->right = ET_CreateSubTree(Postfix);
        NewNode->left = ET_CreateSubTree(Postfix);

        if (NewNode->right == NULL || NewNode->left == NULL) {
            ET_DestroySubTree(NewNode);
            return NULL;
        }
        break;
    }
    return NewNode;
}
bt_node *ET_CreateNode(ET_dataType Newdata)
{
    bt_node *NewNode = malloc(sizeof(bt_node));
    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->data = Newdata;

    return NewNode;
}
void ET_PreorderPrintSubTree(bt_node *Tree)
{
    if (Tree == NULL) {
        return;
    }
    printf(" %c", Tree->data);
    ET_PreorderPrintSubTree(Tree->left);
    ET_PreorderPrintSubTree(Tree->right);
}
void ET_InorderPrintSubTree(bt_node *Tree)
{
    if (Tree == NULL) {
        return;
    }
    printf("(");
    ET_InorderPrintSubTree(Tree->left);
    printf("%c", Tree->data);
    ET_InorderPrintSubTree(Tree->right);
    printf(")");
}
void ET_PostorderPrintSubTree(bt_node *Tree)
{
    if (Tree == NULL) {
        return;
    }
    ET_PostorderPrintSubTree(Tree->left);
    ET_PostorderPrintSubTree(Tree->right);
    printf(" %c", Tree->data);
}
void ET_DestroySubTree(bt_node *SubTree)
{
    if (SubTree == NULL) {
        return;
    }
    ET_DestroySubTree(SubTree->left);
    ET_DestroySubTree(SubTree->right);
    free(SubTree);
}
void ET_DestroyTree(ET *Tree)
{
    if (Tree == NULL) {
        return;
    }
    ET_DestroySubTree(Tree->Root);
    free(Tree);
}
double ET_Calculate(bt_node *SubTree)
{
    char Temp[2];

    double left = 0;
    double right = 0;
    double Result = 0;

    if (SubTree == NULL) {
        return 0;
    }
    switch (SubTree->data) {
    case '+': // 연산자인 경우
    case '-':
    case '*':
    case '/':
        left = ET_Calculate(SubTree->left);
        right = ET_Calculate(SubTree->right);

        if (SubTree->data == '+')
            Result = left + right;
        else if (SubTree->data == '-')
            Result = left - right;
        else if (SubTree->data == '*')
            Result = left * right;
        else if (SubTree->data == '/')
            Result = left / right;
        break;
    default: // 피연산자인 경우
        memset(Temp, 0, sizeof(Temp));
        Temp[0] = SubTree->data;
        Result = atof(Temp);
        break;
    }
    return Result;
}
