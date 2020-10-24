/*
--PROGRAM NAME: rlch6e6.cpp
--PROGRAM STATEMENT: Extend the employee class of Exercise 4 to include a date 
class (see Exercise 5) and an etype enum (see Exercise 6 in Chapter 4). An object 
of the date class should be used to hold the date of first employment; that is, 
the date when the employee was hired. The etype variable should hold the 
employee’s type: laborer, secretary, manager, and so on. These two items will be 
private member data in the employee definition, just like the employee number and 
salary. You’ll need to extend the  getemploy() and putemploy() functions to 
obtain this new information from the user and display it. These functions will 
probably need switch statements to handle the etype variable. 
Write a main() program that allows the user to enter data for three employee 
variables and then displays this data.
*/
#include<iostream>
#include<iomanip>		//setw(), setfill(), right, left.
using namespace std;

enum etype {laborer,secretary,manager,accountant,executive,researcher};

class date
{
	private:
		int d,m,y;
	public:
		void getdate()
		{char c; cin>>d>>c>>m>>c>>y;}
		void showdate()const
		{cout<<d<<'/'<<m<<'/'<<y;}
};

class employee
{
	private:
		int id;		//Employee ID
		float cmpn;		//Employee compensation/salary
		etype emt;		//Employee type
		date d;		//Date of Employment.
		char c;		//Holds the first character of employment type.
	public:
		void getemploy();
		void putemploy()const;
};

void tabHead();

int main()
{
	employee e1,e2,e3;
	
	//Getting 3 employees' details.
	cout<<"Enter deatils of employee 1:\n";
	e1.getemploy();
	cout<<"Enter deatils of employee 2:\n";
	e2.getemploy();
	cout<<"Enter deatils of employee 3:\n";
	e3.getemploy();
	
	//Table head is generated.
	tabHead();
	//Employee details are displayed in the tabel.
	e1.putemploy();
	e2.putemploy();
	e3.putemploy();
	
	return 0;
}

void employee::getemploy()
{
	cout<<"Enter employee ID: ";
	cin>>id;
	cout<<"Enter employee compensation($): ";
	cin>>cmpn;
	cout<<"Enter employee DOE(Date of employment(D/M/Y)): ";
	d.getdate();
	cout<<"Enter the first character of the employment type(default: laborer)\
	\n(l=laborer, s=secretary, m=manager, a=accountant, e=executive, r=researcher): ";
	cin>>c;
	switch(c)
	{
		case 'r':emt=researcher;break;
		case 's':emt=secretary;break;
		case 'm':emt=manager;break;
		case 'a':emt=accountant;break;
		case 'e':emt=executive;break;
		default:emt=laborer;
	}
}

void employee::putemploy()const
{
	cout<<right<<setw(7)<<id<<setw(18)<<cmpn<<setw(3)<<""<<setw(10)<<left;
	switch(c)
	{
		case 'r':cout<<"Researcher";break;
		case 's':cout<<"Secretary";break;
		case 'm':cout<<"Manager";break;
		case 'a':cout<<"Accountant";break;
		case 'e':cout<<"Executive";break;
		default:cout<<"Laborer";
	}
	cout<<setw(3)<<"";
	d.showdate();
	cout<<endl;
}

void tabHead()
{
	cout<<endl<<setw(10)<<left<<"Emp. ID";
	cout<<setw(18)<<"Compensation($)"<<setw(13)<<"Emp. type"<<setw(13)<<"DOE"<<endl;
	cout<<setw(54)<<setfill('-')<<""<<setfill(' ')<<right<<endl;
}