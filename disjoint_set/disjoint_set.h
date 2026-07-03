#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *Parent;
} DisjointSets;

DisjointSets *DS_CreateSets(int Capacity);
void DS_CreateSet(DisjointSets *Sets, int index);
int DS_FindSet(DisjointSets *Sets, int Index);
void DS_UnionSet(DisjointSets *Sets, int Set1, int Set2);
void DS_DestroySets(DisjointSets *Sets);

#endif