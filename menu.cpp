//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#include "menu.h"

int result;
std::string infix, postfix;
struct NumericValues numericValues;

void checkNull(std::string expression){
	if (expression == "") {
		std::cout << "Error: You need to insert the infix expression and then convert it" << std::endl;
		showMenu();
	}
}

void option(char opt){
	switch(opt){
		case '1':
			infix = readExpression();
			std::cout << "Expression saved." << std::endl;
			showMenu();
		case '2':
			checkNull(infix);			
			numericValues = readDigits(infix);
			showMenu();
		case '3':
			checkNull(infix);
			postfix = convert(infix);
			showMenu();
		case '4':
			checkNull(postfix);
			
			if (numericValues.total == 0){
				std::cout << "Error: You need to insert numeric values first" << std::endl;
				showMenu();
			}
			
			result = solve(postfix, &numericValues);
			std::cout << "\nResult is " << result << std::endl;
			
			exit(0);
		case '5':
			exit(0);
		default:
			std::cout << "Invalid Option. Try again" << std::endl;
			showMenu();
	}
	
}
void showMenu(){
	std::cout << "\n1) Infix expression input" << std::endl;
	std::cout << "2) Numeric values input" << std::endl;
	std::cout << "3) Postfix expression conversion" << std::endl;
	std::cout << "4) Expression evaluation" << std::endl;
	std::cout << "5) Exit" << std::endl;
	
	std::cout << "\nChoose an option: ";
	char opt;
	std::cin >> opt;
	
	option(opt);
}
