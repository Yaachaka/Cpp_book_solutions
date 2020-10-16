/*
--PROGRAM NAME: rlch4e3.cpp
--PROGRAM STATEMENT: Create a structure called  Volume that uses three variables 
of type Distance (from the ENGLSTRC example) to model the volume of a room. 
Initialize a variable of type  Volume to specific dimensions, then calculate the 
volume it represents, and print out the result. To  calculate the volume, convert 
each dimension from a Distance variable to a variable of type  float representing 
feet and fractions of a foot, and then multiply the resulting three numbers.
*/

#include<iostream>
using namespace std;

struct Distance
{
	int feet; 	//1 foot=12 inches.
	float inches;
};

struct Volume
{
	Distance length,breadth,height;
};

int main()
{
	float l,b,h,v;
	Volume vol={{6,5.5},{4,5.8},{8,8.8}};
	
	l=vol.length.feet+vol.length.inches/12;
	b=vol.breadth.feet+vol.breadth.inches/12;
	h=vol.height.feet+vol.height.inches/12;
	v=l*b*h;
	
	cout<<"Volume is "<<v<<" cubic feet."<<endl;
	
	return 0;
}