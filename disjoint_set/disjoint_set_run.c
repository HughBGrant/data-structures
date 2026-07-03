#include "disjoint_set.h"

void TestDS(void)
{
    DisjointSets *Sets = DS_CreateSets(10);
    DS_CreateSet(Sets, 0);
    DS_CreateSet(Sets, 1);
    DS_CreateSet(Sets, 2);
    DS_CreateSet(Sets, 3);

    printf("Set0 == Set1 : %d \n", DS_FindSet(Sets, 0) == DS_FindSet(Sets, 1));

    DS_UnionSet(Sets, 0, 2);
    printf("Set0 == Set2 : %d \n", DS_FindSet(Sets, 0) == DS_FindSet(Sets, 2));

    DS_UnionSet(Sets, 2, 3);
    printf("Set2 == Set3 : %d \n", DS_FindSet(Sets, 2) == DS_FindSet(Sets, 3));

    DS_DestroySets(Sets);
}
int main(void)
{

    int SetNumber = 0;

    switch (SetNumber) {
    case 0:
        TestDS();
        break;
    }
    return 0;
}