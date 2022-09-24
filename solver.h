//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "stack.h"
#include <string>
#include "converter.h"
#include "input.h"
#include <math.h>

int operation(int number1, int number2, std::string op);
int solve(std::string expression, struct NumericValues *map);

#endif
