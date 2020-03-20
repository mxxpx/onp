#include "stack.h"
#include <stdlib.h>

            
CStack* head = NULL;

void push(char c)
{
    CStack* x = (CStack*)malloc(sizeof(CStack));
    if (!x)
    {
        perror("Allocation error! /push()");
        return;
    }
    x->value = c;
    x->next = head;
    head = x;
}

void emptyStack()
{
    while (!isEmpty())
        del();
}

void del()
{
    if (isEmpty())
    {
        perror("Stack underflow! /del()");
        return;
    }
    CStack* temp = head;
    head = temp->next;
    free(temp);
}

char top()
{
    if (isEmpty())
    {
        return 0;
    }
    return head->value;
}

char pop()
{
    char c;
    if (c = top())
    {
        del();
        return c;
    }
    perror("Stack underflow /pop()");
    return 0;
}

int isEmpty()
{
    return !head;
}