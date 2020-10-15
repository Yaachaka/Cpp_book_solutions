/*
--PROGRAM NAME: rlch2e1.cpp	: Robert Lafore chapter 2 Exercise 1
--PROGRAM STATEMENT: Assuming there are 7.481 gallons in a cubic foot, 
write a program that asks the user to enter a number of gallons, 
and then displays the equivalent in cubic feet.
*/

#include<iostream>

using namespace std;

int main()
{
	float gallons,cufeet;
	
	//Taking user input for gallons.
	cout<<"Enter quantity in gallons: ";
	cin>>gallons;
	
	//Conversion: gallons to cubic feet.
	cufeet=gallons/7.481;
	
	//Displaying the converted value.
	cout<<gallons<<"gallons = "<<cufeet<<"cubicfeet"<<endl;
	
	return 0;
}