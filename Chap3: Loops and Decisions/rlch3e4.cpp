/*
--PROGRAM NAME: rlch3e4.cpp
--PROGRAM STATEMENT: Create the equivalent of a four-function calculator.  The 
program should ask the user to enter a number, an operator, and another number. 
(Use floating point.) It should then carry out the specified arithmetical 
operation: adding, subtracting, multiplying, or dividing the two numbers. Use a  
switch statement to select the operation. Finally, display the result. When it 
finishes the calculation, the program should ask whether the user wants to do 
another calculation.  The response can be  ‘y’  or ‘n’. Some sample interaction 
with the program might look like this: 
	Enter first number, operator, second number: 10 / 3 
	Answer = 3.333333 
	Do another (y/n)? y 
	Enter first number, operator, second number: 12 + 100 
	Answer = 112 
	Do another (y/n)? n
*/

#include<iostream>
using namespace std;

int main()
{
	float num1,num2;
	char c,d='y';		//variable c holds the operator.
	
	while(d=='y' || d=='Y')
	{
		cout<<"Enter 1st number, operator, 2nd number: ";
		cin>>num1>>c>>num2;
		switch(c)
		{
			case '+':
				cout<<"Answer: "<<num1+num2;
				break;
			case '-':
				cout<<"Answer: "<<num1-num2;
				break;
			case '*':
				cout<<"Answer: "<<num1*num2;
				break;
			case '/':
				if(num2==0)
				{
					cout<<"Answer: ∞";
					break;
				}
				cout<<"Answer: "<<num1/num2;
				break;
			default:
				cout<<"Operator not defined.";
				break;
		}
		cout<<"\nGo again (y/n)?: ";
		cin>>d;
	}
	
	return 0;
}