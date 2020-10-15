/*
--PROGRAM NAME: rlch2e7.cpp
--PROGRAM STATEMENT: You can convert temperature from degrees Celsius to degrees 
Fahrenheit by multiplying by 9/5 and adding 32.  Write a program that allows the 
user to enter a floating-point number representing degrees Celsius, and then 
displays the corresponding degrees Fahrenheit.
*/

#include<iostream>
using namespace std;

int main()
{
	float temperature;
	cout<<"Enter temperature in degrees Celcius: ";
	cin>>temperature;
	cout<<"That is equal to "<<(temperature*9/5)+32<<" degrees Fahrenheit."<<endl;
	
	return 0;
}