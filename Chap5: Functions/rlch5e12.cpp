/*
--PROGRAM NAME: rlch5e12.cpp
--PROGRAM STATEMENT: Revise the four-function fraction calculator from Exercise 
12, Chapter 4, so that it uses functions for each of the four arithmetic 
operations. They can be called fadd(), fsub(), fmul(), and fdiv(). Each of these 
functions should take two arguments of type struct fraction, and return an 
argument of the same type.
*/
#include<iostream>
using namespace std;

struct Fraction
{
	int num,den;
};

Fraction fadd(Fraction f1,Fraction f2);
Fraction fsub(Fraction f1,Fraction f2);
Fraction fmul(Fraction f1,Fraction f2);
Fraction fdiv(Fraction f1,Fraction f2);

int main()
{
	Fraction f,f1,f2;
	char c,d;		//d holds the operator.
	bool flag=true;
	
	cout<<"Enter fraction1(n/d), operator(+,-,*,/) and fraction2: ";
	cin>>f1.num>>c>>f1.den>>d>>f2.num>>c>>f2.den;
	
	switch(d)
	{
		case '+': f=fadd(f1,f2); break;
		case '-': f=fsub(f1,f2); break;
		case '*': f=fmul(f1,f2); break;
		case '/': f=fdiv(f1,f2); break;
		default: cout<<"undefined operator."; flag=false;
	}
	if (flag)
		cout<<"Result is "<<f.num<<'/'<<f.den<<endl;

	return 0;
}

Fraction fadd(Fraction f1,Fraction f2)
{
	f1.num=f1.num*f2.den+f1.den*f2.num;
	f1.den*=f2.den;
	return f1;
}

Fraction fsub(Fraction f1,Fraction f2)
{
	f1.num=f1.num*f2.den-f1.den*f2.num;
	f1.den*=f2.den;
	return f1;
}

Fraction fmul(Fraction f1,Fraction f2)
{
	f1.num*=f2.num;
	f1.den*=f2.den;
	return f1;
}

Fraction fdiv(Fraction f1,Fraction f2)
{
	f1.num*=f2.den+f1.den;
	f1.den*=f2.num;
	return f1;
}