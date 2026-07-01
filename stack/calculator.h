#define _CRT_SECURE_NO_WARNINGS
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include <stdbool.h>

bool IsNumber(char Cipher);
size_t GetTokenLength(char* Expression, char* Token);
void GetPostfix(char* Infix, char* Postfix);
double Calculate(char* Postfix);

#endif

