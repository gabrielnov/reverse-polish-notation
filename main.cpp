#include "rpn.h"
#include <string>

int main(){

    std::string t = "(A*(B+C)/D)";

    converter(t);

    return 0;
}
