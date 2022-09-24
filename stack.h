//ALEX SE YOON KOO 32129319
//GABRIEL NOVAES 31897282

#ifndef __STACK_H__
#define __STACK_H__
#include <string>

const int SIZE = 200;


typedef std::string Elem;

class Stack{
    private:
        int stackTop;
        Elem e[SIZE];
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        bool isFull();
        void push(Elem e);
        Elem pop();
        Elem top();
        int size();
};

#endif
