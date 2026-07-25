#define _CRT_SECURE_NO_WARNINGS
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>
#include <stdlib.h>

bool is_operand(char symbol);
size_t get_token_size(char *expression, char *token);
int prioritize(char operator, bool in_stack);
void convert(char *infix, char *postfix);
double evaluate(char *postfix);

#endif
