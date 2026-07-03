#include "disjoint_set.h"

DisjointSets *DS_CreateSets(int Capacity)
{
    DisjointSets *Sets = malloc(sizeof(DisjointSets));
    if (Sets == NULL) {
        return NULL;
    }

    Sets->Parent = malloc(sizeof(int) * Capacity);
    if (Sets->Parent == NULL) {
        return NULL;
    }
    return Sets;
}
void DS_CreateSet(DisjointSets *Sets, int Index)
{
    Sets->Parent[Index] = -1;
}
int DS_FindSet(DisjointSets *Sets, int Index)
{
    while (Sets->Parent[Index] != -1) {
        Index = Sets->Parent[Index];
    }
    return Index;
}
void DS_UnionSet(DisjointSets *Sets, int Index1, int Index2)
{
    Index1 = DS_FindSet(Sets, Index1);
    Index2 = DS_FindSet(Sets, Index2);

    if (Index1 != Index2) {
        Sets->Parent[Index2] = Index1;
    }
}
void DS_DestroySets(DisjointSets *Sets)
{
    if (Sets == NULL) {
        return;
    }
    free(Sets->Parent);
    free(Sets);
}
