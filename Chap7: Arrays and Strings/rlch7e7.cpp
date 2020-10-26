/*
--PROGRAM NAME: rlch7e7.cpp
--PROGRAM STATEMENT: One of the weaknesses of C++ for writing business programs is 
that it does not contain a built-in type for monetary values such as 
$173,698,001.32. Such a money type should be able to store a number with a fixed 
decimal point and about 17 digits of precision, which is enough to handle the 
national debt in dollars and cents. Fortunately, the built-in C++ type long double 
has 19 digits of precision, so we can use it as the basis of a money class, even 
though it uses a floating decimal. However, we’ll need to add the capability to 
input and output money amounts preceded by a dollar sign and divided by commas 
into groups of three digits; this makes it much easier to read large numbers. As 
a first step toward developing such a class, write a function called  mstold() 
that takes a money string, a string representing a money amount like 
	“$1,234,567,890,123.99” 
as an argument, and returns the equivalent long double. 
You’ll need to treat the money string as an array of characters, and go through 
it character by character, copying only digits (1–9) and the decimal point into 
another string. Ignore everything else, including the dollar sign and the commas. 
You can then use the _atold() library function (note the initial underscore—header 
file STDLIB.H or MATH.H) to convert the resulting pure string to a long double. 
Assume that money values will never be negative. Write a main() program to test 
mstold() by repeatedly obtaining a money string from the user and displaying the 
corresponding long double.
*/
#include<iostream>
#include<string>
#include<stdlib.h>	//To use strtold();.

using namespace std;

long double mstold(string s);

int main()
{
	string money;
	long double ld;
	char q='y';

	while(q=='y'||q=='Y')
	{
		//Getting user input for money string.
		cout<<"Enter amount: ";
		cin>>money;
		
		//Converting string to long double and displaying.
		ld=mstold(money);	//money string to long double conversion.
		cout<<"Amount in long double: "<<fixed<<ld<<endl;
				//'fixed' manipulator is used to avoid printing the long double value in 
					   //scientific notation i.e. 102.5(fixd nota.)=1.025E2(scientific nota.).
		
		//Adjusting money string and assigning it to a char array. And that char array is 
			//passed to strtold(), the standard function(which doesn't take string as parameter).
		for(int i=0;i<money.length()-1;i++)	//remove, and $ symbols from the money string
		{
			char c=money[i];
			if(!((c>='0'&&c<='9')||c=='.'))
			{
				money.erase(i,1);
			}
		}
		char m[money.length()+1];		//Declaring char array of suitable length.
		m[money.length()]='\0';	//Appending null/terminating character to character array.
		strcpy(m,money.c_str());	//Copying string to array using c_str() in strcpy.
				//money.c_str() converts money of type string to money of type char array.
		
		//Now using the standard library function: strtold().
		ld=strtold(m,NULL);	//strtold(char* ,NULL);
		cout<<"Amount in long double(on using strtold()): "<<fixed<<ld<<endl;
				//_atold() raised errors saying undefined.
		cout<<"Go again (y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

long double mstold(string s)
{
	long double ld=0,multiplier=1;	//multiplier variable here is used to adjust the positional values of each digit.
	char c;
	int length=s.length();
	for(int i=length-1;i>=1;i--)	//conversion starts from least position valued digit.
	{
		c=s.at(i);	//taking individual character.
		if(c>='0'&&c<='9')	//check if it lies between 0 and 9 (including 0 and 9).
		{
			ld+=(int(c)-48)*multiplier;	//converting digit(char) to digit(int) and adjusting position.
			multiplier*=10;
			
		}
		if(c=='.')
		{
			ld/=multiplier;
			multiplier=1;
		}
		
	}
	return ld;
}