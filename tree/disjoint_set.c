#include "disjoint_set.h"

DS_Node *DS_MakeSet(void *NewData)
{
    DS_Node *NewNode = malloc(sizeof(DS_Node));
    if (NewNode == NULL) {
        return NULL;
    }
    NewNode->Data = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}
void DS_UnionSet(DS_Node *Set1, DS_Node *Set2)
{
    Set2 = DS_FindSet(Set2);
    Set2->Parent = Set1;
}
DS_Node *DS_FindSet(DS_Node *Node)
{
    while (Node->Parent != NULL) {
        Node = Node->Parent;
    }
    return Node;
}
