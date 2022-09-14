#include "stack.h"
#include "rpn.h"
#include <iostream>

int priority(char c){
	if (c == '('){
		return 0;
	}
	if (c == '+' || c == '-'){
		return 1;
	}	
	if (c == '/' || c == '*'){
		return 2;
	}
	if (c == '^' ){
		return 3;
	}		
}

bool isOperator(char e){
    char operatorsList[8] = {'+','-','*','/','^', '(', ')'};

    for (int i = 0; i < 8; i++){
        if (e == operatorsList[i]) return true;
    }

    return false;
}

void converter(std::string e){
	std::cout << "infix expression is " << e << std::endl;
    Stack s;
    std::string output, op;
    
    // A*(B+C)/D
    
    for (int i = 0; i < e.size(); i++){
    	
        if (!isOperator(e[i])){
           output.push_back(e[i]);
           continue;
        }
        
		if (e[i] == ')'){
            while (op != "("){
                output.append(op);
                op = s.pop();
            }
            op = "";
            continue;
        }
		
		std::string sc;
        sc.push_back(e[i]);
				
        if (e[i] == '(' || s.isEmpty() || priority(e[i]) > priority(s.top()[0])){
        	
           
            s.push(sc);
            continue;
        }
        
        if (priority(e[i]) <= priority(s.top()[0])){
           	output.append(s.pop());
           	s.push(sc);
        	continue;
		}    
    }
    
    while (!s.isEmpty()){
    	output.append(s.pop());
	}

    std::cout << "postfix expression is " << output << std::endl;

    
}
