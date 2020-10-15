/*
--PROGRAM NAME: rlch3e11.cpp
--PROGRAM STATEMENT: Create a three-function calculator for old-style English 
currency, where money amounts are specified in pounds, shillings, and pence. 
(See Exercises 10 and 12 in Chapter 2.) The calculator should allow the user to 
add or subtract two money amounts, or to multiply a money amount by a 
floating-point number. (It doesn’t make sense to multiply two money amounts; 
there is no such thing as square money. We’ll ignore division. Use the general 
style of the ordinary four-function calculator in Exercise 4 in this chapter.)
*/

#include<iostream>
#include<cmath>		//abs().
using namespace std;

int main()
{
	int pounds1,pounds2,pounds3,shillings1,shillings2,shillings3,pence1,pence2,pence3,choice,amt3;
	char c;
	float n,amt1,amt2;
	
	cout<<"Enter an amount: £";
	cin>>pounds1>>c>>shillings1>>c>>pence1;
	amt1=(pounds1*240)+(shillings1*12)+pence1;		//storing the amount in pence unit.
	
	cout<<"Enter 1 to add this amount\n\
	2 to subtract this amount\n\
	3 to multiply this amount\n\
	other key to exit:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"Enter second amount: £";
			cin>>pounds2>>c>>shillings2>>c>>pence2;
			amt2=(pounds2*240)+(shillings2*12)+pence2;		//storing the amount in pence amount.
			amt1+=amt2;		//adding two amounts.
			cout<<"Sum of two amounts: ";
			break;
		case 2:
			cout<<"Enter second amount: £";
			cin>>pounds2>>c>>shillings2>>c>>pence2;
			amt2=(pounds2*240)+(shillings2*12)+pence2;
			amt1=abs(amt1-amt2);		//finding difference
			cout<<"Difference of two amounts: ";
			break;
		case 3:
			cout<<"Enter multiplying factor: ";
			cin>>n;
			amt1*=n;
			cout<<"The product amount: ";
			break;
		default:
			cout<<"Invalid option.";
			return 0;
	}
	amt3=amt1;		//Resulting amount in pence unit.
	pounds3=amt3/240;		//Extracting pounds.
	shillings3=(amt3%240)/12;		//Extracting shillings.
	pence3=amt3%12;		//Remaining pence.
	
	cout<<"£"<<pounds3<<'.'<<shillings3<<'.'<<pence3<<endl;
	
	return 0;
}