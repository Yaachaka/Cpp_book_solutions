/*
--PROGRAM NAME: rlch3e8.cpp
--PROGRAM STATEMENT: Write a program that repeatedly asks the user to enter two 
money amounts expressed in old-style British currency: pounds, shillings, and 
pence. (See Exercises 10 and 12 in Chapter 2, “C++ Programming Basics.”)  The 
program should then add the two amounts and display the answer, again in pounds, 
shillings, and pence. Use a  do loop that asks the user whether the program should 
be terminated. Typical interaction might be 
	Enter first amount: £5.10.6 
	Enter second amount: £3.2.6 
	Total is £8.13.0 
	Do you wish to continue (y/n)? 
To  add the two amounts, you’ll need to carry 1 shilling when the pence value is 
greater than 11, and carry 1 pound when there are more than 19 shillings.
*/

#include<iostream>
using namespace std;

int main()
{
	int pounds1,pounds2,pounds3,shillings1,shillings2,shillings3,pence1,pence2,pence3;
	char c,q='y';
	while(q=='y'||q=='Y')
	{
		pounds3=shillings3=pence3=0;
		
		cout<<"Enter first amount: £";
		cin>>pounds1>>c>>shillings1>>c>>pence1;
		
		cout<<"Enter second amount: £";
		cin>>pounds2>>c>>shillings2>>c>>pence2;
		
		pence3=pence1+pence2;
		if(pence3>11)
		{
			pence3%=12;
			shillings3=1;
		}
		
		shillings3+=shillings1+shillings2;
		if(shillings3>19)
		{
			shillings3%=20;
			pounds3=1;
		}
		
		pounds3+=pounds1+pounds2;
		
		cout<<"Total is £"<<pounds3<<"."<<shillings3<<"."<<pence3;
		
		cout<<"\nDo you wish to continue (y/n)?: ";
		cin>>q;
	}
		
	return 0;
}