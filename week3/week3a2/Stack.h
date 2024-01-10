#ifndef STACK_H
#define STACK_H

#include "CppLib.h"

class Stack {
public:
    Stack() {
        top = 0;
    }
    ~Stack() {
        while (top) delete pop();
    }
    void push(Stash* stash) {
        data[top++] = stash;
    }
    Stash* pop() {
        return data[--top];
    }
    bool isEmpty() {
        return top == 0;
    }
private:
    Stash* data[100];
    int top;
};

#endif
