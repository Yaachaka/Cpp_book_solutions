/*
--PROGRAM NAME: rlch5e7.cpp
--PROGRAM STATEMENT: Start with the power() function of Exercise 2, which works 
only with type double. Create a series of overloaded functions with the same name 
that, in addition to double, also work with types char, int, long, and float. 
Write a main() program that exercises these overloaded functions with all 
argument types.
*/
#include<iostream>
#include<iomanip>
using namespace std;

char power(char c,int p=2);
int power(int a,int p=2);
long power(long a,int p=2);
float power(float a,int p=2);
double power(double a,int p=2);

int main()
{
	char c,q;
	int powerv,a;
	long l;
	float f;
	double d;
	
	cout<<"Exercising power function Overloading: \n";
	cout<<setw(80)<<setfill('-')<<""<<endl;
	
	//Raising a character.
	cout<<"Raising a character: ";
	cout<<"Enter a character: ";
	cin>>c;
	cout<<"Default raising power is 2. Change it(y/n)?: ";
	cin>>q;
	if(q=='y'||q=='Y')
	{
		cout<<"Enter power: ";
		cin>>powerv;
		c=power(c,powerv);
	}
	else
		c=power(c);
	cout<<"Result: "<<c<<endl;
	
	//Raising an integer.
	cout<<"Raising an integer: ";
	cout<<"Enter an integer: ";
	cin>>a;
	cout<<"Default raising power is 2. Change it(y/n)?: ";
	cin>>q;
	if(q=='y'||q=='Y')
	{
		cout<<"Enter power: ";
		cin>>powerv;
		a=power(a,powerv);
	}
	else
		a=power(a);
	cout<<"Result: "<<a<<endl;
	
	//Raising a long integer.
	cout<<"Raising long integer: ";
	cout<<"Enter a long integer: ";
	cin>>l;
	cout<<"Default raising power is 2. Change it(y/n)?: ";
	cin>>q;
	if(q=='y'||q=='Y')
	{
		cout<<"Enter power: ";
		cin>>powerv;
		l=power(l,powerv);
	}
	else
		l=power(l);
	cout<<"Result: "<<l<<endl;
	
	//Raising a floating point number.
	cout<<"Raising Floating point number: ";
	cout<<"Enter a floating point number: ";
	cin>>f;
	cout<<"Default raising power is 2. Change it(y/n)?: ";
	cin>>q;
	if(q=='y'||q=='Y')
	{
		cout<<"Enter power: ";
		cin>>powerv;
		f=power(f,powerv);
	}
	else
		f=power(f);
	cout<<"Result: "<<f<<endl;
	
	//Raising a double.
	cout<<"Raising Double: ";
	cout<<"Enter a double: ";
	cin>>d;
	cout<<"Default raising power is 2. Change it(y/n)?: ";
	cin>>q;
	if(q=='y'||q=='Y')
	{
		cout<<"Enter power: ";
		cin>>powerv;
		d=power(d,powerv);
	}
	else
		d=power(d);
	cout<<"Result: "<<d<<endl;
	 
	return 0;
}

char power(char c,int p)
{
	int a=static_cast<int>(c);
	int b=a;
	for(int i=1;i<p;i++)
		b*=a;
	c=static_cast<char>(b);
	return c;
}

int power(int a,int p)
{
	int b=a;
	for(int i=1;i<p;i++)
		b*=a;
	return b;
}

long power(long a,int p)
{
	
	long b=a;
	for(int i=1;i<p;i++)
		b*=a;
	return b;
}

float power(float a,int p)
{
	
	float b=a;
	for(int i=1;i<p;i++)
		b*=a;
	return b;
}

double power(double a,int p)
{
	
	double b=a;
	for(int i=1;i<p;i++)
		b*=a;
	return b;
}