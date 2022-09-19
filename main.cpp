#include "converter.h"
#include "input.h"
#include "solver.h"
#include <string>

int main(){

    std::string infix = "(A+B)/(C-D)*E", postfix;
    int result;
    
    struct NumericValues numericValues;
    
	numericValues = readDigits(infix);

    postfix = convert(infix);
    
    result = solve(postfix, &numericValues);
    std::cout << "The final result is " << result << std::endl;

    return 0;
}
