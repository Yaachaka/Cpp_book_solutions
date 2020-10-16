/*
--PROGRAM NAME: rlch4e5.cpp
--PROGRAM STATEMENT: Create a structure of type date that contains three members: 
the month, the day of the month, and the year, all of type  int. (Or use 
day-month-year order if you prefer). Have the user enter a date in the format 
12/31/2001, store it in a variable of type struct date, then retrieve the values 
from the variable and print them out in the same format.
*/

#include<iostream>
using namespace std;

struct date
{
	int day,month,year;
};

int main()
{
	date date1;
	char c;	//to place a dummy character along with needed input. Here it is '/'.
	
	cout<<"Enter day/month/year: ";
	cin>>date1.day>>c>>date1.month>>c>>date1.year;
	
	cout<<"Entered date: "<<date1.day<<'/'<<date1.month<<'/'<<date1.year<<endl;
	
	return 0;
}