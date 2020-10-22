/*
--PROGRAM NAME: rlch5e2.cpp
--PROGRAM STATEMENT: Raising a number n to a power p is the same as multiplying  
n by itself p times. Write a function called power() that takes a double value 
for n and an int value for p, and returns the result as a double value. Use a 
default argument of 2 for p, so that if this argument is omitted, the number n 
will be squared. Write a main() function that gets values from the user to test 
this function.
*/
#include<iostream>
using namespace std;

double power(double n,int p=2);

int main()
{
	double number,rnumber;
	int powerv;
	//User inputs.
	cout<<"Enter a number: ";
	cin>>number;
	cout<<"Enter raising power: ";
	cin>>powerv;
	
	//Calculating and displaying
	rnumber=power(number);
	cout<<number<<" raised to default argument power=2 is "<<rnumber<<endl;
	rnumber=power(number,powerv);
	cout<<number<<" raised to power "<<powerv<<" is "<<rnumber<<endl;
	
	return 0;
}

double power(double n,int p)
{
	double temp=n;
	for(int i=1;i<p;i++)
		temp*=n;
	return temp;
}