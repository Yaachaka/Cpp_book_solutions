/*
--PROGRAM NAME: rlch2e9.cpp
--PROGRAM STATEMENT: If you have two fractions, a/b and c/d, their sum can be 
obtained from the formula (a/b)+(c/d)=(a*d+b*c)/(b*d). For example, 1/4 plus 2/3 
is (1/4)+(2/3)=(1*3+4*2)/(4*3)=(3+8)/12=11/12. Write a program that encourages 
the user to enter two fractions, and then displays their sum in fractional form. 
(You don’t need to reduce it to lowest terms.)  The interaction with the user 
might look like this: 
	Enter first fraction: 1/2 
	Enter second fraction: 2/5 
	Sum = 9/10 
You can take advantage of the fact that the extraction operator (>>) can be 
chained to read in more than one quantity at once: 
	cin >> a >> dummychar >> b;
*/

#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	char e;		//to insert '/'.
	
	cout<<"Enter first fraction: ";
	cin>>a>>e>>b;
	cout<<"Enter second fraction: ";
	cin>>c>>e>>d;
	
	cout<<"Sum = "<<(a*d+b*c)<<"/"<<b*d<<endl;
	
	return 0;
}