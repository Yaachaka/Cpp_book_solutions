/*
--PROGRAM NAME: rlch3e2.cpp
--PROGRAM STATEMENT: Write a temperature-conversion program that gives the user 
the option of converting Fahrenheit to Celsius or Celsius to Fahrenheit.  Then 
carry out the conversion. Use floating-point numbers. Interaction with the program 
might look like this: 
	Type 1 to convert Fahrenheit to Celsius, 
		2 to convert Celsius to Fahrenheit: 1 
	Enter temperature in Fahrenheit: 70 
	In Celsius that’s 21.111111
*/

#include<iostream>
using namespace std;

int main()
{
	float temperature;
	int option;
	
	cout<<"Type 1 to convert from Celsius to Fahrenheit\n	\
2 to convert from Fahrenheit to Celsius: ";
	cin>>option;
	
	if(option==1)
	{
		cout<<"Enter temperature (°C): ";
		cin>>temperature;
		cout<<"That is equal to "<<(temperature*9/5)+32<<"°Fahrenheit"<<endl;
	}
	else if(option==2)
	{
		cout<<"Enter temperature (°F): ";
		cin>>temperature;
		cout<<"That is equal to "<<(temperature-32)*5/9<<"°Celsius"<<endl;
	}
	else
		cout<<"Invalid option"<<endl;
	
	return 0;
}