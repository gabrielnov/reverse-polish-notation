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
	
	Stack s;
	int number1, number2, result;
	std::string op;
	
	
	for(int i = 0; i < expression.size(); i++){		
		std::string digit, expressionNumber, letter;
		digit.push_back(expression[i]);
		
		/* caso o digito seja um operando, encontramos o numero equivalente
		no map e salvamos o numero numa stack */
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
		
		/* fazemos essa verificação até encontrar um operador.
		Quando o operador é encontrado, realizamos a operação
		entre os dois números salvos na stack e adicionamos
		o resultado na stack. */
		
		} else{
			/* como a stack usa elementos do tipo string,
			precisamos converter esse valor para int para realizarmos os calculos.
			Uma saída seria declarar uma Stack extra que recebe inteiros */
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
