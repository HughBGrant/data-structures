#include "lcrs_tree.h"

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