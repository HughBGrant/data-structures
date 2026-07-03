#include "disjoint_set.h"

void DS_MakeSet(char *Array, int *Parent, int Index, char NewData)
{
    Array[Index] = NewData;
    Parent[Index] = -1;
}
int DS_FindSet(int *Parent, int Index)
{
    while (Parent[Index] != -1) {
        Index = Parent[Index];
    }
    return Index;
}
void DS_UnionSet(int *Parent, int Index1, int Index2)
{
    Index1 = DS_FindSet(Parent, Index1);
    Index2 = DS_FindSet(Parent, Index2);

    if (Index1 != Index2) {
        Parent[Index2] = Index1;
    }
}
