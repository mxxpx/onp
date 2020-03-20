#ifndef DSTACK_H 
#define DSTACK H 
#include "float.h"

typedef struct DStack
{
    double value;
    DStack* next;
    void initDStack(DStack** pStack) { pStack = NULL; }
}DStack;


void demptyStack();
void dpush(double y);
double dpop();
double dtop();
void ddel();
int disEmpty();


#endif 

