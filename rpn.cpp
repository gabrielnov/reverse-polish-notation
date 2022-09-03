#include "stack.h"
#include "rpn.h"
#include <iostream>

bool isOperator(char e){
    char operatorsList[5] = {'+','-','*','/','^'};

    for (int i = 0; i < 5; i++){
        if (e == operatorsList[i]) return true;
    }

    return false;
}

void converter(std::string e){
    Stack s;
    std::string output;
    
    for (auto &c : e){
        if (!isOperator(c)){
           output.push_back(c);
           continue;
        }

        if (s.isEmpty() || (isOperator(c) && s.top() == "(")){
            std::string sc;
            sc.push_back(c);
            s.push(sc);
            continue;
        }

        if (c == ')'){
            while (c != ')'){

                std::string sc = s.pop();
                output.append(sc);
            }
        }
    }

    std::cout << "output is " << output << std::endl;

    
}