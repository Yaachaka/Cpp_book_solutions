/*
--PROGRAM NAME: rlch10e5.cpp
--PROGRAM STATEMENT: Suppose you have a main() with three local arrays, 
all the same size and type (say float). The first two are already initialized to 
values. Write a function called addarrays() that accepts the addresses of the 
three arrays as arguments; adds the contents of the first two arrays together, 
element by element; and places the results in the third array before returning. A 
fourth argument to this function can carry the size of the arrays. Use pointer 
notation throughout; the only place you need brackets is in defining the arrays.
*/
#include<iostream>
using namespace std;
//------------------------------------------------------------------------//
void disparr(const float*,const int);  //Display the array.
void addarray(const float*,const float*,float*,const int);  //Adding 2 arrays element-wise.
//-----------------------START OF MAIN()----------------------------------//
int main(void)
{
	const int MAX=5;
	float arr1[MAX]={10.0,55.6,78.9,38.99,92.9},
	 arr2[MAX]={121.1,133.4,156.7,21.9,35.5}, arr3[MAX];
	//Displaying arr1 and arr2.
	cout<<"Array arr1: ";disparr(arr1,MAX);
	cout<<"\nArray arr2: ";disparr(arr2,MAX);
	//Adding arr1 and arr2 and storing the result in arr3.
	addarray(arr1,arr2,arr3,MAX);
	//Displaying arr3.
	cout<<"\nArray arr3(=arr1+arr2): ";disparr(arr3,MAX);
	
	cout<<endl;
	return 0;
}
//-----------------------END OF MAIN()----------------------------------//
void disparr(const float* arr,const int n)
{
	for(int i=0;i<n;i++)
		cout<<*(arr+i)<<"  ";
}
//------------------------------------------------------------------------//
void addarray(const float* arr1, const float* arr2, float* arr3,const int n)
{
	for(int i=0;i<n;i++)
		*(arr3+i)=*(arr1+i)+*(arr2+i);
}
//------------------------------------------------------------------------//
