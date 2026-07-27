#define _CRT_SECURE_NO_WARNINGS
#ifndef POSTFIX_CALCULATOR_H
#define POSTFIX_CALCULATOR_H

#include <stdbool.h>

bool is_operand(char symbol);
int prioritize(char operator, bool in_stack);
void convert(char *infix, char *postfix);
int evaluate(const char *postfix);

#endif