/*
--PROGRAM NAME: rlch4e11.cpp
--PROGRAM STATEMENT: Use the time structure from Exercise 9, and write a program 
that obtains two time values from the user in 12:59:59 format, stores them in  
struct time variables, converts each one to seconds (type int), adds these 
quantities, converts the result back to hoursminutes-seconds, stores the result 
in a time structure, and finally displays the result in 12:59:59 format.
*/

#include<iostream>
using namespace std;

struct Time
{
	int h,m,s;
};

int main()
{
	Time t,t1,t2;
	char c;
	
	//Entering t1.
	cout<<"Enter time t1(H:M:S)= ";
	cin>>t1.h>>c>>t1.m>>c>>t1.s;
	
	//Entering t2.
	cout<<"Enter time t2(H:M:S)= ";
	cin>>t2.h>>c>>t2.m>>c>>t2.s;
	
	//Calculating t1's total seconds and and storing.
	t.s=t1.h*3600+t1.m*60+t1.s;
	
	//Calculating t2's total seconds and adding it to t1's total seconds.
	t.s+=	t2.h*3600+t2.m*60+t2.s;
	
	t.h=t.s/3600;		//Extracting hours.
	t.m=(t.s%3600)/60;		//Extracting minutes.
	t.s%=60;		//Extracting seconds.
	
	//Displaying the sum of 2 times.
	cout<<"Sum of t1 and t2= "<<t.h<<':'<<t.m<<':'<<t.s<<endl;
	
	return 0;
}