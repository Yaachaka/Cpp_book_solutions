/*
--PROGRAM NAME: rlch4e12.cpp
--PROGRAM STATEMENT: Revise the four-function fraction calculator program of 
Exercise 12 in Chapter 3 so that each fraction is stored internally as a variable 
of type struct fraction, as discussed in Exercise 8 in this chapter.
*/

#include<iostream>
using namespace std;

struct Fraction
{
	int num,den;
};

int main()
{
	Fraction f1,f2,result;
	char c,d;		//variable d holds the operator and c is to put a dummy character.
	bool flag=true;
	
	cout<<"Enter fraction1(n/d), operator(+,-,*,/), fraction2(n/d): ";
	cin>>f1.num>>c>>f1.den>>d>>f2.num>>c>>f2.den;
			
	switch(d)
	{
		case '+':
			result.num=f1.num*f2.den+f1.den*f2.num;
			result.den=f1.den*f2.den;
			break;
		case '-':
			result.num=f1.num*f2.den-f1.den*f2.num;
			result.den=f1.den*f2.den;
			break;
		case '*':
			result.num=f1.num*f2.num;
			result.den=f1.den*f2.den;
			break;
		case '/':
			result.num=f1.num*f2.den;
			result.den=f1.den*f2.num;
			break;
		default:
			flag=false;
			cout<<"Operator not defined."<<endl;
						
	}
	if(flag)
		cout<<"Result= "<<result.num<<'/'<<result.den<<endl;
	return 0;
}