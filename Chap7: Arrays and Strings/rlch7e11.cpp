/*
--PROGRAM NAME: rlch7e11.cpp
--PROGRAM STATEMENT: Refer back to the discussion of money strings in Exercise 6. 
Write a function called ldtoms() to convert a number represented as type long 
double to the same value represented as a money string. First you should check 
that the value of the original long double is not too large. We suggest that you 
don’t try to convert any number greater than 9,999,999,999,999,990.00. Then 
convert the long double to a pure string (no dollar sign or commas) stored in 
memory, using an ostrstream object, as discussed earlier in this chapter. The 
resulting formatted string can go in a buffer called  ustring. 
You’ll then need to start another string with a dollar sign; copy one digit from 
ustring at a time, starting from the left, and inserting a comma into the new 
string every three digits. Also, you’ll need to suppress leading zeros. You want 
to display $3,124.95, for example, not $0,000,000,000,003,124.95. Don’t forget to 
terminate the string with a ‘\0’ character. 
Write a main() program to exercise this function by having the user repeatedly 
input numbers in type long double format, and printing out the result as a money 
string.
*/
#include<iostream>
#include<string>
#include<sstream>		//stringstream. Using instead of ostrsream related header. 
															//Reference links given at the end of the program.
using namespace std;

string ldtoms(long double);

int main(void)
{
	long double ld;
	string money;
	char q='y';
	
	while(q=='y'||q=='Y')
	{
		cout<<"Enter money(in long double): ";
		cin>>ld;
		
		if(ld>9999999999999999.000)
			cout<<"Sorry!! currently not handling value bigger than "
			"9,999,999,999,999,990,00.\n";
		else
		{
			money=ldtoms(ld);
			cout<<"The money string is "<<money<<endl;
		}
		cout<<"Go again(y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

string ldtoms(long double ld)
{
	stringstream ss;
	string money;
	
	//Long double to string conversion: Long double to stringstream then stringstream to string.
	//Feeding ss stream with long double value. 
	ss<<fixed<<ld;	//ld will be fed to ss in scientific notation if fixed manipulator is not used.
	//sending string stream to string.
	ss>>money;
	
	//Filling necessary symbols: $ and ,
	//Placing commas before decimal point.
	int pos=money.find('.');
	for(int i=pos-3;i>0;i-=3)
		money.insert(i,",");
	//Placing commas after decimal point.
	pos=money.find('.');
	for(int i=pos+4;i<money.size();i+=4)
		money.insert(i,",");
	money.insert(0,"$");
	
	return money;
}

/*
REFERENCE LINKS:
--https://en.cppreference.com/w/cpp/io/ostrstream
--https://stackoverflow.com/questions/2820221/why-was-stdstream-deprecated
*/