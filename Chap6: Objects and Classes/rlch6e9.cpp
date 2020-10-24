/*
--PROGRAM NAME: rlch6e9.cpp
--PROGRAM STATEMENT: Transform the fraction structure from Exercise 8 in Chapter 4 
into a fraction class. Member data is the fraction’s numerator and denominator. 
Member functions should accept input from the user in the form 3/5, and output 
the fraction’s value in the same format. Another member function should add two 
fraction values. 
Write a main() program that allows the user to repeatedly input two fractions and 
then displays their sum. After each operation, ask whether the user wants to 
continue.
*/
#include<iostream>
using namespace std;

class fraction
{
	private:
		int num,den;
	public:
		void read();
		void disp()const;
		void sum(fraction);	//one parameter is passed implicitly.
};

int main()
{
	fraction f1,f2;
	char q='y';
	
	cout<<"Enter a fraction: ";
	f1.read();
	cout<<"Entered fraction: ";
	f1.disp();
	
	cout<<"\nAdding two fractions: \n";
	while(q=='y'||q=='Y')
	{
		cout<<"Enter fraction1: ";
		f1.read();
		cout<<"Enter fraction2: ";
		f2.read();
		
		cout<<"Sum of two fractions: ";
		f1.sum(f2);
		f1.disp();
		
		cout<<"\nGo again(y/n)?: ";
		cin>>q;
		
	}
	
	return 0;
}

void fraction::read()
{
	char c;
	cin>>num>>c>>den;
}

void fraction::disp()const
{
	cout<<num<<'/'<<den;
}

void fraction::sum(fraction f)
{
	num=num*f.den+den*f.num;
	den*=f.den;
}