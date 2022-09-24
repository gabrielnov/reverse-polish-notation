//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#ifndef __INPUT_H__
#define __INPUT_H__

#include <string>
#include "converter.h"
#include <iostream>
#include "stack.h"

struct Values{
	std::string letter;
	std::string number;
};

struct NumericValues{
	struct Values values[20];
	int total = 0;
};

std::string readExpression();
std::string digitToReplace(std::string c);
NumericValues readDigits(std::string expression);
bool validParentheses(std::string expression);

#endif
