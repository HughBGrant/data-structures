#define _CRT_SECURE_NO_WARNINGS
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
} SYMBOL;

bool IsNumber(char Cipher);
size_t GetTokenSize(char* Expression, char* Token, int* TYPE);
void GetPostfix(char* Infix, char* Postfix);
double Calculate(char* Postfix);

#endif
