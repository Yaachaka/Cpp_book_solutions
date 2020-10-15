/*
--PROGRAM NAME: rlch2e5.cpp
--PROGRAM STATEMENT: A library function, islower(), takes a single character 
(a letter) as an argument and returns a nonzero integer if the letter is lowercase, 
or zero if it is uppercase. This function requires the header file  CTYPE.H.  
Write a program that allows the user to enter a letter, and then displays either 
zero or nonzero, depending on whether a lowercase or uppercase letter was entered. 
(See the  SQRT program for clues.)
*/

#include<iostream>
#include<ctype.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char a;
	cout<<"Enter a character: ";
	cin>>a;
	cout<<islower(a)<<endl;

	return 0;
}