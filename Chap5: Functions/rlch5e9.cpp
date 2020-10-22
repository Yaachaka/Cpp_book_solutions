/*
--PROGRAM NAME: rlch5e9.cpp
--PROGRAM STATEMENT: Repeat Exercise 8, but instead of two int variables, have 
the swap() function interchange two struct time values (see Exercise 6).
*/
#include<iostream>
using namespace std;

struct Time 
{
	int h,m,s;
};

void swap(Time& t1,Time& t2);

int main()
{	
	Time t1={12,36,38},t2={13,37,50};
	
	cout<<"Before swap function call:\n";
	cout<<"t1= "<<t1.h<<':'<<t1.m<<':'<<t1.s<<endl;
	cout<<"t2= "<<t2.h<<':'<<t2.m<<':'<<t2.s<<endl;
	
	swap(t1,t2);
	
	cout<<"After swap function call:\n";
	cout<<"t1= "<<t1.h<<':'<<t1.m<<':'<<t1.s<<endl;
	cout<<"t2= "<<t2.h<<':'<<t2.m<<':'<<t2.s<<endl;
	
	return 0;
}

void swap(Time& t1, Time& t2)
{
	Time t=t1;
	t1=t2;
	t2=t;
}