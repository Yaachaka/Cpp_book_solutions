/*
--PROGRAM NAME: rlch2e2.cpp
--PROGRAM STATEMENT: Write a program that generates the following table:
				1990      135
				1991     7290
				1992    11300
				1993    16200
Use a single cout statement for all output.
*/

#include<iostream>
#include<iomanip>		//To use setw().

using namespace std;

int main()
{
	//Generating table.
	cout<<setw(6)<<1990<<setw(7)<<135<<endl
		<<setw(6)<<1991<<setw(7)<<7290<<endl
		<<setw(6)<<1992<<setw(7)<<11300<<endl
		<<setw(6)<<1993<<setw(7)<<16200<<endl;
	
	return 0;
}