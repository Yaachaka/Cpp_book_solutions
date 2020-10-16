/*
--PROGRAM NAME: rlch4e9.cpp
--PROGRAM STATEMENT: Create a structure called time. Its three members, all type 
int, should be called hours, minutes, and seconds. Write a program that prompts 
the user to enter a time value in hours, minutes, and seconds. This can be in 
12:59:59 format, or each number can be entered at a separate prompt (“Enter hours:”, 
and so forth). The program should then store the time in a variable of type 
struct time, and finally print out the total number of seconds represented by 
this time value: 
	long totalsecs = t1.hours*3600 + t1.minutes*60 + t1.seconds
*/

#include<iostream>
using namespace std;

struct time
{
	int hours,minutes,seconds;
};

int main()
{
	struct time t;		//Here struct keyword is necessary to create structure variable.
															//To prevent searching/invoking time() from standard library.
	char c;
	
	cout<<"Enter time (HH:MM:SS)= ";
	cin>>t.hours>>c>>t.minutes>>c>>t.seconds;
	
	long totalsecs=t.hours*3600+t.minutes*60+t.seconds;
	
	cout<<"Total no. of seconds= "<<totalsecs<<endl;
	
	return 0;
}