#ifndef __INPUT_H__
#define __INPUT_H_

#include <string>
#include "converter.h"
#include <iostream>

struct Values{
	char letter;
	int number;
};

struct NumericValue{
	struct Values values[20];
};

int readNumber(char c);
NumericValue numericExpression(std::string expression);


#endif
