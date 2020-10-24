/*
--PROGRAM NAME: rlch6e8.cpp
--PROGRAM STATEMENT: Create a class that includes a data member that holds a 
“serial number” for each object created from the class. That is, the first object 
created will be numbered 1, the second 2, and so on. To do this, you’ll need 
another data member that records a count of how many objects have been created 
so far. (This member should apply to the class as a whole; not to individual 
objects. What keyword specifies this?). Then, as each object is created, its 
constructor can examine this count member variable to determine the appropriate 
serial number for the new object. Add a member function that permits an object 
to report its own serial number. Then write a main() program that creates three 
objects and queries each one about its serial number. They should respond I am 
object number 2,and so on.
*/
#include<iostream>
using namespace std;

class objects
{
	private:
		static int count;		//This member is applied to the class as a whole.
		int slNumber;
	public:
		objects()
		{count++;slNumber=count;}
		~objects(){}
		void tcount()const;
		void respond()const;
};

int objects::count=0;		//The static member declared in the class is assigned here.

int main()
{
	objects o1,o2,o3;
	o1.tcount();
	cout<<"What is your Sl. number o2?: ";
	o2.respond();
	cout<<"What is your Sl. number o3?: ";
	o3.respond();
	cout<<"What is your Sl. number o1?: ";
	o1.respond();
	
	return 0;
}

void objects::tcount()const
{
	cout<<"The total no. of objects created: "<<count<<endl;
}

void objects::respond()const
{
	cout<<"I am object number "<<slNumber<<endl;
}