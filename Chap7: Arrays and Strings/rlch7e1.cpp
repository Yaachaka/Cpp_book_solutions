/*
--PROGRAM NAME: rlch7e1.cpp
--PROGRAM STATEMENT: Write a function called reversit() that reverses a C-string 
(an array of char). Use a for loop that swaps the first and last characters, then 
the second and next-to-last characters, and so on. The string should be passed to 
reversit() as an argument. Write a program to exercise reversit(). The program 
should get a string from the user, call reversit(), and print out the result. Use 
an input method that allows embedded blanks. Test the program with Napoleon’s 
famous phrase, “Able was I ere I saw Elba.”
*/
#include<iostream>
#include<cstring>	//to use strlen(), cin.get(...)
using namespace std;

int main()
{
	void reversit(char[]);	//function declaration with scope restricted to main.
	const int MAX=80;
	char arr[MAX];
	//Prompting user to enter a string.
	cout<<"Enter a string: ";
	cin.get(arr,MAX);		//Input method that allows embedded blanks.
	
	reversit(arr);		
	
	cout<<"Reversed string: "<<arr<<endl;
	return 0;
}

void reversit(char arr[])
{
	int len=strlen(arr);
	for(int i=0;i<len/2;i++)
	{
		char c=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=c;
	}
}