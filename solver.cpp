//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#include "solver.h"

int operation(int number1, int number2, std::string op){
	if(op == "+") return number1 + number2;
	if(op == "/") return number1 / number2;
	if(op == "*") return number1 * number2;
	if(op == "-") return number1 - number2;
	if(op == "^") return (int)(pow(number1, number2) + 1e-9);			
}


int solve(std::string expression, struct NumericValues *map){
	
	// TODO create a stack of integers to avoid lots of casting later
	Stack s;
	int number1, number2, result;
	std::string op;
	
	
	for(int i = 0; i < expression.size(); i++){		
		std::string digit, expressionNumber, letter;
		digit.push_back(expression[i]);
		
		if (isOperand(digit)){
					
			for(int i = 0; i < map->total; i++){
				letter = map->values[i].letter;
				
				if (letter == digit) 
					expressionNumber = map->values[i].number;
			}
				
			if (expressionNumber.empty()) {
				std::cout << "Fatal: number not found" << std::endl;;
				return -1;
			}
				
			s.push(expressionNumber);
			
		} else{
			number1 = stoi(s.pop());
			number2 = stoi(s.pop());
			
			op = digit;
			result = operation(number2, number1, op);
		
			s.push(std::to_string(result));			
		}			
	}
	
	
	result = stoi(s.pop());
	
	return result;
}
