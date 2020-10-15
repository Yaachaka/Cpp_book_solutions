/*
--PROGRAM NAME: rlch2e6.cpp
--PROGRAM STATEMENT: On a certain day the British pound was equivalent to $1.487 U.S., 
the French franc was $0.172, the German deutschemark was $0.584, and the Japanese 
yen was $0.00955. Write a program that allows the user to enter an amount in 
dollars, and then displays this value converted to these four other monetary 
units.
*/

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int ndollars;
	
	//Taking user input.
	cout<<"Enter amount in dollars: ";
	cin>>ndollars;
	
	//Displaying converted amounts.
	cout<<setw(22)<<"British (pound)"<<setw(10)<<ndollars*1.487<<endl
		<<setw(22)<<"French (franc)"<<setw(10)<<ndollars*0.172<<endl
		<<setw(22)<<"German(deutschmark)"<<setw(10)<<ndollars*0.584<<endl
		<<setw(22)<<"Japanese(yen)"<<setw(10)<<ndollars*0.00955<<endl;
	
	return 0;
}