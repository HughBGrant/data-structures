#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <stdio.h>
#include <stdlib.h>

// typedef struct {
//     char *Data;
//     int *Parents;
// } DisjointSet;

void DS_MakeSet(char *Array, int *Parent, int index, char NewData);
int DS_FindSet(int *Parent, int Index);
void DS_UnionSet(int *Parent, int Set1, int Set2);

#endif