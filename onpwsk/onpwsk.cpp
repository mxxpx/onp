// onpwsk.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <stdio.h>
#include "stack.h"
#include "Dstack.h"
#include "funonp.h"
#include <cstdio>

using namespace std;

void onp();
double onpcalc();


int main()
{
    cout << "Podaj wyrazenie:" << endl;
    onp();
	cout << endl;
    cout<<"Podaj wyrazenie:"<<endl;
	double x = onpcalc();
	cout << x;
    


}
void onp() 
{
    char c;
    while ((c = getchar()) != '\n') 
    {
        if (!isOper(c)) {
            putchar(c);
        }
        else {
            while (prior(c) <= prior(top())) {
                putchar(pop());
            }
            push(c);

        }
    }
    
    while (!isEmpty())
        putchar(pop());
}

double onpcalc ()
{	
	DStack* dhead = new DStack();
	CStack* head = new Cstack();
	dhead->initDStack(&dhead);
	head->initStack(&head);
	
	char c;
	dpush(getNum());
	
	while (isOper(c = getOper()))
		{
				while (prior(top()) >= prior(c))
			{
					while (!isEmpty) {
						double arg2 = dpop();
						dpush(Eval(pop(), dpop(), arg2));
					}
			}
			push(c);
			dpush(getNum());
		}
		

	while (!isEmpty())
	{
		double arg2 = dpop();
		dpush(Eval(pop(), dpop(), arg2));

	}

	return dpop();

}

