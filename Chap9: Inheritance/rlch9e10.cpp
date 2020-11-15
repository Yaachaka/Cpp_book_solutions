/*
--PROGRAM NAME: rlch9e10.cpp
--PROGRAM STATEMENT: There is only one kind of manager in the EMPMULT 
program in this chapter. Any serious company has executives as well as managers. 
From the manager class derive a class called executive. (We’ll assume an 
executive is a high-end kind of manager). The additional data in the executive 
class will be the size of the employee’s yearly bonus and the number of shares 
of company stock held in his or her stock-option plan. Add the appropriate 
member functions so these data items can be input and displayed along with the 
other manager data.
*/	
#include <iostream>
using namespace std;
const int LEN = 80;			  //maximum length of names
////////////////////////////////////////////////////////////////
class student					  //educational background
{
	private:
		char school[LEN];		 //name of school or university
		char degree[LEN];		 //highest degree earned
	public:
		void getedu()
		{
			cout << "	Enter name of school or university: ";
			cin >> school;
			cout << "	Enter highest degree earned \n";
			cout << "	(Highschool, Bachelor's, Master's, PhD): ";
			cin >> degree;
		}
		void putedu() const
		{
			cout << "\n	School or university    : " << school;
			cout << "\n	Highest degree earned   : " << degree;
		}
};
////////////////////////////////////////////////////////////////
class employee
{
	private:
		char name[LEN];			//employee name
		unsigned long number;	//employee number
	public:
		void getdata()
		{
			cout << "\n	Enter last name: "; cin >> name;
			cout << "	Enter number: ";		cin >> number;
		}
		void putdata() const
		{
			cout << "\n	Name                    : " << name;
			cout << "\n	Number                  : " << number;
		}
};
////////////////////////////////////////////////////////////////
class manager:private employee, private student  //management
{
	private:
		char title[LEN];		  //"vice-president" etc.
		double dues;				//golf club dues
	public:
		void getdata()
		{
			employee::getdata();
			cout << "	Enter title: ";			 cin >> title;
			cout << "	Enter golf club dues: "; cin >> dues;
			student::getedu();
		}
		void putdata() const
		{
			employee::putdata();
			cout << "\n	Title                   : " << title;
			cout << "\n	Golf club dues          : " << dues;
			student::putedu();
		}
};
////////////////////////////////////////////////////////////////
class executive:public manager
{
	private:
		float yearly_bonus;
		int no_of_shares;
	public:
		executive():manager(){}
		~executive(){}
		
		void getdata()
		{
			manager::getdata();
			cout<<"	Enter size of the employee’s yearly bonus: ";
			cin>>yearly_bonus;
			cout<<"	Enter the number of shares of company stock held in his or her \
stock-option plan: ";
			cin>>no_of_shares;
		}
		void putdata()const
		{
			manager::putdata();
			cout<<"\n	Yearly bonus            : "<<yearly_bonus
			    <<"\n	No. of shares           : "<<no_of_shares;
		}
};
////////////////////////////////////////////////////////////////
class scientist : private employee, private student  //scientist
{
	private:
		int pubs;	  //number of publications
	public:
		void getdata()
		{
			employee::getdata();
			cout << "	Enter number of pubs: "; cin >> pubs;
			student::getedu();
		}
		void putdata() const
		{
			employee::putdata();
			cout << "\n	Number of publications  : " << pubs;
			student::putedu();
		}
};
////////////////////////////////////////////////////////////////
class laborer : public employee				 //laborer
{
};
////////////////////////////START OF MAIN()/////////////////////////////////
int main()
{
	executive m1;
	scientist s1, s2;
	laborer l1;

	cout << endl;
	cout << "\nEnter data for manager 1";	 //get data for
	m1.getdata();									 //several employees

	cout << "\nEnter data for scientist 1";
	s1.getdata();

	cout << "\nEnter data for scientist 2";
	s2.getdata();

	cout << "\nEnter data for laborer 1";
	l1.getdata();

	cout << "\nData on manager 1";			  //display data for
	m1.putdata();									 //several employees

	cout << "\nData on scientist 1";
	s1.putdata();

	cout << "\nData on scientist 2";
	s2.putdata();

	cout << "\nData on laborer 1";
	l1.putdata();
	cout << endl;
	return 0;
}
////////////////////////////END OF MAIN()/////////////////////////////////
