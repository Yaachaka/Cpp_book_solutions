/*
--PROGRAM NAME: rlch4e7.cpp
--PROGRAM STATEMENT: Add a variable of type  enum etype (see Exercise 6), and 
another variable of type struct date (see Exercise 5) to the  employee class of 
Exercise 4. Organize the resulting program so that the user enters four items of 
information for each of three employees: an employee number, the employee’s 
compensation, the employee type, and the date of first employment. The program 
should store this information in three variables of type employee, and then 
display their contents.
*/

#include<iostream>
#include<iomanip>		//setw(), right, left, setfill().
														//'right' and 'left' are manipulators using as alternatives to 
																//setiosflags(ios::right) and setiosflags(ios::left) respectively.
																//And are defined in iomanip library (come under std namespace).
using namespace std;

enum etype {laborer,secretary,manager,accountant,executive,researcher};

struct Date
{
	int day,month,year;
};

struct employee
{
	int id;		//Employee number.
	float cmpn;		//Employee's compensation in $.
	char a;		//To store the first character of employee type.
	Date date1;	//For DOE(Date of Employment).
	etype type1;		//Employee type.
};

int main()
{
	char c;
	employee emp1,emp2,emp3;
	
	//Employee emp1 datail feeding.
	cout<<"Enter employee ID, employee's compensation($) and DOE(date of employment(D/M/Y)) for emp1: ";
	cin>>emp1.id>>emp1.cmpn>>emp1.date1.day>>c>>emp1.date1.month>>c>>emp1.date1.year;
	cout<<"Enter employee type (1st letter only)(laborer,secretary,manager,accountant,executive,researcher): ";
	cin>>emp1.a;

	//Employee emp2 detail feeding.
	cout<<"Enter employee ID, employee's compensation($) and DOE(date of employment(D/M/Y)) for emp2: ";
	cin>>emp2.id>>emp2.cmpn>>emp2.date1.day>>c>>emp2.date1.month>>c>>emp2.date1.year;
	cout<<"Enter employee type (1st letter only)(laborer,secretary,manager,accountant,executive,researcher): ";
	cin>>emp2.a;

	//Employee emp3 detail feeding.
	cout<<"Enter employee ID, employee's compensation($) and DOE(date of employment(D/M/Y)) for emp3: ";
	cin>>emp3.id>>emp3.cmpn>>emp3.date1.day>>c>>emp3.date1.month>>c>>emp3.date1.year;
	cout<<"Enter employee type (1st letter only)(laborer,secretary,manager,accountant,executive,researcher): ";
	cin>>emp3.a;
	
	//Table head
	cout<<left<<setw(10)<<"Emp. ID"<<setw(18)<<"Compensation($)"<<setw(13)<<"Emp. type"<<setw(13)<<"DOE"<<endl;
	//Line under table head.
	cout<<setw(54)<<setfill('-')<<""<<setfill(' ')<<""<<endl;

	//Printing emp1 details.
	cout<<right<<setw(7)<<emp1.id<<setw(18)<<emp1.cmpn<<setw(3)<<""<<left<<setw(10);
	switch(emp1.a)
	{
		case 'l': emp1.type1=laborer; cout<<"laborer"; break;
		case 's': emp1.type1=secretary; cout<<"secretary"; break;
		case 'm': emp1.type1=manager; cout<<"manager"; break;
		case 'a': emp1.type1=accountant; cout<<"accountant"; break;
		case 'e': emp1.type1=executive; cout<<"executive"; break;
		case 'r': emp1.type1=researcher; cout<<"researcher"; break;
		default: cout<<"----------";
	}
	cout<<setw(3)<<""<<right<<setw(2)<<emp1.date1.day<<'/'<<emp1.date1.month<<'/'<<emp1.date1.year<<setw(3)<<""<<endl;

	//Printing emp2 details.
	cout<<right<<setw(7)<<emp2.id<<setw(18)<<emp2.cmpn<<setw(3)<<""<<left<<setw(10);
	switch(emp2.a)
	{
		case 'l': emp2.type1=laborer; cout<<"laborer"; break;
		case 's': emp2.type1=secretary; cout<<"secretary"; break;
		case 'm': emp2.type1=manager; cout<<"manager"; break;
		case 'a': emp2.type1=accountant; cout<<"accountant"; break;
		case 'e': emp2.type1=executive; cout<<"executive"; break;
		case 'r': emp2.type1=researcher; cout<<"researcher"; break;
		default: cout<<"----------";
	}
	cout<<setw(3)<<""<<right<<setw(2)<<emp2.date1.day<<'/'<<emp2.date1.month<<'/'<<emp2.date1.year<<setw(3)<<""<<endl;

	//Printing emp3 details.
	cout<<right<<setw(7)<<emp3.id<<setw(18)<<emp3.cmpn<<setw(3)<<""<<left<<setw(10);
	switch(emp3.a)
	{
		case 'l': emp3.type1=laborer; cout<<"laborer"; break;
		case 's': emp3.type1=secretary; cout<<"secretary"; break;
		case 'm': emp3.type1=manager; cout<<"manager"; break;
		case 'a': emp3.type1=accountant; cout<<"accountant"; break;
		case 'e': emp3.type1=executive; cout<<"executive"; break;
		case 'r': emp3.type1=researcher; cout<<"researcher"; break;
		default: cout<<"----------";
	}
	cout<<setw(3)<<""<<right<<setw(2)<<emp3.date1.day<<'/'<<emp3.date1.month<<'/'<<emp3.date1.year<<setw(3)<<""<<endl;

	return 0;
}

/*
NOTE:
-- setiosflags(ios::right) and setiosflags(ios::left) did not work as expected.
They were not carrying the mentioned manipulator status to the next cout statement.
And the ...ios::right.. did not respond right.
*/