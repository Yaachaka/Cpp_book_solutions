/*
--PROGRAM NAME: rlch2e11.cpp
--PROGRAM STATEMENT: By default, output is right-justified in its field.  You can 
left-justify text output using the manipulator setiosflags(ios::left). (For now, 
don’t worry about what this new notation means.) Use this manipulator, along with 
setw(), to help generate the following output: 
	Last name   First name   Street address    Town        State
	-----------------------------------------------------------
	Jones       Bernard      109 Pine Lane     Littletown  MI 
	O’Brian     Coleen       42 E. 99th Ave.   Bigcity     NY 
	Wong        Harry        121-A Alabama St. Lakeville   IL
*/

#include<iostream>
#include<iomanip>		//setw(), setiosflags().
using namespace std;

int main()
{
	//Printing head of the table.
	cout<<setiosflags(ios::left)<<setw(13)<<"Last name"<<setw(14)<<"First name"
		<<setw(18)<<"Street address"<<setw(14)<<"Town"<<setw(9)<<"State"<<endl;
	
	//Printing line under the table.
	cout<<setw(64)<<setfill('-')<<""<<setfill(' ')<<endl;
	
	//Printing info of person 1.
	cout<<setw(13)<<"Jones"<<setw(14)<<"Bernard"<<setw(18)<<"109 Pipe Lane"
		<<setw(14)<<setiosflags(ios::left)<<"Littletown"<<setw(9)<<"MI"<<endl;
	
	//printing info of person2.
	cout<<setw(13)<<"O`Brian"<<setw(14)<<"Coleen"<<setw(18)<<"42 E.99th Ave."
		<<setw(14)<<"Bigcity"<<setw(9)<<"NY"<<endl;
	
	//printing info of oerson 3.
	cout<<setw(13)<<"Wong"<<setw(14)<<"Harry"<<setw(18)<<"121-A Alabama St."
		<<setw(14)<<"Lakeville"<<setw(9)<<"IL"<<endl;
	
	return 0;
}