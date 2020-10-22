/*
--PROGRAM NAME: rlch5e11.cpp
--PROGRAM STATEMENT: Write a program, based on the sterling structure of Exercise 
10 in Chapter 4, that obtains from the user two money amounts in old-style 
British format (£9:19:11), adds them, and displays the result, again in old-style 
format. Use three functions. The first should obtain a pounds-shillings-pence 
value from the user and return the value as a structure of type sterling. The 
second should take two arguments of type sterling and return a value of the same 
type, which is the sum of the arguments. The third should take a sterling 
structure as its argument and display its value.
*/
#include<iostream>
using namespace std;

struct Sterling
{
	int pounds,shillings,pence;
};

Sterling read();
Sterling add(Sterling s1,Sterling s2);
void display(Sterling s);

int main()
{
	Sterling s1,s2,s;
	
	cout<<"Enter an amount: £";
	s1=read();
	cout<<"Enter another amount: £";
	s2=read();
	
	cout<<"Sum of two amounts: £";
	s=add(s1,s2);
	display(s);  
	cout<<endl;
	
	return 0;
}

Sterling read()
{
	Sterling s;
	char c;
	cin>>s.pounds>>c>>s.shillings>>c>>s.pence;
	return s;
}

Sterling add(Sterling s1, Sterling s2)
{
	s1.pence+=s1.pounds*240+s1.shillings*12;
	s1.pence+=s2.pounds*240+s2.shillings*12+s2.pence;
	s1.pounds=s1.pence/240;
	s1.shillings=(s1.pence%240)/12;
	s1.pence%=12;
	return s1;
}

void display(Sterling s)
{
	cout<<s.pounds<<'.'<<s.shillings<<'.'<<s.pence;
}