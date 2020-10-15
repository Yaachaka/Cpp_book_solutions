/*
--PROGRAM NAME: rlch3e3.cpp
--PROGRAM STATEMENT: Operators such as  >>, which read input from the keyboard, 
must be able to convert a series of digits into a number.  Write a program that 
does the same thing. It should allow the user to type up to six digits, and then 
display the resulting number as a type  long integer.  The digits should be read 
individually, as characters, using  getche(). Constructing the number involves 
multiplying the existing value by 10 and then adding the new digit. 
(Hint: Subtract 48 or ‘0’ to go from  ASCII to a numerical digit.)
Here’s some sample interaction: 
	Enter a number: 123456 
	Number is: 123456
*/

#include<iostream>
//#include<conio.h>		//getch().
#include<curses.h>		//getchar(). some properties of conio.h for linux. 
															//ncurses.h can be used. 
using namespace std;

int main()
{
	long int a=0;
	char b;
	
	cout<<"Enter a 6 digit number: ";
	for(int i=0;i<6;i++)
	{
		//b=getch();
		b=getchar();
		if(b>='0'&&b<='9')		//ignore non-digit character.
		{
			a+=b-48;		//converting ASCII equivalent decimal to proper integer digit.
			if(i<5)
				a*=10;		//position adjusting.
		}
		else
			i--;		//ignore count if non-digit character is entered.
	}
	
	cout<<"Number is: "<<a;
	return 0;
}