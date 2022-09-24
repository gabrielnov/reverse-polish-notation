//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#include "stack.h"
#include "converter.h"


int priority(std::string c){
	if (c == "("){
		return 0;
	}
	if (c == "+" || c == "-"){
		return 1;
	}	
	if (c == "/" || c == "*"){
		return 2;
	}
	if (c == "^" ){
		return 3;
	}		
}

bool isOperand(std::string digit){
    std::string operatorsList[8] = {"+","-","*","/","^", "(", ")"};

    for (int i = 0; i < 8; i++){
        if (digit == operatorsList[i]) return false;
    }

    return true;
}

std::string convert(std::string expression){
	std::cout << "infix expression: " << expression;
    Stack s;
    std::string output, op;
    
    for (int i = 0; i < expression.size(); i++){
    	
    	std::string digit;
    	digit.push_back(expression[i]);
    
        if (isOperand(digit)){
           output.append(digit);
           continue;
        }
        
		if (digit == ")"){
            while (op != "("){
                output.append(op);
                op = s.pop();
            }
            op = "";
            continue;
        }
		
		std::string sc;
        sc.append(digit);
				
        if (digit == "(" || s.isEmpty() || priority(digit) > priority(s.top())){
        	
           
            s.push(sc);
            continue;
        }
        
        if (priority(digit) <= priority(s.top())){
           	output.append(s.pop());
           	s.push(sc);
        	continue;
		}    
    }
    
    while (!s.isEmpty()){
    	output.append(s.pop());
	}

    std::cout << " | postfix expression is " << output << std::endl;
    return output;
}
