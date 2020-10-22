/*
--PROGRAM NAME: rlch5e8.cpp
--PROGRAM STATEMENT: Write a function called swap() that interchanges two int 
values passed to it by the calling program. (Note that this function swaps the 
values of the variables in the calling program, not those in the function.) 
You’ll need to decide how to pass the arguments. Create a main() program to 
exercise the function.
*/
#include<iostream>
using namespace std;

void swap(int& a, int& b);

int main()
{
	int a=3, b=4;
	
	cout<<"Before swap function call:\n";
	cout<<"a= "<<a<<" b= "<<b<<endl;
	
	swap(a,b);
	
	cout<<"After swap function call:\n";
	cout<<"a= "<<a<<" b= "<<b<<endl;
	
	return 0;
}

void swap(int& a,int&b)
{
	int c=a;
	a=b;
	b=c;
}