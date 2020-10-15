/*
--PROGRAM NAME: rlch3e10.cpp
--PROGRAM STATEMENT: Write another version of the program from Exercise 7 so that, 
instead of finding the final amount of your investment, you tell the program the 
final amount and it figures out how many years it will take, at a fixed rate of 
interest compounded yearly, to reach this amount. What sort of loop is appropriate 
for this problem? (Don’t worry about fractional years; use an integer value for 
the year.)
*/

#include<iostream>
using namespace std;

int main()
{
	float ini_amt,cmp_amt,int_rate,temp;
	int years=0;
	
	cout<<"Enter initial amount: ";
	cin>>ini_amt;
	
	cout<<"Enter interest rate (per year): ";
	cin>>int_rate;
	
	cout<<"Enter compound amount expected: ";
	cin>>cmp_amt;
	
	temp=ini_amt;
	while(temp<cmp_amt)
	{
		temp+=temp*int_rate/100;
		years++;
	}
	
	cout<<"It takes about "<<years<<" years."<<endl;
	
	return 0;
}