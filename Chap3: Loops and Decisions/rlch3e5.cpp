/*
--PROGRAM NAME: rlch3e5.cpp
--PROGRAM STATEMENT: Use for loops to construct a program that displays a pyramid 
of Xs on the screen. The pyramid should look like this 
    X 
   XXX 
  XXXXX 
 XXXXXXX 
XXXXXXXXX 
except that it should be 20 lines high, instead of the 5 lines shown here. One 
way to do this is to nest two inner loops, one to print spaces and one to print 
Xs, inside an outer loop that steps down the screen from line to line.
*/

#include<iostream>
#include<iomanip>		//setw().
using namespace std;

int main()
{
	for(int i=19,star=1;i>=0;i--,star+=2)
	{
		cout<<setw(i)<<setfill(' ')<<"";		//to fill spaces.
		cout<<setw(star)<<setfill('*')<<""<<endl;		//to fill stars.
	}
	
	return 0;
}