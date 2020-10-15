/*
--PROGRAM NAME: rlch2e3.cpp
--PROGRAM STATEMENT: Write a program that generates the following output:
10
20
19
Use an integer constant for the 10, an arithmetic assignment operator to generate 
the 20, and a decrement operator to generate the 19.
*/
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	int a=10;
	cout<<a<<endl;
	a+=10;
	cout<<a<<endl<<(--a)<<endl;

	return 0;
}