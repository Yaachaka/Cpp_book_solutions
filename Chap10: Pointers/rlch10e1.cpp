/*
--PROGRAM NAME: rlch10e1.cpp
--PROGRAM STATEMENT: Write a program that reads a group of numbers from the user 
and places them in an array of type float. Once the numbers are stored in the 
array, the program should average them and print the result. Use pointer notation 
wherever possible.
*/
#include<iostream>
using namespace std;

int main(void)
{
	float farr[10],favg=0.0;
	
	cout<<"Enter 10 decimal numbers: \n";
	for(int i=0;i<10;i++)
	{
		cin>>*(farr+i);  //is equal to farr[i]
		favg+=*(farr+i);  //Summing the numbers.
	}
	favg/=10;  //Calculating average.
	
	cout<<"Average of 10 floats: "<<favg<<endl;
	
	return 0;
}