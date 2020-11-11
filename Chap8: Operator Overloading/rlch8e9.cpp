/*
--PROGRAM NAME: rlch8e9.cpp
--PROGRAM STATEMENT: Augment the safearray class in the ARROVER3 program in this 
chapter so that the user can specify both the upper and lower bound of the array 
(indexes running from 100 to 200, for example). Have the overloaded subscript 
operator check the index each time the array is accessed to ensure that it is not 
out of bounds. You’ll need to add a two argument constructor that specifies the 
upper and lower bounds. Since we have not yet learned how to allocate memory 
dynamically, the member data will still be an array that starts at 0 and runs up 
to 99, but perhaps you can map the indexes for the safearray into different indexes 
in the real int array. For example, if the client selects a range from 100 to 175, 
you could map this into the range from  arr[0] to arr[75].
*/
#include <iostream> 
using namespace std; 

class safearray 
{ 
	private:
		static const int LIMIT = 100;  //array size 
		int arr[LIMIT]={0},minl,maxl;  //minl and maxl store the bounds entered by the user.
		
	public:
		safearray(){}  //default constructor
		~safearray(){}  //destructor
		
		void getrange(); //To get lower and upper bounds of the array from the user.
		
		safearray(int min, int max):minl(min),maxl(max){}  //parameterised constructor.
		
		int& operator [](int index)  //note: return by reference 
		{ 
			if( index<minl || index>maxl ) 
			{cout<<"\nIndex out of bounds"; exit(1);} 
			return arr[index%LIMIT];  //Remapping range to actual array range[0:99].
		}
}; 

int main() 
{ 
	safearray sa1;
	int choice,index,value;
	char q='y';
	
	cout<<"Enter range of array( max. 100 elements capacity): \n";
	sa1.getrange();
	
	while(q=='y'||q=='Y')
	{
		cout<<"Enter 1 to put element, otherwise to get element: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter index and value to put: ";
				cin>>index>>value;
				sa1[index]=value;
				break;
			default:
				cout<<"Enter index to get value: ";
				cin>>index;
				value=sa1[index];
				cout<<"sa1["<<index<<"] = "<<value;
		}
		
		cout<<"\nGo again(y/n)?: ";
		cin>>q;
	}
	
	return 0;
}

void safearray::getrange()
{
	cout<<"Enter lower bound: ";
	cin>>minl;
	cout<<"Enter Upper bound: ";
	cin>> maxl;
	if(maxl-minl>=LIMIT)
	{cout<<"No. of elements greater than array size!!!!";exit(1);}
}