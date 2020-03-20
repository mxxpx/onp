#ifndef STACK_H  
#define STACK_H
#include "float.h"

typedef struct CStack {
    char value;
    CStack* next;
    void initStack(CStack** pStack) { pStack = NULL; }
} Cstack;

void emptyStack();
void push(char c);
char pop();
char top();
void del();
int isEmpty();


#endif 