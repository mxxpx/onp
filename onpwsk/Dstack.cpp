#include "Dstack.h"
#include <stdlib.h>


DStack* dhead = NULL;

void dpush(double y)
{
    DStack* x = (DStack*)malloc(sizeof(DStack));
    if (!x)
    {
        perror("Allocation error! /dpush()");
        return;
    }
    x->value = y;
    x->next = dhead;
    dhead = x;
}

void demptyStack()
{
    while (!disEmpty())
        ddel();
}

void ddel()
{
    if (disEmpty())
    {
        perror("Stack underflow! /ddel()");
        return;
    }
    DStack* temp = dhead;
    dhead = temp->next;
    free(temp);
}

double dtop()
{
    if (disEmpty())
    {   
        perror("Stack underflow /dtop()");
        return DBL_MIN;
    }
    return dhead->value;
}

double dpop()
{
    if (!disEmpty())
    {
        double x = dtop();
        ddel();
        return x;
    }
    perror("Stack underflow /dpop()");
    return DBL_MIN;
}

int disEmpty()
{
    return !dhead;
}


