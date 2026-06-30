#include "lcrs_tree.h"
#include "binary_tree.h"
#include "expression_tree.h"

void TestLCRST(void)
{
    LCRSTree *Tree = LCRST_CreateTree('A');
    LCRST_Node *B = LCRST_CreateNode('B');
    LCRST_Node *C = LCRST_CreateNode('C');
    LCRST_Node *D = LCRST_CreateNode('D');
    LCRST_Node *E = LCRST_CreateNode('E');
    LCRST_Node *F = LCRST_CreateNode('F');
    LCRST_Node *G = LCRST_CreateNode('G');
    LCRST_Node *H = LCRST_CreateNode('H');
    LCRST_Node *I = LCRST_CreateNode('I');
    LCRST_Node *J = LCRST_CreateNode('J');
    LCRST_Node *K = LCRST_CreateNode('K');

    // 트리에 노드 추가
    LCRST_AddChild(Tree, Tree->Root, B);
    LCRST_AddChild(Tree, B, C);
    LCRST_AddChild(Tree, B, D);
    LCRST_AddChild(Tree, D, E);
    LCRST_AddChild(Tree, D, F);

    printf("Count : %zu\n", Tree->Count);

    LCRST_AddChild(Tree, Tree->Root, G);
    LCRST_AddChild(Tree, G, H);

    LCRST_AddChild(Tree, Tree->Root, I);
    LCRST_AddChild(Tree, I, J);
    LCRST_AddChild(Tree, J, K);

    // 트리 출력
    LCRST_PrintSubTree(Tree->Root, 0);

    LCRST_RemoveSubTree(Tree, B, C);

    LCRST_PrintSubTree(Tree->Root, 0);

    // 트리 소멸
    LCRST_DestroyTree(Tree);

}
void TestBT(void)
{
    BT_Node *A = BT_CreateNode('A');
    BT_Node *B = BT_CreateNode('B');
    BT_Node *C = BT_CreateNode('C');
    BT_Node *D = BT_CreateNode('D');
    BT_Node *E = BT_CreateNode('E');
    BT_Node *F = BT_CreateNode('F');
    BT_Node *G = BT_CreateNode('G');

    // 트리에 노드 추가
    BT_InsertLeft(A, B);
    BT_InsertLeft(B, C);
    BT_InsertRight(B, D);

    BT_InsertRight(A, E);
    BT_InsertLeft(E, F);
    BT_InsertRight(E, G);

    // 트리 출력
    printf("Preorder ...\n");
    BT_PreorderPrintTree(A);
    printf("\n\n");

    printf("Inorder ... \n");
    BT_InorderPrintTree(A);
    printf("\n\n");

    printf("Postorder ... \n");
    BT_PostorderPrintTree(A);
    printf("\n");

    // 트리 소멸
    BT_DestroySubTree(A);
}
void TestET(void)
{
    ET_Node *Root = NULL;

    char PostfixExpression[20] = "71*52-/";
    ET_BuildExpressionTree(PostfixExpression, &Root);

    // 트리 출력
    printf("Preorder ... \n");
    ET_PreorderPrintTree(Root);
    printf("\n\n");

    printf("Inorder ... \n");
    ET_InorderPrintTree(Root);
    printf("\n\n");

    printf("Postorder ... \n");
    ET_PostorderPrintTree(Root);
    printf("\n");

    printf("Evaluation Result : %f \n", ET_Evaluate(Root));

    // 트리 소멸
    ET_DestroyTree(Root);
}
int main(void)
{
    int TreeNumber = 1;

    switch (TreeNumber)
    {
        case 0:
        {
            TestLCRST();
            break;
        }
        case 1:
        {
            TestBT();
            break;
        }
        case 2:
        {
            TestET();
            break;
        }
    }
    return 0;
}