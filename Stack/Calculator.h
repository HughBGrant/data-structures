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
size_t GetNextToken(char* Expression, char* Token, int* TYPE);
bool IsPrior(char Operator1, char Operator2);
void GetPostfix(char* InfixExpression, char* PostfixExpression);
double Calculate(char* PostfixExpression);

#endif
