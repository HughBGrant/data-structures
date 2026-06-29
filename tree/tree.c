#include "lcrs_tree.h"

void TestLCRST(void)
{
	LCRST_Node *A = LCRST_CreateNode('A');
    LCRSTree *Tree = LCRST_CreateTree(A);
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
    LCRST_AddChildNode(A, B);
    LCRST_AddChildNode(B, C);
    LCRST_AddChildNode(B, D);
    LCRST_AddChildNode(D, E);
    LCRST_AddChildNode(D, F);

    LCRST_AddChildNode(A, G);
    LCRST_AddChildNode(G, H);

    LCRST_AddChildNode(A, I);
    LCRST_AddChildNode(I, J);
    LCRST_AddChildNode(J, K);

    // 트리 출력
    LCRST_PrintTree(A, 0);

    // 트리 소멸
    LCRST_DestroyTree(Tree);

}
int main(void)
{
    int TreeNumber = 0;

    switch (TreeNumber)
    {
        case 0:
        {
            TestLCRST();
            break;
        }
    }
    return 0;
}