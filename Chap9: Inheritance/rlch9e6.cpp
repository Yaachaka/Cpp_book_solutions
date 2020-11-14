/*
--PROGRAM NAME: rlch9e6.cpp
--PROGRAM STATEMENT: Start with the ARROVER3 program in Chapter 8. Keep 
the safearay class the same as in that program, and, using inheritance, derive 
the capability for the user to specify both the upper and lower bounds of the 
array in a constructor. This is similar to Exercise 9 in Chapter 8, except that 
inheritance is used to derive a new class (you can call it safehilo) instead of 
modifying the original class.
*/
#include <iostream> 
using namespace std; 

class safearray 
{ 
	protected:
		static const int LIMIT = 100;  //array size 
	private:
		int arr[LIMIT]={0};
		
	public:
		safearray(){}  //default constructor
		~safearray(){}  //destructor
		
		int& operator [](int n)  //note: return by reference 
		{ 
			if( n<0 || n>LIMIT ) 
			{cout<<"\nIndex out of bounds"; exit(1);} 
			return arr[n%LIMIT];  //Remapping range to actual array range[0:99].
		}
}; 
//000000000000000000000000000000000000000000000000000000000000//
class safehilo:public safearray
{
	private:
		int minl,maxl;  //minl and maxl store the bounds entered by the user.
	public:
		safehilo(){}
		~safehilo(){}
		safehilo(int min, int max):minl(min),maxl(max){}  //parameterised constructor.
		
		void getrange(); //To get lower and upper bounds of the array from the user.
		
		int& operator [](int index)  //note: return by reference 
		{ 
			if( index<minl || index>maxl ) 
			{cout<<"\nIndex out of bounds"; exit(1);} 
			return safearray::operator [](index%LIMIT);  //Remapping range to actual array range[0:99].
		}
};
////////////////////////////START OF MAIN()///////////////////////////////
int main() 
{ 
	safehilo sa1;
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
////////////////////////////END OF MAIN()///////////////////////////////

void safehilo::getrange()
{
	cout<<"Enter lower bound: ";
	cin>>minl;
	cout<<"Enter Upper bound: ";
	cin>> maxl;
	if(maxl-minl>=LIMIT)
	{cout<<"No. of elements greater than array size!!!!";exit(1);}
}