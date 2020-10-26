/*
--PROGRAM NAME: rlch7e8.cpp
--PROGRAM STATEMENT: Another weakness of C++ is that it does not automatically 
check array indexes to see whether they are in bounds. (This makes array operations 
faster but less safe). We can use a class to create a safe array that checks the 
index of all array accesses. 
Write a class called safearay that uses an int array of fixed size (call it LIMIT) 
as its only data member. There will be two member functions. The first, putel(), 
takes an index number and an int value as arguments and inserts the int value 
into the array at the index. The second, getel(), takes an index number as an 
argument and returns the int value of the element with that index. 
	safearay sa1;           // define a safearay object 
	int temp = 12345;       // define an int value 
	sa1.putel(7, temp);     // insert value of temp into array at index 7 
	temp = sa1.getel(7);    // obtain value from array at index 7 
Both functions should check the index argument to make sure it is not less than 
0 or greater than  LIMIT-1. You can use this array without fear of writing over 
other parts of memory. 
Using functions to access array elements doesn’t look as eloquent as using the [] 
operator. In Chapter 8 we’ll see how to overload this operator to make our 
safearay class work more like built-in arrays.
*/
#include<iostream>
using namespace std;

class safearray
{
	private:
		enum {LIMIT=10};	//Instead of: const int MAX=10;
															//Refer stakaray.cpp example explanation 
															//[chap 7, page 279(305)] from the reference book.
		int sa[LIMIT]={0};	//initializing all elements to 0.
		
	public:
		void putel(int,int);
		int getel(int)const;
};

int main()
{
	safearray sa;
	char q='y';
	int choice, index, value;
	
	while(q=='y'||q=='Y')
	{
		cout<<"Enter 1 to insert a value or 2 to obtain and display the value into/from the array: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter index and value: ";
				cin>>index>>value;
				sa.putel(index,value);
				break;
			case 2:
				cout<<"Enter index: ";
				cin>>index;
				value=sa.getel(index);
				cout<<"Value is: "<<value<<endl;
				break;
			default:
				cout<<"Invalid choice."<<endl;
		}
		cout<<"Go again (y/n)?: ";
		cin>>q;
	}
	return 0;
}

void safearray::putel(int index, int value)
{
	if(index>=0&&index<LIMIT-1)
		sa[index]=value;
	else
		cout<<"Index out of bound."<<endl;
}

int safearray::getel(int index)const
{
	if(index>=0&&index<LIMIT-1)
		return sa[index];
	cout<<"Index out of bound. Returning value at index 0."<<endl;
	return sa[0];
}