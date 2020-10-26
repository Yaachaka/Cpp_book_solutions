/*
--PROGRAM NAME: rlch7e4.cpp
--PROGRAM STATEMENT: Start with a program that allows the user to input a number 
of integers, and then stores them in an  int array. Write a function called 
maxint() that goes through the array, element by element, looking for the largest 
one. The function should take as arguments the address of the array and the 
number of elements in it, and return the index number of the largest element. The 
program should call this function and then display the largest element and its 
index number. (See the SALES program in this chapter.)
*/
#include<iostream>
using namespace std;

int main()
{
	int maxint(int[],int);		//Scope of this function restricted to main
	const int MAX=10;
	int arr[MAX];
	//Getting integers from user to fill up the array.
	cout<<"Enter "<<MAX<<" integers: \n";
	for(int i=0;i<MAX;i++)
		cin>>arr[i];
	//Finding the index of the maximum number and displying them.
	int n=maxint(arr,MAX);
	cout<<"Largest integer in the array is "<<arr[n]<<" and it's index is "<<n<<".\n";
	
	return 0;
}

int maxint(int a[],int n)
{
	int b=0;
	for(int i=1;i<n;i++)
		if(a[b]<a[i])
	  	b=i;		//Store the index of maximum value.
	
	return b;
}