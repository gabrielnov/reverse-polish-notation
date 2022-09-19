#include "input.h"


int readNumber(char c){
	int number;
	
	std::cout << "Type a number to replace character " << c << ": ";
		
	std::cin >> number;
	
	return number;
}

NumericValue numericExpression(std::string expression){
	std::string numeric;
	struct NumericValue map;
	int total = 0, input;
	
	for (int i = 0; i < expression.size(); i++){
		
		if (!isOperator(expression[i])){
		
			input = readNumber(expression[i]);
			
			map.values[total].letter = expression[i];
			map.values[total].number = input;
			total++;
			
		}
	}
	
	return map;
	
	

}
