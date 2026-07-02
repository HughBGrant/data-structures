#include "binary_tree.h"
#include "disjoint_set.h"
#include "expression_tree.h"
#include "lcrs_tree.h"

void TestLCRST(void)
{
    LCRSTree *Tree = LCRST_CreateTree('A');
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
void TestBT(void)
{
    BinaryTree *Tree = BT_CreateTree('A');
    BT_Node *A = Tree->Root;
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
    BT_PreorderPrintSubTree(Tree->Root);
    printf("\n\n");

    printf("Inorder ... \n");
    BT_InorderPrintSubTree(Tree->Root);
    printf("\n\n");

    printf("Postorder ... \n");
    BT_PostorderPrintSubTree(Tree->Root);
    printf("\n");

    // 트리 소멸
    BT_DestroyTree(Tree);
}
void TestET(void)
{
    char Postfix[20] = "71*52-/";
    ExpressionTree *Tree = ET_CreateTree(Postfix);
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
void TestDS(void)
{
    char a = 'A', b = 'B', c = 'C', d = 'D';

    DS_Node *Set1 = DS_MakeSet(a);
    DS_Node *Set2 = DS_MakeSet(b);
    DS_Node *Set3 = DS_MakeSet(c);
    DS_Node *Set4 = DS_MakeSet(d);

    printf("Set1 == Set2 : %d \n", DS_FindSet(Set1) == DS_FindSet(Set2));

    DS_UnionSet(Set1, Set3);
    printf("Set1 == Set3 : %d \n", DS_FindSet(Set1) == DS_FindSet(Set3));

    DS_UnionSet(Set3, Set4);
    printf("Set3 == Set4 : %d \n", DS_FindSet(Set3) == DS_FindSet(Set4));
}
int main(void)
{

    int TreeNumber = 3;

    switch (TreeNumber) {
    case 0:
        TestLCRST();
        break;
    case 1:
        TestBT();
        break;
    case 2:
        TestET();
        break;
    case 3:
        TestDS();
        break;
    }
    return 0;
}