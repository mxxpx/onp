#ifndef FUNONP_H  
#define FUNONP_H

int prior(char c);
int isOper(char c);
int isDigit(char c);
void skipSpaces();
double getNum();
char getOper();
double Eval(char cOper, double arg1, double arg2);

#endif 