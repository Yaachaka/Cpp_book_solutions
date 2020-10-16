/*
--PROGRAM NAME: rlch4e4.cpp
--PROGRAM STATEMENT: Create a structure called employee that contains two members: 
an employee number (type int) and the employee’s compensation (in dollars; type 
float). Ask the user to fill in this data for three employees, store it in three 
variables of type struct employee, and then display the information for each 
employee.
*/

#include<iostream>
#include<iomanip>		//setw(), setiosflags(), setfill().
using namespace std;

struct employee
{
	int emp_num;	//Employee number.
	float emp_compn;		//Employee's compensation in $.
};

int main()
{
	employee emp1,emp2,emp3;
	
	//Taking details of employee 1.
	cout<<"Enter employee no. and employee's compensation($) for emp1: ";
	cin>>emp1.emp_num>>emp1.emp_compn;
	
	//Taking details of employee 2.
	cout<<"Enter employee no. and employee's compensation($) for emp2: ";
	cin>>emp2.emp_num>>emp2.emp_compn;
	
	//Taking details of employee 3.
	cout<<"Enter employee no. and employee's compensation($) for emp3: ";
	cin>>emp3.emp_num>>emp3.emp_compn;
	
	//Generating table head.
	cout<<setiosflags(ios::left)<<setw(10)<<"Emp. ID"<<setw(16)<<"Compensation($)"<<endl;
	//Generating line under the table head.
	cout<<setw(26)<<setfill('-')<<""<<setfill(' ')<<""<<setiosflags(ios::right)<<endl;
	//Displaying employees' details in the table.
	cout<<setw(7)<<emp1.emp_num<<setw(18)<<emp1.emp_compn<<endl;
	cout<<setw(7)<<emp2.emp_num<<setw(18)<<emp2.emp_compn<<endl;
	cout<<setw(7)<<emp3.emp_num<<setw(18)<<emp3.emp_compn<<endl;
	
	return 0;
}