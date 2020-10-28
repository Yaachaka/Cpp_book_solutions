/*
--PROGRAM NAME: rlch7e2.cpp
--PROGRAM STATEMENT: Create a class called employee that contains a name (an 
object of class string) and an employee number (type long). Include a member 
function called getdata() to get data from the user for insertion into the object, 
and another function called putdata() to display the data. Assume the name has no 
embedded blanks. 
Write a main() program to exercise this class. It should create an array of type 
employee, and then invite the user to input data for up to 100 employees. Finally, 
it should print out the data for all the employees.
*/
#include<iostream>
#include<string>
#include<iomanip>		//setw(), setfill(), right, left
using namespace std;

class employee
{
	private:
		string name;		//To store Employee name.
		int id;		//To store Employee number/ID
	public:
		void getdata();
		void putdata()const;
};

int main()
{
	void tabhead();
	const int MAX=100;
	employee e[MAX];
	char q;
	int count=0;
	
	//Getting user input
	cout<<"Enter employee's details: \n";
	do
	{
		e[count++].getdata();
		cout<<"Enter another employee's details(y/n)?: ";
		cin>>q;
	}while((q=='y'||q=='Y')&&count<MAX);
	
	if(count==MAX)
		cout<<"Storage full. Displaying entered data.\n";
	
	//Displaying table containing employees details.
	tabhead();
	for(int i=0;i<count;i++)
	{
		e[i].putdata();
		cout<<endl;
	}
	cout<<right;
	
	return 0;
}

void employee::getdata()
{
	cout<<"Enter employee ID: ";
	cin>>id;
	cout<<"\tEnter employee name: ";
	cin>>name;		//Input method that doesn't allow embedded blanks.
}

void employee::putdata()const
{
	cout<<setw(7)<<right<<id<<setw(3)<<""<<setw(15)<<left<<name;
}

void tabhead()
{
	cout<<endl<<left<<setw(10)<<"Emp. ID"<<setw(18)<<"Emp. name"<<endl;
	cout<<setw(28)<<setfill('*')<<""<<setfill(' ')<<""<<endl;
}