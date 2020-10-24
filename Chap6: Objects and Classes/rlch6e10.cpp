/*
--PROGRAM NAME: rlch6e10.cpp
--PROGRAM STATEMENT: Create a class called  ship that incorporates a ship’s 
number and location. Use the approach of Exercise 8 to number each ship object 
as it is created. Use two variables of the angle class from Exercise 7 to 
represent the ship’s latitude and longitude. A member function of the ship class 
should get a position from the user and store it in the object; another should 
report the serial number and position. Write a main() program that creates 
three ships, asks the user to input the position of each, and then displays each 
ship’s number and position.
*/
#include<iostream>
#include<iomanip>
using namespace std;

class angle		//angle class holds a co-ordinate, can be latitude or longitude. 
{
	private:
		int degrees;
		float minutes;
		char c;
	public:
		void getangle();
		void putangle()const;
};

class position		//position class holds longitude and latitude.
{
	private:
		angle longi,latti;
	public:
		void getdata();
		void givdata()const;
};

class ship		//ship class holds ship and and ship position.
{
	private:
		static int count;		//To keep count of the number of ships.
		int id;
		position pos;
	public:
		ship(){count++,id=count;}
		~ship(){}
		void getpos(){pos.getdata();}
		void reppos()const;
};
int ship::count=0;

void tabHead();

int main()
{
	ship s1,s2,s3;
	
	cout<<"Enter position of the ship 1: \n";
	s1.getpos();
	
	cout<<"Enter position of the ship 2: \n";
	s2.getpos();
	
	cout<<"Enter position of the ship 3: \n";
	s3.getpos();
	
	tabHead();
	//Displaying 3 ships' details.
	s1.reppos();
	s2.reppos();
	s3.reppos();
	
	return 0;
}

void angle::getangle()
{
	cout<<"Enter degrees: ";cin>>degrees;
	cout<<"Enter minutes(0.00' to 59.59'): ";cin>>minutes;
	cout<<"Enter direction: ";cin>>c;
	c=toupper(c);
}

void angle::putangle()const
{
	cout<<degrees<<"°"<<minutes<<'\''<<" "<<c;
}

void position::getdata()
{
	cout<<"Enter LONGITUDE(0°0' to 180°0' E or W direction): \n";
	longi.getangle();
	cout<<"Enter LATTITUDE(0°0' to 90°0' N or S direction): \n";
	latti.getangle();
}

void position::givdata()const
{
	longi.putangle();
	cout<<" ";
	latti.putangle();
}

void ship::reppos()const
{
	cout<<right<<setw(7)<<id<<setw(3)<<""<<left;
	pos.givdata();
	cout<<endl;
}

void tabHead()
{
	cout<<endl<<left<<setw(10)<<"Ship ID"<<setw(31)<<"Location"<<endl;
	cout<<setw(41)<<setfill('-')<<""<<setfill(' ')<<right<<endl;
}