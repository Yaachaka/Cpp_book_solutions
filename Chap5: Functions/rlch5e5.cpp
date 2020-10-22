/*
--PROGRAM NANE: rlch5e5.cpp
--PROGRAM STATEMENT: Write a function called hms_to_secs() that takes three 
int values—for hours, minutes, and seconds—as arguments, and returns the 
equivalent time in seconds (type long). Create a program that exercises this 
function by repeatedly obtaining a time value in hours, minutes, and seconds 
from the user (format 12:59:59), calling the function, and displaying the value 
of seconds it returns.
*/
#include<iostream>
using namespace std;

long hms_to_secs(int hours,int minutes,int seconds);

int main()
{
	int h,m,s;
	long tsec;
	char c,q='y';
	while(q=='y')
	{
		cout<<"Enter time(H:M:S)= ";
		cin>>h>>c>>m>>c>>s;
		
		tsec=hms_to_secs(h,m,s);
		cout<<"That is equal to "<<tsec<<" seconds.";
		
		cout<<"\nGo again(y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

long hms_to_secs(int hours,int minutes,int seconds)
{
	long temp=hours*3600+minutes*60+seconds;
	return temp;
}