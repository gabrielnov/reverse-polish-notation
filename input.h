#ifndef __INPUT_H__
#define __INPUT_H__

#include <string>
#include "converter.h"
#include <iostream>

struct Values{
	std::string letter;
	std::string number;
};

struct NumericValues{
	struct Values values[20];
	int total = 0;
};

std::string read(std::string c);
NumericValues readDigits(std::string expression);


#endif
