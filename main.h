#pragma once

#ifndef SHUNT_03112023

#define SHUNT_03112023

// necessary includes
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

/*
Insert shunt docstring here xoxo
*/
void shunt(std::string infix);

/*
isLowerPrecedence checks if operand 1 has lower precedence than operand 2
Parameters:
char op1: operand 1
char op2: operand 2
Returns:
bool: true if operand 1 has lower precedence than operand 2
*/
bool isLowerPrecedence(char op1, char op2);

/*
isEqualPrecedence checks if operand 1 has equal precedence to operand 2
Parameters:
char op1: operand 1
char op2: operand 2
Returns:
bool: true if operand 1 has equal precedence to operand 2
*/
bool isEqualPrecedence(char op1, char op2);

/*
Insert precedence docstring here xoxo
*/
int precedence(char operand);

#endif

