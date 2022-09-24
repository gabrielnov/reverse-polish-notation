//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#include "input.h"

std::string readExpression(){
	std::string expression;
	std::cout << "Insert the infix expression: ";
	std::cin >> expression;
	
	while (!validParentheses(expression)){
		std::cout << "Invalid expression. Try again: " << std::endl;
		std::cin >> expression;;
	}
	
	return expression;
}

std::string digitToReplace(std::string c){
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
		
			input = digitToReplace(digit);
			
			map.values[map.total].letter = digit;
			map.values[map.total].number = input;
			map.total++;
			
		}
	}
	
	return map;
}

bool validParentheses(std::string expression){
	Stack s;
	std::string digit;
	
	for (int i = 0; i < expression.size(); i++){
		digit = expression[i];
		
		if (digit == "("){
			s.push(digit);
		} 
		
		if (digit == ")"){
			if (s.isEmpty())
				return false;	
			s.pop();
		}
	}
	
	if(s.isEmpty())
		return true;
	
	return false;	
}





