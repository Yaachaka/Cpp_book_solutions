/*
--PROGRAM NAME: rlch3e12.cpp
--PROGRAM STATEMENT: Create a four-function calculator for fractions. (See 
Exercise 9 in Chapter 2, and Exercise 4 in this chapter.) Here are the formulas 
for the four arithmetic operations applied to fractions: 
Addition: a/b + c/d = (a*d + b*c) / (b*d) 
Subtraction: a/b - c/d = (a*d - b*c) / (b*d) 
Multiplication: a/b * c/d = (a*c) / (b*d) 
Division:a/b / c/d = (a*d) / (b*c) 
The user should type the first fraction, an operator, and a second fraction.  The 
program should then display the result and ask whether the user wants to continue.
*/

#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	char e,f,g='y';	//f holds operator.
	
	while(g=='y'||g=='Y')
	{
		cout<<"Enter first fraction, operator, second fraction: ";
		cin>>a>>e>>b>>f>>c>>e>>d;
		switch(f)
		{
			case '+':
				cout<<"Result= "<<a*d+b*c<<"/"<<b*d;
				break;
			case '-':
				cout<<"Result= "<<a*d-b*c<<"/"<<b*d;
				break;
			case '*':
				cout<<"Result= "<<a*c<<"/"<<b*d;
				break;
			case '/':
				cout<<"Result= "<<a*d<<"/"<<b*c;
				break;
			default:
				cout<<"Operator not defined.";
		}
		cout<<"\nGo again (y/n)?: ";
		cin>>g;
	}
	
	return 0;
}