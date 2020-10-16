/*
--PROGRAM NAME: rlch4e1.cpp
--PROGRAM STATEMENT: A phone number, such as (212) 767-8900, can be thought of as 
having three parts: the area code (212), the exchange (767), and the number (8900). 
Write a program that uses a structure to store these three parts of a phone number 
separately. Call the structure phone. Create two structure variables of type  
phone. Initialize one, and have the user input a number for the other one.  Then 
display both numbers.  The interchange might look like this: 
	Enter your area code, exchange, and number: 415 555 1212 
	My number is (212) 767-8900 
	Your number is (415) 555-1212
*/

#include<iostream>
using namespace std;

struct phone
{
	int area_code,exchange,number;
};

int main()
{
	phone ph1={212,767,8900},ph2;
	
	cout<<"Enter your code, exchange, and number: ";
	cin>>ph2.area_code>>ph2.exchange>>ph2.number;
	
	cout<<"My number is ("<<ph1.area_code<<") "<<ph1.exchange<<"-"<<ph1.number;
	
	cout<<"\nYour number is ("<<ph2.area_code<<") "<<ph2.exchange<<"-"<<ph2.number<<endl;
	
	return 0;
}