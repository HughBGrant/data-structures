#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagDS_Node {
    struct tagDS_Node *Parent;
    void *Data;
} DS_Node;

void DS_UnionSet(DS_Node *Set1, DS_Node *Set2);
DS_Node *DS_FindSet(DS_Node *Node);
DS_Node *DS_MakeSet(void *NewData);

#endif
