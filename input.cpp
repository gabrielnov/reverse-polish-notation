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
		
		// colocamos o valor de i na variavel 'digit' para simplificar a escrita
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

/* Valida se os parenteses da expressão pósfixa são válidos.
Exemplo de parentes inválidos: 
	((A+B)
	(A+B))
	(A+B    */
bool validParentheses(std::string expression){
	Stack s;
	std::string digit;
	

	for (int i = 0; i < expression.size(); i++){
		digit = expression[i];
		
		/* Ao encontrar um (, salva-o na stack.
		Ao encontrar um ), tenta retirar um ( na stack.
		Caso a stack esteja vazia, conclui-se que os parenteses são inválidos */	
		if (digit == "("){
			s.push(digit);
		} 
		
		if (digit == ")"){
			if (s.isEmpty())
				return false;	
			s.pop();
		}
	}
	
	/* Ao final verifica-se se algum ( sobrou. 
	Caso não, sinaliza-se que os parenteses são válidos */
	if(s.isEmpty())
		return true;
	
	return false;	
}





