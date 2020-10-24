/*
--PROGRAM NAME: rlch6e4.cpp
--PROGRAM STATEMENT: Create an employee class, basing it on Exercise 4 of Chapter 
4. The member data should comprise an int for storing the employee number and a 
float for storing the employee’s compensation. Member functions should allow the 
user to enter this data and display it. Write a main() that allows the user to 
enter data for three employees and display it.
*/
#include<iostream>
#include<iomanip>		//right, left, setw(), setfill().
using namespace std;

class employee
{
	private:
		int id;		//Employee number.
		float cmpn;		//Employee's compensation.
	public:
		void enter();
		void display()const;
};

void tableHead();

int main()
{
	employee e1,e2,e3;

	//Taking user inputs.
	cout<<"Enter details of the employee 1: \n";
	e1.enter();
	cout<<"Enter details of the employee 2: \n";
	e2.enter();
	cout<<"Enter details of the employee 3: \n";
	e3.enter();
	
	tableHead();	//Function to place table head.
	//Displaying all the emplyees' details.
	e1.display();
	e2.display();
	e3.display();
	
	return 0;
}

void employee::enter()
{
	cout<<"Enter employee ID: ";
	cin>>id;
	cout<<"Enter employee compensation($): ";
	cin>>cmpn;
}

void employee::display()const
{
	cout<<setw(7)<<id<<setw(18)<<cmpn<<endl;
}

void tableHead()
{
	cout<<endl<<setw(10)<<left<<"Emp. ID";
	cout<<setw(18)<<"Compensation($)"<<endl;
	cout<<setw(28)<<setfill('-')<<""<<setfill(' ')<<right<<endl;
}