/*
--PROGRAM NAME: rlch8e3.cpp
--PROGRAM STATEMENT: Modify the Time class from Exercise 3 in Chapter 6 so that 
instead of a function add_Time() it uses the overloaded + operator to add two 
Times. Write a program to test this class.
*/
#include<iostream>
using namespace std;

class Time
{
	private:
		int h,m,s;
	public:
		Time():h(0),m(0),s(0){}		//Constructor to initialise data members to 0.
		Time(int hh,int mm,int ss):h(hh),m(mm),s(ss){}	//Constructor to initialise data members to default values.
		~Time(){}		//destructor.
		void display()
		{cout<<h<<':'<<m<<':'<<s;}
		Time operator +(Time)const;
};

int main()
{
	Time t,t1(12,15,30),t2(06,30,45);	 
	
	cout<<"t: ";t.display();
	cout<<"\nt1: ";t1.display();
	cout<<"\nt2: ";t2.display();
	//Adding t1 and t2 using overloaded operator +
	t=t1+t2;
	cout<<"\nt(=t1+t2)= ";t.display();
	cout<<endl;
	
	return 0;
}

Time Time::operator +(Time t2)const
{
	int ss=h*3600+m*60+s;  //Time t1 in seconds.
	ss+=t2.h*3600+t2.m*60+t2.s;  //Time t1=t1 in seconds + t2 in seconds.
	int hh=ss/3600;
	int mm=(ss%3600)/60;
	ss%=60;
	
	return Time(hh,mm,ss);  //Unnamed Time object is returned(Uses constructor 2).
}