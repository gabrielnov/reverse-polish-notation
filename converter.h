#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <string>
#include <iostream>

bool isOperand(std::string e);
std::string convert(std::string expression);
int priority(std::string c);

#endif
