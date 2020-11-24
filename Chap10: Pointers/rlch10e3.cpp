/*
--PROGRAM NAME: rlch10e3.cpp
--PROGRAM STATEMENT: Start with an array of pointers to strings 
representing the days of the week, as found in the PTRTOSTR program in this 
chapter. Provide functions to sort the strings into alphabetical order, using 
variations of the bsort() and order() functions from the PTRSORT program in this 
chapter. Sort the pointers to the strings, not the actual strings.
*/
//--------------------------------------------------------------------//
#include <iostream>
using namespace std;

const int DAYS = 7;				 //number of pointers in array
//---------------------------------START OF MAIN()--------------------------//
int main()
{									 //array of pointers to char
	void bsort(char**, int);		 //prototype
	char* arrptrs[DAYS] = {"Sunday","Monday","Tuesday","Wednesday","Thursday",
	"Friday","Saturday"};

	cout<<"Strings before alphabetical sorting.\n";
	for(int j=0;j<DAYS;j++)	 //display every string
		cout<<"  "<<&arrptrs[j]<<"  "<<arrptrs[j]<<endl;
	
	bsort(arrptrs, DAYS);					//sort the array	
	
	cout<<"\nStrings after alphabetical sorting.\n";
	for(int j=0; j<DAYS; j++)	 //display every string
		cout<<"  "<<&arrptrs[j]<<"  "<<arrptrs[j]<< endl;
	
	return 0;
}
//---------------------------------END OF MAIN()--------------------------//
void bsort(char** arrptrs, int days)
{
	void order(char**, char**);		//prototype
	int j, k;						  //indexes to array

	for(j=0; j<days-1; j++)			//outer loop
		for(k=j+1; k<days; k++)		//inner loop starts at outer
			order(arrptrs+j, arrptrs+k);			//order the pointer contents
}
//--------------------------------------------------------------------//
void order(char** str1, char** str2)  //orders two numbers
{										 
	if(**str1 > **str2)			 //if 1st larger than 2nd,
	{
		char* temp = *str1;		  //swap them
		*str1 = *str2;
		*str2 = temp;
	}
}
//--------------------------------------------------------------------//
