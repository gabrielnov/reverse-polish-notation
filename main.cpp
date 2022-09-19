#include "converter.h"
#include "input.h"
#include <string>

int main(){

    std::string t = "(A*(B+C)/D)";
    
    struct NumericValue newExpression;
    
	newExpression = numericExpression(t);
	
	for (int i = 0; i < 4; i++){
		std::cout << "depois: " << newExpression.values[i].letter << "   " << newExpression.values[i].number << std::endl;
	}
	
	
    convert(t);

    return 0;
}
