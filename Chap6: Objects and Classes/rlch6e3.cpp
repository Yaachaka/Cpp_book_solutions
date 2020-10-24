/*
--PROGRAM NAME: rlch6e3.cpp
--PROGRAM STATEMENT: Create a class called time that has separate int member 
data for hours, minutes, and seconds. One constructor should initialize this 
data to 0, and another should initialize it to fixed values. Another member 
function should display it, in 11:59:59 format. The final member function should 
add two objects of type time passed as arguments. 
A main() program should create two initialized time objects (should they be const?) 
and one that isn’t initialized. Then it should add the two initialized values 
together, leaving the result in the third time variable. Finally it should display 
the value of this third variable. Make appropriate member functions const.
*/
#include<iostream>
using namespace std;

class time
{
	private:
		int h,m,s;
	public:
		time():h(0),m(0),s(0){}		//Constructor to initialise data members to 0.
		time(int hh,int mm,int ss):h(hh),m(mm),s(ss){}	//Constructor to initialise data members to default values.
		~time(){}		//destructor.
		void display()
		{cout<<h<<':'<<m<<':'<<s;}
		void add(const time, const time);
};

int main()
{
	class time t,t1(12,15,30),t2(06,30,45);		//keyword class is a must here. 
																		//Since there already exist a std function called time().
	
	cout<<"t: ";t.display();
	cout<<"\nt1: ";t1.display();
	cout<<"\nt2: ";t2.display();
	
	t.add(t1,t2);
	cout<<"\nt=t1+t2: t=";t.display();
	cout<<endl;
	
	return 0;
}

void time::add(const time t1,const time t2)
{
	s=t1.h*3600+t1.m*60+t1.s;
	s+=t2.h*3600+t2.m*60+t2.s;
	h=s/3600;
	m=(s%3600)/60;
	s%=60;
}