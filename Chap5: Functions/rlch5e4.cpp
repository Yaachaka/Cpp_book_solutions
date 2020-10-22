/*
--PROGRAM NAME: rlch5e4.cpp
--PROGRAM STATEMENT: Write a function that takes two Distance values as arguments 
and returns the larger one. Include a main() program that accepts two Distance 
values from the user, compares them, and displays the larger. (See the  RETSTRC 
program for hints.)
*/
#include<iostream>
using namespace std;

struct Distance		//Do not use 'distance' instead of 'Distance'. 'distance' is a 
															//keyword belong to namespace std.
{
	int feet;
	float inches;
};

Distance bigdist(Distance d1,Distance d2);

int main()
{
	Distance d1,d2,d3;
	
	cout<<"Enter Distance d1(feet and inches): ";
	cin>>d1.feet>>d1.inches;
	cout<<"Enter Distance d2(feet and inches): ";
	cin>>d2.feet>>d2.inches;
	
	d3=bigdist(d1,d2);
	
	cout<<"Larger Distance is: "<<d3.feet<<"\' "<<d3.inches<<"\""<<endl;
	
	return 0;
}

Distance bigdist(Distance d1,Distance d2)
{
	if(d1.feet>d2.feet)
		return d1;
	else if(d1.feet==d2.feet)
		return (d1.inches>d2.inches)?d1:d2;
	else
		return d2;
}