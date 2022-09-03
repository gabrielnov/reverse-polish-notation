#include <iostream>
#include "stack.h"

Stack::Stack(){
    this->stackTop = -1;
}

Stack::~Stack(){};

int Stack::size(){
    return stackTop+1;
}

bool Stack::isEmpty(){
    return this->stackTop == -1;
}

bool Stack::isFull(){
    return this->stackTop == SIZE-1;
}

void Stack::push(Elem e){
    if (!this->isFull()){
        this->e[++this->stackTop] = e;
        return;
    }

    std::cout << "stack overflow exception";
}

Elem Stack::pop(){
    if (this->isEmpty()){
        std::cout << "stack underflow exception";
        return "-1";
    }

    return this->e[this->stackTop--];
}

Elem Stack::top(){
     if (this->isEmpty()){
        std::cout << "stack underflow exception";
        return "-1";
    }
       return this->e[this->stackTop];
}