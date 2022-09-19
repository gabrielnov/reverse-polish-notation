#include "input.h"


std::string read(std::string c){
	std::string digit;
	
	std::cout << "Type a number to replace character " << c << ": ";
		
	std::cin >> digit;
	
	return digit;
}

NumericValues readDigits(std::string expression){
	std::string numeric, input;
	struct NumericValues map;
	
	for (int i = 0; i < expression.size(); i++){
		
		std::string digit;
    	digit.push_back(expression[i]);
    	
		if (isOperand(digit)){
		
			input = read(digit);
			
			map.values[map.total].letter = digit;
			map.values[map.total].number = input;
			map.total++;
			
		}
	}
	
	return map;
	
	

}
