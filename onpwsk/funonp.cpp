#include "funonp.h"
#include <stdio.h>
#include <cmath>
#include <string>

#define DOT '.'


int prior(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

int isOper(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    }
    return 0;
}

int isDigit(char c) //sprawdza czy jest cyfr¹
{
    return (c >= '0' && c <= '9');
}


void skipSpaces()
{
    char c;
    while ((c = getchar()) == ' ');
    ungetc(c, stdin);
    //while( isspace(c = getchar()))
}

double getNum()
{
    char c;
    double res = 0;
    
    skipSpaces();

   

    while (isDigit(c = getchar()))
        res = res * 10 + c - '0';

    if (c == DOT)
    {
        double coef = 0.1;
        while (isDigit(c = getchar()))
        {
            res += c - '0' * coef;
            coef *= 0.1;
        }

    }

    
    ungetc(c, stdin);
    return res;
}

char getOper()
{
    skipSpaces();
    return getchar();
}

double Eval(char cOper, double arg1, double arg2)
{
    
    switch (cOper)
    {
    case '+': return arg1 + arg2;
    case '-': return arg1 - arg2;
    case '*': return arg1 * arg2;
    case '/': if (fabs(arg2) > 1e-15)
    {
    return arg1 / arg2;
    perror("ERROR: Devision by 0!");
    return DBL_MIN;
    }
    case '^': return pow(arg1, arg2);//nie kiedy wykladnik jest calkowity
    }
    return 0;

}

