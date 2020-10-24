/*
--PROGRAM NAME: rlch6e1.cpp
--PROGRAM STATEMENT: Create a class that imitates part of the functionality of the 
basic data type int. Call the class Int (note different capitalization). The only 
data in this class is an int variable. Include member functions to initialize an 
Int to 0, to initialize it to an  int value, to display it (it looks just like an 
int), and to add two Int values. Write a program that exercises this class by 
creating one uninitialized and two initialized Int values, adding the two 
initialized values and placing the response in the uninitialized value, and then 
displaying this result.
*/
#include<iostream>
using namespace std;

class Int
{
	private:
		int a;
	public:
		Int()
			{a=0;}
		Int(int i)
			{a=i;}
		void add(Int i1,Int i2)
		{a=i1.a+i2.a;}
		void disp()const
		{cout<<a;}
};

int main()
{
	Int i1,i2(23),i3(34);
	
	cout<<"Before addition operation:\n";
	cout<<"i1= ";i1.disp();
	cout<<"\ni2= ";i2.disp();
	cout<<"\ni3= ";i3.disp();
	
	i1.add(i2,i3);
	
	cout<<"\nAfter addition operation:\n";
	cout<<"i1(i1=i1+i2)= ";i1.disp();
	cout<<"\ni2= ";i2.disp();
	cout<<"\ni3= ";i3.disp();
	cout<<endl;
	
	return 0;
}