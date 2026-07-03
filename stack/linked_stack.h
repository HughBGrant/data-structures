#define _CRT_SECURE_NO_WARNINGS
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *LS_DataType;

typedef struct tagLS_Node {
    LS_DataType Data;
    struct tagLS_Node *NextNode;
} LS_Node;

typedef struct {
    LS_Node *Top;
    size_t Count;
} LS;

LS *LS_CreateStack(void);
LS_Node *LS_CreateNode(LS_DataType NewData);
void LS_Push(LS *Stack, LS_DataType NewData);
void LS_Pop(LS *Stack);
LS_DataType LS_Top(LS *Stack);
void LS_DestroyStack(LS *Stack);

size_t LS_GetSize(LS *Stack);
bool LS_IsEmpty(LS *Stack);

#endif