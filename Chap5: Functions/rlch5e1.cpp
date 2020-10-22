/*
--PROGRAM NAME: rlch5e1.cpp
--PROGRAM STATEMENT: Refer to the CIRCAREA program in Chapter 2, “C++ Programming 
Basics. ”Write a function called circarea() that finds the area of a circle in a 
similar way. It should take an argument of type float and return an argument of 
the same type. Write a main() function that gets a radius value from the user, 
calls circarea(), and displays the result.
*/
#include<iostream>
using namespace std;

float circarea(float a);

int main()
{
	float rad,area;
	
	cout<<"Enter radius of the circle: ";
	cin>>rad;
	
	area=circarea(rad);
	
	cout<<"Area is "<<area<<endl;
	
	return 0;
}

float circarea(float a)
{
	return 3.14159*a*a;
}