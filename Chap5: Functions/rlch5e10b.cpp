/*
--PROGRAM NAME: rlch5e10b.cpp - Using a local static variable to store the count.
--PROGRAM STATEMENT: Write a function that, when you call it, displays a message 
telling how many times it has been called: “I have been called 3 times”, for 
instance. Write a main() program that calls this function at least 10 times. Try 
implementing this function in two different ways. First, use a global variable to 
store the count. Second, use a local static variable. Which is more appropriate? 
Why can’t you use a local variable?
*/
#include<iostream>
using namespace std;

void counting();

int main()
{
	for(int i=0;i<10;i++)
		counting();
	return 0;
}

void counting()
{
	static int a=0;	//Local static variable.
	cout<<"I have been called "<<++a<<" times.\n";
}