/*
--PROGRAM NAME: rlch9e5.cpp
--PROGRAM STATEMENT: Derive a class called employee2 from the employee 
class in the EMPLOY program in this chapter. This new class should add a type 
double data item called compensation, and also an enum type called period to 
indicate whether the employee is paid hourly, weekly, or monthly. For simplicity 
you can change the manager, scientist, and laborer classes so they are derived 
from employee2 instead of employee. However, note that in many circumstances it 
might be more in the spirit of OOP to create a separate base class called 
compensation and three new classes manager2, scientist2, and laborer2, and use 
multiple inheritance to derive these three classes from the original manager, 
scientist, and laborer classes and from compensation. This way none of the 
original classes needs to be modified.
*/
#include <iostream>
using namespace std;

const int LEN = 80;					 //maximum length of names
enum pay_period {hourly, weekly, monthly};

//0000000000000000000000000000000000000000000000000000000000000000000//
class employee							//employee class
{
	private:
		char name[LEN];				  //employee name
		unsigned long ID;		  //employee ID
	public:
		void getdata()
		{
			cout<<"\n  Enter last name: "; cin>>name;
			cout<<"  Enter ID: ";		cin>>ID;
		}
		void putdata() const
		{
			cout<<"\n  Name           :"<<name;
			cout<<"\n  Number         :"<<ID;
		}
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class compensation
{
	private:
		double compn;
		pay_period pp;
	public:
		void getdata();
		void putdata()const;
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class manager:public employee	 //management class
{
	private:
		char title[LEN];				 //"vice-president","MD" etc.
		double dues;					  //golf club dues
	public:
		void getdata()
			{
				employee::getdata();
				cout<<"  Enter title: ";cin>>title;
				cout<<"  Enter golf club dues: ";cin>>dues;
			}
		void putdata() const
			{
				employee::putdata();
				cout<<"\n  Title          :"<<title;
				cout<<"\n  Golf club dues :"<<dues;
			}
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class scientist:public employee  //scientist class
{
	private:
		int pubs;						  //Number of publications
	public:
		void getdata()
		{
			employee::getdata();
			cout<<"  Enter Number of publications: "; cin>>pubs;
		}
		void putdata()const
		{
			employee::putdata();
			cout<<"\n  No. of publications: "<<pubs;
		}
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class laborer:public employee	 //laborer class
{
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class manager1:public manager,public compensation	 //management class
{
	public:
		void getdata()
		{
			manager::getdata();
			compensation::getdata();
		}
		void putdata() const
		{
			manager::putdata();
			compensation::putdata();
		}
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class scientist1:public scientist,public compensation	 //management class
{
	public:
		void getdata()
		{
			scientist::getdata();
			compensation::getdata();
		}
		void putdata()const
		{
			scientist::putdata();
			compensation::putdata();
		}
};
//0000000000000000000000000000000000000000000000000000000000000000000//
class laborer1:public laborer,public compensation	 //management class
{
	public:
		void getdata()
		{
			laborer::getdata();
			compensation::getdata();
		}
		void putdata() const
		{
			laborer::putdata();
			compensation::putdata();
		}
};

//////////////////////////////START OF MAIN///////////////////////////
int main()
{
	manager1 m1, m2;
	scientist1 s1;
	laborer1 l1;

	cout<<endl;			  //get data for several employees
	cout<<"\nEnter data for manager 1";	 
	m1.getdata();									 

	cout<<"\nEnter data for manager 2";
	m2.getdata();

	cout<<"\nEnter data for scientist 1";
	s1.getdata();

	cout<<"\nEnter data for laborer 1";
	l1.getdata();
									//display data for several employees
	cout<<"\nData on manager 1";			  
	m1.putdata();									 

	cout<<"\nData on manager 2";
	m2.putdata();

	cout<<"\nData on scientist 1";
	s1.putdata();

	cout<<"\nData on laborer 1";
	l1.putdata();
	cout<<endl;
	return 0;
}
////////////////////////////////END OF MAIN//////////////////////

void compensation::getdata()
{
	char c;
	cout<<"  Enter compensation: "; cin>>compn;
	cout<<"  Choose pay period(h-hourly, w-weekly, m-monthly): ";cin>>c;
	switch(c)
	{
		case 'h':
			pp=hourly;break;
		case 'w':
			pp=weekly;break;
		case 'm':
			pp=monthly;break;
		
	}
}
//0000000000000000000000000000000000000000000000000000000000000000000//
void compensation::putdata()const
{
	cout<<"\n  Compensation   :"<<compn;
	cout<<"\n  Pay period     :";
	switch(pp)
	{
		case hourly:
			cout<<"Hourly";break;
		case weekly:
			cout<<"Weekly";break;
		case monthly:
			cout<<"Monthly";break;
		
	}
}