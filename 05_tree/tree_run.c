#include "expression_tree.h"
#include "lcrs_tree.h"

void TestLCRST(void)
{
    LCRST *Tree = LCRST_CreateTree('A');
    LCRST_Node *A = Tree->Root;
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
    LCRST_AddChild(A, B);
    LCRST_AddChild(B, C);
    LCRST_AddChild(B, D);
    LCRST_AddChild(D, E);
    LCRST_AddChild(D, F);

    LCRST_AddChild(A, G);
    LCRST_AddChild(G, H);

    LCRST_AddChild(A, I);
    LCRST_AddChild(I, J);
    LCRST_AddChild(J, K);

    // 트리 출력
    LCRST_PrintSubTree(A, 0);

    LCRST_RemoveSubTree(Tree, B, C);

    LCRST_PrintSubTree(A, 0);

    // 트리 소멸
    LCRST_DestroyTree(Tree);
}
void TestET(void)
{
    char Postfix[20] = "71*52-/";
    ET *Tree = ET_CreateTree(Postfix);
    ET_Node *Root = Tree->Root;

    // 트리 출력
    printf("Preorder ... \n");
    ET_PreorderPrintSubTree(Root);
    printf("\n\n");

    printf("Inorder ... \n");
    ET_InorderPrintSubTree(Root);
    printf("\n\n");

    printf("Postorder ... \n");
    ET_PostorderPrintSubTree(Root);
    printf("\n");

    printf("Evaluation Result : %f \n", ET_Calculate(Root));

    // 트리 소멸
    ET_DestroyTree(Tree);
}
int main(void)
{

    int TreeNumber = 1;

    switch (TreeNumber) {
    case 0:
        TestLCRST();
        break;
    case 1:
        TestET();
        break;
    }
    return 0;
}