/*
--PROGRAM NAME: rlch5e3.cpp
--PROGRAM STATEMENT: Write a function called zeroSmaller() that is passed two 
int arguments by reference and then sets the smaller of the two numbers to 0. 
Write a main() program to exercise this function.
*/
#include<iostream>
using namespace std;

void zeroSmaller(int& a,int& b);		//Notice the changes while receiving by refence.

int main()
{
	int a,b;
	cout<<"Enter two integer values: ";
	cin>>a>>b;
	
	cout<<"Before function call: a= "<<a<<" b= "<<b<<endl;
	zeroSmaller(a,b);		//Notice that there are no changes while passing by reference.
	cout<<"After function call: a= "<<a<<" b= "<<b<<endl;
   
	return 0;
}

void zeroSmaller(int& a,int& b)	//Notices the changes while receiving by refernce.
{
	if (a>b)
		b=0;
	else
		a=0;
}