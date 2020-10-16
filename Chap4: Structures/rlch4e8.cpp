/*
--PROGRAM NAME: rlch4e8.cpp
--PROGRAM STATEMENT: Start with the fraction-adding program of Exercise 9 in 
Chapter 2, “C++ Programming Basics.” This program stores the numerator and 
denominator of two fractions before adding them, and may also store the answer, 
which is also a fraction. Modify the program so that all fractions are stored in 
variables of type struct fraction, whose two members are the fraction’s numerator 
and denominator (both type int). All fractionrelated data should be stored in 
structures of this type.
*/

#include<iostream>
using namespace std;

struct fraction
{
	int num, den;
};

int main()
{
	char c;		//To place a dummy character between numerator and denominator. Here: /
	fraction f1,f2,sum;
	
	cout<<"Enter 1st fraction: ";
	cin>>f1.num>>c>>f1.den;
	
	cout<<"Enter 2nd fraction: ";
	cin>>f2.num>>c>>f2.den;
	
	sum.num=f1.num*f2.den+f1.den*f2.num;
	sum.den=f1.den*f2.den;

	cout<<"The result is: "<<sum.num<<'/'<<sum.den<<endl;
	
	return 0;
}